// MFConsole.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "MFConsole.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 유일한 응용 프로그램 개체입니다.

CWinApp theApp;

using namespace std;

// User Defined Class
class Hello
{
public:
	Hello()
	:mx(0)
	{}
	Hello(int x)
		:mx(x)
	{}
	int mx;
};

void print(CArray<Hello,Hello&>& a)
{
	for (int i = 0; i < a.GetSize(); ++i)
	{
		cout << a[i].mx << " ";
	}
	cout << endl;
}

int main()
{
    int nRetCode = 0;

    HMODULE hModule = GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // MFC를 초기화합니다. 초기화하지 못한 경우 오류를 인쇄합니다.
        if (!AfxWinInit(hModule, nullptr, GetCommandLine(), 0))
        {
            // TODO: 오류 코드를 필요에 따라 수정합니다.
            wprintf(L"심각한 오류: MFC를 초기화하지 못했습니다.\n");
            nRetCode = 1;
        }
        else
        {
			// TODO: 응용 프로그램의 동작은 여기에서 코딩합니다.

			//CString
			CString strHello;
			strHello.LoadString(IDS_HELLO);
			cout << strHello << endl;
			cout << (LPCTSTR)strHello << endl;
			CString str;
			str.Format("x = %d, y = %d", 100, 200);
			//MessageBox(NULL, str, "CString::Format 연습", MB_OK);

			// CPoint, CRect, CSize
			CPoint p{ 5,15 };
			cout << p.x << "," << p.y << endl;

			CRect r{ 0,0,10,20 };
			cout << r.Width() << " " << r.Height() << endl;
			cout << r.PtInRect(p) << endl;

			CSize s{ 10,20 };
			cout << (s == r.Size()) << endl;
			s.SetSize(5, 10);
			cout << (s == r.Size()) << endl;

			// CTime, CTimeSpan
			CTime t;
			t = CTime::GetCurrentTime();
			cout << t.GetYear() << "/" << t.GetMonth() << "/" << t.GetDay() << endl;
			cout << t.GetHour() << ":" << t.GetMinute() << ":" << t.GetSecond() << endl;

			CTime startTime = CTime::GetCurrentTime();
			//Sleep(2000);
			CTime endTime = CTime::GetCurrentTime();
			CTimeSpan elapsedTime = endTime - startTime;
			CString str3;
			str3.Format("%d초가 지났습니다.", elapsedTime.GetSeconds());
			cout << (LPCTSTR)str3 << endl;
			 
			// Array Class
			// Template Array Class
			// iterator는 없다
			CArray<Hello, Hello&> helloArray;
			helloArray.Add(Hello{ 5 });

			cout << helloArray[0].mx << endl;

			//CStringArray sa;
			cout << helloArray.GetSize() << endl;
			helloArray.InsertAt(4,Hello{ 1 });
			helloArray.Add(Hello(3));
			print(helloArray);
			helloArray.RemoveAt(0);
			print(helloArray);
			cout << helloArray.GetSize();

			// List Class
			CList<Hello, Hello&> hList;

        }
    }
    else
    {
        // TODO: 오류 코드를 필요에 따라 수정합니다.
        wprintf(L"심각한 오류: GetModuleHandle 실패\n");
        nRetCode = 1;
    }

    return nRetCode;
}