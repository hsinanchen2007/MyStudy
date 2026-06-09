### 解题思路
//方法一：二分法查找

### 代码

```c
//方法一：二分法查找
int mySqrt(int x){

    int     iLeft       = 1;
    int     iRight      = x / 2;        //x的平方根不会大于 x/2
    int     iTmp        = 0;

    if (0 == x) return 0;
    if (1 == x) return 1;

    while (iLeft < iRight)
    { 
        iTmp = (iLeft + iRight + 1) / 2;
        if (iTmp == x / iTmp)
        {
            iLeft = iTmp;
            break;
        }
        else if (iTmp < x / iTmp)
        {
            iLeft = iTmp;
        }
        else
        {
            iRight = iTmp - 1;
        }
    }

    return iLeft;
}
```