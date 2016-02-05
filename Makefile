
BIN_DIR=./build/bin
LIB_DIR=./build/lib
SRC_DIR=./src

$(BIN_DIR)/LustriousPaint.exe: $(SRC_DIR)/main.rs $(LIB_DIR)/libctypes.rlib $(LIB_DIR)/libwin32.rlib | $(BIN_DIR)
	rustc $< -L $(LIB_DIR) -C link_args="-Wl,--subsystem,windows" -L ./ -o $@

$(LIB_DIR)/libctypes.rlib: $(SRC_DIR)/ctypes.rs | $(LIB_DIR)
	rustc $< -L $(LIB_DIR) --out-dir=$(LIB_DIR)

$(LIB_DIR)/libwin32.rlib: $(SRC_DIR)/win32/lib.rs | $(LIB_DIR)
	rustc $(SRC_DIR)/win32/lib.rs -L $(LIB_DIR) --out-dir=$(LIB_DIR)

$(LIB_DIR):
	mkdir -p ./build/lib

$(BIN_DIR):
	mkdir -p ./build/bin

clean:
	rm -rf ./build
