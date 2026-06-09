### 解题思路
此处撰写解题思路
统计A B糖果总和，计算出差值sumA-sumB
满足交换的要求时交换糖果A[i]-B[j]==（sumA-sumB)/2
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* fairCandySwap(int* A, int ASize, int* B, int BSize, int* returnSize){
    int sumA=0,sumB=0;
    int *res=(int*)malloc(sizeof(int)*2);
    for(int i=0;i<ASize;i++)
        sumA+=A[i];
    for(int i=0;i<BSize;i++)
        sumB+=B[i];

    for(int i=0;i<ASize;i++)
    {
        for(int j=0;j<BSize;j++)
        {
            if((sumA-sumB)/2==A[i]-B[j])
            {
                res[0]=A[i];
                res[1]=B[j];
                break;
            }
        }
    }
    *returnSize=2;

    return res;

}
```