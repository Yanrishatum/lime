#include <hx/CFFI.h>
#include <app/MobileEvent.h>


namespace lime {
	
	
	AutoGCRoot* MobileEvent::callback = 0;
	AutoGCRoot* MobileEvent::eventObject = 0;
	
	static int id_type;
	static bool init = false;
	
	
	MobileEvent::MobileEvent () {
		
		type = TERMINATING;
		
	}
	
	
	void MobileEvent::Dispatch (MobileEvent* event) {
		
		if (MobileEvent::callback) {
			
			if (!init) {
				
				id_type = val_id ("type");
				init = true;
				
			}
			
			value object = (MobileEvent::eventObject ? MobileEvent::eventObject->get () : alloc_empty_object ());
			
			alloc_field (object, id_type, alloc_int (event->type));
			
			val_call0 (MobileEvent::callback->get ());
			
		}
		
	}
	
	
}