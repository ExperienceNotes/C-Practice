// CallDLL.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stdio.h>
#include <Windows.h>
using namespace std;
typedef int (*add_number)(int, int);
typedef int (*sub_number)(int, int);
typedef bool(__stdcall* Init)();
int main()
{
    add_number add;
    HINSTANCE hinstLib = LoadLibrary(TEXT("classCallDLL.dll"));
    if (hinstLib == NULL) {
        cout << "ERROR:unable to load DLL" <<endl;
        system("pause");
        return 0;
    }
    Init Init_1 = (Init)GetProcAddress(hinstLib,"Init");
    Init Proce_1 = (Init)GetProcAddress(hinstLib, "Proce");
    if (Init_1 == NULL) {
        cout << "ERROR: unable to find DLL function" << endl;
        FreeLibrary(hinstLib);
        system("pause");
        return 0;
    }
    Init_1();
    Proce_1();
    //int ans = add(2, 1);
    //cout << "ans = " << ans << endl;
    FreeLibrary(hinstLib);
    system("pause");
    cout << "Hello World!\n";
    return 0;
}