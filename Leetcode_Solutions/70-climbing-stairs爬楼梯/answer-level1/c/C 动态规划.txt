### 解题思路
n阶的方法数目，转化为n-1阶的方法数加上n-2的方法数。

### 代码

```c

//动态规划
int climbStairs(int n){
    //n阶的方法数目，转化为n-1阶的方法数加上n-2的方法数。
    int result =0;
    if (1 == n) {
        return 1;
    }
    if ( 2 == n) {
        return 2;
    }
    int* dpArray = (int *)malloc(sizeof(int)*n);
    memset(dpArray,0,n);
    *dpArray = 1;
    *(dpArray+1) = 2;
    for(int i=2;i<n;i++) {
        *(dpArray+i) = *(dpArray+(i-1)) + *(dpArray+(i-2));
    }
    result = *(dpArray+n-1);
    free(dpArray);
    return result;
}

```