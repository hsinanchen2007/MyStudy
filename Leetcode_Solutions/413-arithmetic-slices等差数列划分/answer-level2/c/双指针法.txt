### 解题思路
1. 用一个n维数组盛放数组A的两两差值（数组索引从 1：n-1）
2. 用left,right指针，来找到差值相同的索引范围，然后计算结果即可

### 代码

```c


int caculate(int x){
    if (x<=1)
        return 0;
    x++;
    return (x-1)*(x-2)/2;
}


int numberOfArithmeticSlices(int* A, int ASize){
    int *delta=malloc(sizeof(int)*ASize),count=0;
    for (int i=1;i<ASize;i++)
        delta[i] = A[i] - A[i-1];
    int left,right;
    left = 1;
    right = 1;
    while(left<ASize){
        while(right<ASize&&delta[right]==delta[left])
            right++;
        count += caculate(right-left);
        left = right;
    }
    return count;
}
```