### 解题思路
这台最简单的思路应该就是先平方，后排序，不过即时使用快速排序依旧超过时间复杂度，所以改用方法二。
方法二：先平方，由于原数组为非递减数组，所以平方后的数组形式为两边大，中间小
        设两个标志位left，right分别从平方后的数组左右两边开始移动
        将两者中较大者放入res（返回数组）的末尾


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void swap(int *a, int *b);
 void quicksort(int* a,int left, int right);

int* sortedSquares(int* A, int ASize, int* returnSize){
    int *res=(int*)malloc(sizeof(int)*ASize);
    *returnSize=ASize;
    for(int i=0;i<ASize;i++)
        A[i]=A[i]*A[i];
    
    // quicksort(res,0,(*returnSize)-1);
    int left=0,right=ASize-1;
    int i=right;
    while(left<right)
    {
        if(A[left]>=A[right]&&left<right)
        {
            res[i--]=A[left++];
        }
        if(A[left]<=A[right]&&left<right)
        {
            res[i--]=A[right--];
        }
    }
    res[0]=A[left];




    return res;
}

// void quicksort(int* a,int left, int right)
// {
//     if(left>right)
//         return;
//     int tag=a[left];
//     int i=left;
//     int j=right;
//     while(i<j)
//     {
//         while(a[j]>=tag&&i<j)
//             j--;
//         while(a[i]<=tag&&i<j)
//             i++;
//         if(i<j)
//             swap(&a[i],&a[j]);
//     }
//     swap(&a[i],&a[left]);
//     quicksort(a, 0, i-1);
//     quicksort(a, i+1, right);
// }

// void swap(int *a, int *b){
//     int temp=*a;
//     *a=*b;
//     *b=temp;
// }
```