#pragma once

template<typename T>
void Swap(T* ptr1, T* ptr2)
{
	T ptr_L = move(*ptr1);
	*ptr1 = move(*ptr2);
	*ptr2 = move(ptr_L);
}
