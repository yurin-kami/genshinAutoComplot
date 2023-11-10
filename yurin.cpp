#include <iostream>
#include <Windows.h>
#include<thread>
using namespace std;

void yurin() {
    while (true)
    {
        int x = 1979;
        int y = 1238;
        INPUT ipt = { 0 };
        ipt.mi.dx = x * (65536 / GetSystemMetrics(SM_CXSCREEN));
        ipt.mi.dy = y * (65536 / GetSystemMetrics(SM_CYSCREEN));
        ipt.mi.mouseData = 0;
        ipt.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP;
        ipt.mi.time = 0;
        SendInput(1, &ipt, sizeof(INPUT));
        Sleep(100);
        if (GetAsyncKeyState(VK_F6) & 0x8000) { // 检测回车键是否按下
            break;
        }
    }
}

    int main(){
    	//std::cout << "请输入坐标x，y" << std::endl;
    	//std::cin >> x >> y;
        thread systemcommand([]() {
            system("YuanShen.exe");
            });
        cout << "原神，启动！！！" << endl;
        cout << "f7启动autoComplot，f6返回" << endl;
        while (true)
        {
            if (GetAsyncKeyState(VK_F7) & 0x8000) { // 检测回车键是否按下
                yurin();
            }
            if (GetAsyncKeyState(VK_F6) & 0x8000) { // 检测回车键是否按下
                continue;
            }
        }
        systemcommand.join();
    	return 0;
    }
