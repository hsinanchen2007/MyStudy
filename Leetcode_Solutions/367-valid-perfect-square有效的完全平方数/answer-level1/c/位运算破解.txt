### 解题思路
位运算判断num是二进制几位数,那么他的开方若存在,位数为他的一半,m
再搜索  m位数和 m+1位数 ,

有点类似牛顿二分,但比较符合人的思维

比如  十进制三位数  169 他的平方根必然是 俩位数   3   - >  2 
五位数  11345 他的平方根 必然是  100 到 200     5   - >  3


### 代码

```c
bool isPerfectSquare(unsigned int num)
{
    unsigned int i=num;
    short int j=0;
    for(;i>1;i=(i>>1))
        j++;
    for(i=1<<(j/2);i*i<num;i++);
    return i*i==num?1:0;  
}
```