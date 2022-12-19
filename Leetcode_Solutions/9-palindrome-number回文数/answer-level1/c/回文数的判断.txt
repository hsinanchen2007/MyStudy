分析题目得知，如果是负数则肯定是false，对正数的解法有两个
方法1. 直接计算反转后的数，与当前数比较，相等则为回文数；该方法实际测试结果耗时较长；
方法2. 将输入的整数按位分解到数组中保存，然后同时比较头尾的数字是否相等，该方法耗时较少。
```
bool isPalindrome(int x){ 
    char num[10];
    char cnt = 0;
    char i;

    if (x < 0)
        return false;
 
    while (x > 0)
    {   
        num[cnt++] = x % 10; 
        x /= 10; 
    }   

    for (i = 0; i < cnt / 2; i++)
    {   
        if (num[i] != num[cnt - i - 1]) 
            return false;
    }   

    return true;
}
```

