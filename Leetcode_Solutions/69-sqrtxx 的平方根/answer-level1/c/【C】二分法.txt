### 解题思路
二分法查找所求

### 代码

```c
int mySqrt(int x){
    if(x>0 && x<4) return 1;
    long l=0, r=x, i=(l+r)>>1;
    while(true){
        if(i*i<=x && (i+1)*(i+1)>x) return i;
        r = i*i>x ? i : r;
        l = i*i<x ? i : l;
        i = (l+r)/2;
    }
    return -1;
}
```