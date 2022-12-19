### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
int *a,i,j;
a=(int *)malloc(sizeof(int)*(rowIndex+1));
memset(a,0,sizeof(int)*rowIndex);
a[0]=1;
for(i=1;i<=rowIndex;i++){
    for(j=i;j>0;j--){
        a[j]=a[j]+a[j-1];
    }
}
a[rowIndex]=1;
*returnSize = rowIndex+1;
return a;
}
```