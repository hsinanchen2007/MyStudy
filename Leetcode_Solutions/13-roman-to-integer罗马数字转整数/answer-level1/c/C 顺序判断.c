### 解题思路
1.每个单个字符都对应一个数值：使用switch语句映射；
2.字符串s依次比较大小：一般情况，字符数值从左到右依次减小（II,III）
3.减法只有在下述情境下出现：相邻的两个字符，左边的比右边的数值小；
4.减法为特例，出现时指数要跳一位。

### 代码

```c
int getVal(char c)
{
    switch(c)
    {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}
int romanToInt(char * s){
    int len = strlen(s);
    int sum = 0;
    for(int i=0;i<len;i++)
    {
        if(getVal(s[i+1]) > getVal(s[i]))
        {
            sum += getVal(s[i+1]) - getVal(s[i]);
            i++; //减法为特例，出现时指数要跳一位
        }
        else
            sum += getVal(s[i]);
    }
    return sum;
}
```