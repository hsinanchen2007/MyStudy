快速排序
```
int cmp(void* a,void *b)
{
    return *(int*)a-*(int*)b;
}
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    for(int i=m,j=0;j<n;i++,j++)
        A[i]=B[j];
    qsort(A,m+n,sizeof(int),cmp);
}
```
双指针
```
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int k=m+n-1;
    int i=m-1,j=n-1;
    while(i>=0&&j>=0&&k>i)
    {
        if(A[i]>B[j])
            A[k--]=A[i--];
        else
            A[k--]=B[j--];
    }
    while(j>=0)//特殊情况，m=0
        A[k--]=B[j--];
}
```
一道类似的题，[21. 合并两个有序链表 - 力扣（LeetCode）  https://leetcode-cn.com/problems/merge-two-sorted-lists/]()。



