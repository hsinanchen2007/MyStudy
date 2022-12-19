### 解题思路
若x小于1，返回x。
设置循环i<x：
1：i平方等于x，符合题意
2：当i+1的平方大于x时，此时i为平方根的整数值
（用时太长，内存打败100%）

### 代码

```c
int mySqrt(int x){
    long i;
    if(x <= 1){
        return x;
    }
    for(i=0;i<x;i++){
        if((i*i) == x){
            return i;
        }
        if((i+1)*(i+1)>x){
            return i;
            
        }
    }
    return i;
}
```