
use types::*;
use ctypes::*;

pub const IDI_APPLICATION: LPCWSTR = 32512 as LPCWSTR;

pub const IDC_ARROW: LPCWSTR = 32512 as LPCWSTR;

pub const CS_VREDRAW: DWORD = 0x0001;
pub const CS_HREDRAW: DWORD = 0x0002;

pub const WS_OVERLAPPED: DWORD = 0x00000000;
pub const WS_POPUP: DWORD = 0x80000000;
pub const WS_CLIPCHILDREN: DWORD = 0x02000000;
pub const WS_CLIPSIBLINGS: DWORD = 0x04000000;
pub const WS_SYSMENU: DWORD = 0x00080000;
pub const WS_THICKFRAME: DWORD = 0x00040000;
pub const WS_GROUP: DWORD = 0x00020000;
pub const WS_BORDER: DWORD = 0x00800000;
pub const WS_MINIMIZEBOX: DWORD = 0x00020000;
pub const WS_MAXIMIZEBOX: DWORD = 0x00010000;

pub const BLACK_BRUSH: c_int = 4;

