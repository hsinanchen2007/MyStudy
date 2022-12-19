### 解题思路
可以将新石头重量直接插入到数组中合适的位置，与冒泡排序相比可以省去一些冗余的操作。。
可代码写得太烂,就这样吧。。。

### 代码

```c
int lastStoneWeight(int* stones, int stonesSize){
    if(stonesSize <= 1) return *stones;
    
    int j,k,t,i=1;
    for(j=1;j>0;j+=i){
        if(j==stonesSize) i=0,j--;
        if(i==1) t = stones[j];
        else{
            t = stones[j] - stones[--j];
            if(t==0) {stones[j--] = 0;continue;}
        }

        for(k=j-1;k>=0 && t<stones[k];k--) stones[k+1] = stones[k];
        stones[k+1] = t;
    }
    return *stones;
}
```