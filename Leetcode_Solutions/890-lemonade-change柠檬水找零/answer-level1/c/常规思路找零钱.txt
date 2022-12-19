### 解题思路
第一次必为5元，否则返回false，遍历数组若遇到5元记录5元个数加一，若遇到10元记录10元个数加一并将5元的个数减一，若遇到20元无需记录，但是需要进行判断是否10元的个数大于等于一且5元的个数大于等于一，如果满足，则10元跟5元的个数减一并且continue，否则判断是否5元的个数大于等于3，如果满足，5元的个数减三，如果不满足返回false，直到遍历完整个数组返回true

### 代码

```c
bool lemonadeChange(int* bills, int billsSize){
    int i,a=0,b=0;
    if(bills[0]!=5)
    return false;
    a++;
    for(i=1;i<billsSize;i++)
    {
        if(bills[i]==5)
        a++;
        if(bills[i]==10)
        {
            if(a>=1)
            {
                a--;
                b++;
            }
            else
            return false;
        }
        if(bills[i]==20)
        {
            if(a>=1&&b>=1)
            {
                b--;
                a--;
                continue;
            }
            if(a>=3)
            a-=3;
            else
            return false;
        }
    }
    return true;
}
```