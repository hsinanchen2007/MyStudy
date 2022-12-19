### 解题思路
1、先把数组B放到数组A里；
2、对数组A进行遍历排序；
P.S. 算是最简单直观的方法了，但效率不够高。

### 代码

```c
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    for (int i = 0; i< BSize; i++){
        A[i+m] = B[i];
    }
    for (int i = 0;i < ASize-1; i++ ){
        for (int j = i; j<ASize-1; j++){
            int k = 0;
            if (A[i]>A[j+1]){
                k = A[i];
                A[i]= A[j+1];
                A[j+1]=k;
            }
        }
    }

}
```