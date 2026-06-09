### 解题思路
此处撰写解题思路
主要用的是插入排序，当然这不是最优的方案，这种排序时间复杂度为O（n^2）,可以试用快速排序复杂度o(nlogn).之前看过插入排序的算法尝试一下。
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    int i,j;
    int temp;
    int*ans=(int*)malloc(sizeof(int)*k);
    for(j=1;j<arrSize;j++){
        temp=arr[j];
        for(i=j;i>0&&arr[i-1]>temp;i--)
        {
            arr[i]=arr[i-1];
        }
        arr[i]=temp;
    }
    for(i=0;i<k;i++) ans[i]=arr[i];
    *returnSize = k;
    return ans;
      
     

}
```