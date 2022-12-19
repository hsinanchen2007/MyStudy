### 解题思路
两个变量分别控制奇数位置和偶数位置。
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* A, int ASize, int* returnSize){
    int* num=(int*)malloc(sizeof(int)*ASize);
    int cnt=0;      //  偶数
    int cmt=1;      //  奇数
    for(int i=0;i<ASize;i++)
    {
        if(A[i]%2==0)
        {
            num[cnt]=A[i];
            cnt+=2;
        }
        else
        {
            num[cmt]=A[i];
            cmt+=2;
        }
    }
    *returnSize=ASize;
    return num;
}
```