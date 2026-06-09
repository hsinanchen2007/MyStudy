### 解题思路
快速排序（附选择排序和折半），快速排序还是没超时，但是用了递归，时间略长

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 //法一：选择
// int* sortArray(int* nums, int numsSize, int* returnSize){
//     int i,j,min,ex;
//     *returnSize=numsSize;
//     for(j=0;j<numsSize-1;j++){
//         min=j;
//         for(i=j+1;i<numsSize;i++){
//             min = nums[i] < nums[min] ? i : min;
//         }
//         if(min!=j){
//             ex=nums[j];
//             nums[j]=nums[min];
//             nums[min]=ex;    
//         } 
//     }
//     return nums;
// }
//法二:折半查找
// int* sortArray(int* nums, int numsSize, int* returnSize){
//     int i,j,low,high,mid,temp;
//     *returnSize=numsSize;
//     for(j=0;j<numsSize;j++){
//         temp=nums[j];
//         low=0;
//         high=j-1;
//         while(low<=high){
//             mid=(low+high)/2;
//             if(nums[mid]>temp)
//                 high=mid-1;
//             else
//                 low=mid+1;
//         }
//         for(i=j-1;i>=high+1;i--){
//             nums[i+1]=nums[i];
//         }
//         nums[high+1]=temp;
//     }
//     return nums;
// }
//法三：快速排序（前两种超时）
void quicksort(int* Nums, int left, int right){
    if(left<right){
        int i=left,j=right,temp=Nums[left];
        while(i!=j){
            while(i<j&&Nums[j]>temp)
                j--;
        if(i<j)
            Nums[i++]=Nums[j];
        while(i<j&&Nums[i]<temp)
            i++;
        if(i<j)
            Nums[j--]=Nums[i];
        }
        Nums[i]=temp;//
        quicksort(Nums,left,i-1);
        quicksort(Nums,i+1,right);

    }
}
int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize=numsSize;
    quicksort(nums,0,numsSize-1);
    return nums;
}


```