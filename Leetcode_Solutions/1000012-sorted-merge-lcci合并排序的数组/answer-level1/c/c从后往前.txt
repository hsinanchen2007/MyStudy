### 解题思路
实现空间复杂度为1的C语言代码，从A数组的后面开始存，每次判断是从A的最开始元素的最后面还是B的开始元素的最后面取数

### 代码

```c
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int a=m-1,b=n-1,i=m+n-1;
    for(;i>=0;i--){
        if(a<0) A[i]=B[b--];
        else if(b<0) A[i]=A[a--];
        else if(A[a]>B[b]){
            A[i]=A[a--];
        }
        else {
            A[i]=B[b--];
        }
    }
}
```