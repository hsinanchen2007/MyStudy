### 解题思路
此处撰写解题思路
简单的顺序表插入，注意每次的尾部索引更新
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void insert(int *a,int m,int k, int x)    //m就是每次操作的尾部
 {
    for(int i=m;i>k;i--)
     {
         a[i]=a[i-1];
     }
    a[k]=x;

 }
int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize){
    int * target=(int*)malloc(sizeof(int )*numsSize);
    *returnSize=numsSize;
    int i=0;
    for(i=0;i<numsSize;i++)
    {
        insert(target,i,index[i],nums[i]);
    }
    return target;
}
```