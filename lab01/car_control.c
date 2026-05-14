#include <stdio.h>
#include <stdlib.h>

// 函数声明：显示控制菜单
void showMenu()
{
    printf("\n======= 智能小车基础控制程序 =======\n");
    printf("请输入控制指令（1-前进 2-后退 3-左转 4-右转 0-退出）：");
}
// 函数声明：根据指令执行对应动作
void executeAction(int cmd)
{
    switch (cmd)
    {
    case 1:
        printf("小车执行动作：前进\n");
        break;
    case 2:
        printf("小车执行动作：后退\n");
        break;
    case 3:
        printf("小车执行动作：左转\n");
        break;
    case 4:
        printf("小车执行动作：右转\n");
        break;
    case 0:
        printf("程序退出，感谢使用！\n");
        break;
    default:
        printf("错误：输入指令无效，请重新输入！\n");
    }
}
int main()
{
    int command; // 存储用户输入的控制指令
    while (1)
    {                           // 循环接收指令，直到输入 0 退出
        showMenu();             // 显示菜单
        scanf("%d", &command);  // 读取用户输入
        executeAction(command); // 执行对应动作
        if (command == 0)
        { // 输入 0，退出循环
            break;
        }
    }
    return 0;
}