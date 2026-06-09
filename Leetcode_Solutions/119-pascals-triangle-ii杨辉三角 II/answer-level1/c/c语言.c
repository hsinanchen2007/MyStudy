### 解题思路
1
11
121
1331
.....
从后向前计算数组，两头为1，其余的a[i]=a[i]+a[i-1]
注意：审题要仔细，第n行输出的是n+1个数，否则会出现溢出
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    * returnSize=rowIndex+1;
        int *returnarray;
        returnarray=(int *)malloc(sizeof(int)*(rowIndex+1));
        int i,j;
        returnarray[0]=1;
        for(i=1;i<=rowIndex+1;i++){
                returnarray[i-1]=1;
                for(j=i-2;j>=1;j--){
                    returnarray[j]=returnarray[j]+returnarray[j-1];
                    
                }
        }
        return returnarray;
}
```