### 解题思路
1. 前提A够容纳A和B
2. 从A的m+n-1开始遍历到0，每次选AB当前最大的元素
3. A或B为空后（idx=-1），复制另外一个数组剩余的元素

### 代码

```c
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int i;
    int idxa = m-1;
    int idxb = n-1;
    
    for (i=m+n-1; i>=0; i--) {
        if (idxa == -1) A[i] = B[idxb--];
        else if (idxb == -1) A[i] = A[idxa--];
        else if (A[idxa] > B[idxb]) A[i] = A[idxa--];
        else A[i] = B[idxb--];
    }
}
```