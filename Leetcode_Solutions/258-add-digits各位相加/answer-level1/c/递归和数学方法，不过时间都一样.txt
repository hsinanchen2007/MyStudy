### 解题思路
此处撰写解题思路

### 代码

```c
int addDigits(int num){
    /*数学解法
    if(num%9 == 0 && num != 0)
    return 9;
    else
    return num%9;
    */
    while(num > 9)
    {
        int a = 0;
        while(num > 0)
        {
            a += num%10;
            num = num/10;
        }
        num = a;
    }
        return num;
}
```