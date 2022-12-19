### 解题思路
从后往前翻转，这道题我觉得出的还是不错的，一般翻转大家都是针对字符串进行翻转，这里是针对整数。

看代码应该就能懂的哈。

### 代码

```c
#define max pow(2,31)-1
#define min (-1)*pow(2,31)
int reverse(int x) {
    long t=x;
    long temp=0;
    while(t)
    {
        temp = 10*temp + (t%10);
        t=t/10;
    }
    if(temp>max||temp<min)//溢出
        return 0;
    return temp;
}
```