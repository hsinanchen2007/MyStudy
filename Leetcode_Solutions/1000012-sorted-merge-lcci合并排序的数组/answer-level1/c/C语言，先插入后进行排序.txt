### 解题思路
使用一种不需要怎么思考的方法，数组A中有足够的空间，那就把数组B全部放进数组A中后，再对数组A进行排序，我采用的是冒泡排序，时间是O(n2)。

![image.png](https://pic.leetcode-cn.com/c4088d2bbbd86675a892e209fdda57c64c33db85a8dfde2c0f710462ca1988a0-image.png)

### 代码

```c
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int j = 0;
    int temp;
    for(int i = ASize - BSize;i < ASize;i++){
        A[i] = B[j];
        j++;
    }
    for(int i=ASize-1;i > 0;i--){
        for(int k=0;k < i;k++){
            if(A[k] > A[k+1]){
                temp = A[k];
                A[k] = A[k+1];
                A[k+1] = temp;
            }
        }
    }
    return A;
}
```