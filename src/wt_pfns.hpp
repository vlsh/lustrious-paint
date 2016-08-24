#pragma once

#define NOWTBASICFXNS
#define NOWTCTXEDITFXNS
#define NOWTVISIBILITYFXNS
#define NOWTQUEUEFXNS
#include "wintab/WINTAB.H"

typedef UINT ( API * PFN_WTInfoA ) ( UINT, UINT, LPVOID );
typedef HCTX ( API * PFN_WTOpenA )( HWND, LPLOGCONTEXTA, BOOL );
typedef BOOL ( API * PFN_WTGetA ) ( HCTX, LPLOGCONTEXT );
typedef BOOL ( API * PFN_WTSetA ) ( HCTX, LPLOGCONTEXT );
typedef BOOL ( API * PFN_WTClose ) ( HCTX );
typedef BOOL ( API * PFN_WTEnable ) ( HCTX, BOOL );
typedef BOOL ( API * PFN_WTPacket ) ( HCTX, UINT, LPVOID );
typedef BOOL ( API * PFN_WTOverlap ) ( HCTX, BOOL );
typedef BOOL ( API * PFN_WTSave ) ( HCTX, LPVOID );
typedef BOOL ( API * PFN_WTConfig ) ( HCTX, HWND );
typedef HCTX ( API * PFN_WTRestore ) ( HWND, LPVOID, BOOL );
typedef BOOL ( API * PFN_WTExtSet ) ( HCTX, UINT, LPVOID );
typedef BOOL ( API * PFN_WTExtGet ) ( HCTX, UINT, LPVOID );
typedef BOOL ( API * PFN_WTQueueSizeSet ) ( HCTX, int );
typedef int  ( API * PFN_WTDataPeek ) ( HCTX, UINT, UINT, int, LPVOID, LPINT);
typedef int  ( API * PFN_WTPacketsGet ) (HCTX, int, LPVOID);
