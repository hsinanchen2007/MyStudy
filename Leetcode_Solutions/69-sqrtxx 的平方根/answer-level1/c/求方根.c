### 解题思路
二分查找
唉！咋又坑在了数值范围溢出！！

### 代码

```c
int mySqrt(int x){

    int low = 0;
    int high = x;
    int middle = 0;
    if(x < 0)
        return -1;

    if(x <= 1)
        return x;

    while((high - low) > 1)     //二分法O(logN)
    {
        middle = (low + high)/2;
        //if(middle*middle > x)     //注意溢出问题
        if(x/middle < middle)  
            high = middle;
        else
            low = middle;
    }
    return low;    
}
```