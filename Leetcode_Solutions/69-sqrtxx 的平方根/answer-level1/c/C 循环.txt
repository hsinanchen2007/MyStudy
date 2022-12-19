### 解题思路
此处撰写解题思路
循环，直到i 的平方等于x或者大于x，内存消耗击败100%，但是用时击败才26.49%
### 代码

```c
int mySqrt(int x){
    long i;
    for(i = 0;;i++){
        if(i*i > x)
            return i-1;
        if(i*i== x)
            return i;
    }
}
```