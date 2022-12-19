### 解题思路
此处撰写解题思路
这个题此处和offer书中不一样，被简化了许多，建议大家看看书上的解题方式，
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* printNumbers(int n, int* returnSize){
    int num = 1;
    int i=1;
    while(i++<=n)
        num*=10;
    int j=1;
    int *res=(int *)malloc(num*sizeof(int));
    int k=0;
    for(j=1;j<num;j++)
    {
        res[k++]=j;
    }
    *returnSize=num-1;
    return res;


}
```