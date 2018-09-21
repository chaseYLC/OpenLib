#pragma once


#ifdef _WIN32
   //define something for Windows (32-bit and 64-bit, this part is common)
   #ifdef _WIN64
      //define something for Windows (64-bit only)
	  #ifdef _DEBUG
			#pragma comment(lib, "OpenLib/DocumentDBCpp/v140/x64/Debug/DocumentDBCpp.lib")
		#else
			#pragma comment(lib, "OpenLib/DocumentDBCpp/v140/x64/Release/DocumentDBCpp.lib")
		#endif
	#else
		// define for Windows 32-bit
		#ifdef _DEBUG
			#pragma comment(lib, "OpenLib/DocumentDBCpp/v140/Win32/Debug/DocumentDBCpp.lib")
		#else
			#pragma comment(lib, "OpenLib/DocumentDBCpp/v140/Win32/Release/DocumentDBCpp.lib")
		#endif
   #endif
#elif __linux__
    // linux
#elif defined(_POSIX_VERSION)
    // POSIX
#else
#   error "Unknown compiler"
#endif




