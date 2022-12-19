### 解题思路
此处撰写解题思路

### 代码

```c
int repeatedNTimes(int* A, int ASize){
    int i,j;
    for(i=0;i<ASize;i++){
        for(j=i+1;j<ASize;j++){
            if(A[i]==A[j]){
                return A[i];
            }
        }
    }
    return 0;
}
```