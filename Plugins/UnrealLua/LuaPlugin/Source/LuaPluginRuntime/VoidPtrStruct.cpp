#include "VoidPtrStruct.h"

int32 VoidPtrStruct::Index_Raw(lua_State*inL)
{
#if LuaDebug
	if (ue_lua_gettop(inL) < 1)
	{
		ensureAlwaysMsgf(0, TEXT(""));
		return 0;
	}
#endif
	uint8* Ptr = (uint8*)ue_lua_touserdata(inL, 1);
	int32 Offset = ue_lua_tointeger(inL, 2);
	Ptr += Offset;
	VoidPtrStruct TempVoidPtrStruct(Ptr);
	UTableUtil::push_ret(inL, TempVoidPtrStruct);
	return 1;
}

int32 VoidPtrStruct::__index(lua_State*inL)
{
	if (ue_lua_isinteger(inL, 2))
	{
		VoidPtrStruct* Ptr = (VoidPtrStruct*) tovoidtype<VoidPtrStruct>(inL, 1);
		int32 Index = popiml<int>::pop(inL, 2) - 1; 
		uint8* RawPtr = (uint8*)(Ptr->ThePtr) + Index;
		VoidPtrStruct TempVoidPtrStruct(RawPtr);
		UTableUtil::push_ret(inL, TempVoidPtrStruct);
		return 1;
	}
	else
	{
		lua_rawget(inL, lua_upvalueindex(1)); 
		return 1;
	}
}
