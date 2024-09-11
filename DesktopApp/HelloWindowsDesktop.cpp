#include <windows.h>
#include <tchar.h>

LPWSTR chat2LPWSTR(const char* mbstr);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    /*// Using L prefix
    wchar_t msg[] = L"Hello world!";
    wchar_t title[] = L"Message";
    */
    wchar_t* msg = chat2LPWSTR("Hello world!");
    wchar_t* title = chat2LPWSTR("Message");

    MessageBox(NULL, msg, title, MB_OK);

    delete msg;
    delete title;

    MessageBox(NULL, msg, title, MB_OK);

    return 0;
}

LPWSTR chat2LPWSTR(const char* str)
{
    size_t len = strlen(str);
    wchar_t* dest = new wchar_t[len + 1];

    size_t out_size;
    mbstowcs_s(&out_size, dest, len + 1, str, len);

    return dest;
}
