**用2，3,5去除num，最后判断num是否为1即可。**
```c
bool isUgly(int num)
{
    if(num <= 0)
        return 0;
    if(num == 1)
        return 1;
    while(num % 2 == 0)
        num /= 2;
    while(num  % 3 == 0)
        num /= 3;
    while(num % 5 == 0)
        num /= 5;
    return (num == 1) ? 1 : 0;
}
```