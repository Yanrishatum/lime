#ifndef LIME_APP_MOBILE_EVENT_H
#define LIME_APP_MOBILE_EVENT_H


#include <hx/CFFI.h>


namespace lime {
	
	
	enum MobileEventType {
		
		LOW_MEMORY,
		TERMINATING,
    WILL_ENTER_BACKGROUND,
		DID_ENTER_BACKGROUND,
    WILL_ENTER_FOREGROUND,
    DID_ENTER_FOREGROUND
    
	};
	
	
	class MobileEvent {
		
		public:
			
			static AutoGCRoot* callback;
			static AutoGCRoot* eventObject;
			
			MobileEvent ();
			
			static void Dispatch (MobileEvent* event);
			
			MobileEventType type;
		
	};
	
	
}


#endif