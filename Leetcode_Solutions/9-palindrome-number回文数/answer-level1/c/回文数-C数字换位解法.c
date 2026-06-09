### 解题思路
C数字换位解法

### 代码

```c
bool isPalindrome(int x){
    long y=0;
    long z=(long)x;//保留x的原值
    if(x<0)return false;//负数直接返回0
    while(x>0)//x换位操作
    {
        y=y*10+(x%10);
        x=x/10;
    }
    return !(long)(z-y);//强制转换长整形，x的原值z与x换位后的值y比较，相同值为0，取反为ture；x为0，取反为ture

}
