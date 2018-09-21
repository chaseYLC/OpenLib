#pragma once


#ifdef _WIN32
   //define something for Windows (32-bit and 64-bit, this part is common)
   #ifdef _WIN64
      //define something for Windows (64-bit only)
	  #ifdef _DEBUG
			#pragma comment(lib, "OpenLib/acl/dist/lib/win64/lib_acl_cpp_vc2015d.lib")
			#pragma comment(lib, "OpenLib/acl/dist/lib/win64/lib_acl_vc2015d.lib")
		#else
			#pragma comment(lib, "OpenLib/acl/dist/lib/win64/lib_acl_cpp_vc2015.lib")
			#pragma comment(lib, "OpenLib/acl/dist/lib/win64/lib_acl_vc2015.lib")
		#endif
	#else
		// define for Windows 32-bit
		#ifdef _DEBUG
			//#pragma comment(lib, "OpenLib/jsoncpp/lib/lib_jsonD.lib")
		#else
			//#pragma comment(lib, "OpenLib/jsoncpp/lib/lib_json.lib")
		#endif
   #endif
#elif __linux__
    // linux
#elif defined(_POSIX_VERSION)
    // POSIX
#else
#   error "Unknown compiler"
#endif





