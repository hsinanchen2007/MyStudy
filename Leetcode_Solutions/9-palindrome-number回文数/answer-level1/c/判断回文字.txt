### 暴力求解
求逆序输出，然后对比判断**（注意逆序输出存在的溢出的问题）**

### 代码

```c
bool isPalindrome(int x){

    int source = x;
    long result = 0;

    if(x < 0)
    {
        return false;
    }
    else
    {
        while(x)
        {
            result = result * 10 + x % 10;  //注意逆序输出可能溢出问题
            x /= 10;
        }
        if((long)source == result)  
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
```