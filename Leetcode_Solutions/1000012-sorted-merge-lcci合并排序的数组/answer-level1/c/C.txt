### 解题思路
新开辟一块空间，将两个数据元素排序

### 代码

```c
void merge(int* A, int ASize, int m, int* B, int BSize, int n){

    int *buff = NULL;
    int i = 0;
    int a,b;

    buff = (int *)malloc(sizeof(int)*(m+n));

    a = b = 0;
    while(i < m+n){

        if(a == m){
            buff[i++] = B[b++];
            continue;
        }

        if(b == n){
            buff[i++] = A[a++];
            continue;
        }

        if(A[a] > B[b]){
            buff[i++] = B[b++];
        }
        else if(A[a] < B[b]){
            buff[i++] = A[a++];
        }
        else{
            buff[i++] = A[a++];
            buff[i++] = B[b++];
        }
    }

    memcpy(A, buff, sizeof(int)*(m+n));
    return;
}
```