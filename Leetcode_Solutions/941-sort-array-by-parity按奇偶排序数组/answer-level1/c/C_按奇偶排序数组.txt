### 解题思路
跟据快速排序改编

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void func(int* A,int Low,int High)
{
    while(Low<High)
    {
        while(Low<High&&A[Low]%2==0)++Low;
        while(Low<High&&A[High]%2==1)--High;
        int temp=A[Low];
        A[Low]=A[High];
        A[High]=temp;
    }
}
int* sortArrayByParity(int* A, int ASize, int* returnSize){
    * returnSize=ASize;
    func(A,0,ASize-1);
    return A;
}
```