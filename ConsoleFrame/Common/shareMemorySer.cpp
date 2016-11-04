#include "shareMemorySer.h"


shareMemorySer::shareMemorySer(int num)
{

}


shareMemorySer::~shareMemorySer()
{
}

/*
函数功能：创建一块共享内存
返回值：bool
*/
bool shareMemorySer::createShareMemory()
{
	//创建一块大小为SM_ALL_SHARE_DATA的共享内存
	HANDLE hMapFile = ::CreateFileMapping((HANDLE)-1, NULL, PAGE_READWRITE, 0, sizeof(_SM_ALL_SHARE_DATA), FILE_MAP_NAME);
	if (!hMapFile)
	{
		return false;
	}
	//将这个指针指向创建的共享内存
	m_pSMAllData = (_SM_ALL_SHARE_DATA *)MapViewOfFile(hMapFile, FILE_MAP_WRITE | FILE_MAP_READ, 0, 0, 0);
	if (!m_pSMAllData)
	{
		return false;
	}
	return true;
}
/*
函数功能：释放共享内存
返回值：无
*/
void shareMemorySer::destoryShareMemory()
{
	if (m_pSMAllData)
	{
		UnmapViewOfFile(m_pSMAllData);
		m_pSMAllData = nullptr;
	}
}
