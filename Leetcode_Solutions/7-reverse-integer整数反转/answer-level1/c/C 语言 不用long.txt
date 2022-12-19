### 解题思路
C 语言 不用long

### 代码

```c
int reverse(int x){

    int num = 0;
    bool flag = true;
    if (x==-2147483648)
        return 0;
    if (x<0) 
    {
        flag = false;
        x = -x;
    }
    num = x%10;
    
    while (x/10)
    {
        x = x/10;
        if (num>((2147483648-x%10)/10))
            return 0;
        num = num*10 + x%10;   
    }
    if (flag==true)
        return num;
    else
        return -num;

}
```