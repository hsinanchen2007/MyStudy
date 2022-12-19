### 解题思路
如果一个数比后面的数小，那么当前数实际上就是个负数，否则就是正数

### 代码

```c
int translate(char* C)
{
    switch(*C)
    {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        case '\0': return 0;
    }
    return -1;
}

int romanToInt(char * s){
    int sum=0;
    while(*s!=0)
    {
        int num=translate(s),nextNum=translate(s+1);
        if(num>=nextNum)
            sum+=num;
        else
            sum-=num;
        ++s;
    }
    return sum;
}
```