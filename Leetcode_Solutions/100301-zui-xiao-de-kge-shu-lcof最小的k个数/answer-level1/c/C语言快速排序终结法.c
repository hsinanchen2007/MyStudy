### 解题思路
![捕获.JPG](https://pic.leetcode-cn.com/43fbffb8f5199156fb4994c15be50533591ad90c15d2ed9af801674cbef7e2e8-%E6%8D%95%E8%8E%B7.JPG)

此题主要方法是快速排序法，但是可以做一些手法省去不必要的阶段

快速排序分为两部分：
Partition和QuickSort
1. Partition可以确定一个数的最终位置；
2. 在partition确定一个最终位置后，再递归调用Quicksort在partition两边继续排序

本解法的思想：只对前k个数进行排序。
即：在partition确定一个元素位置pos后，看其是否大于等于k；如果大于等于k，
那么只处理这个pos左边的元素；
否则处理pos左边和右边的元素

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//确定元素最终位置
 int Partition(int* nums, int low, int high){
     int pivot=nums[low];
     while(low<high){
         while(low<high && nums[high]>=pivot) --high;
         nums[low]=nums[high];
         while(low<high && nums[low]<=pivot) ++low;
         nums[high]=nums[low];
     }
     nums[low]=pivot;
     return low;
 }
//递归进行排序，并且查看pivotpos是否大于等于k
 void QuickSort(int *nums, int low, int high, int k){
     if(low<high){
         int pivotpos=Partition(nums,low,high);
         if(pivotpos>=k){
             QuickSort(nums,low,pivotpos-1,k);
         }
         else{
             QuickSort(nums,low,pivotpos-1,k);
             QuickSort(nums,pivotpos+1,high, k);
         }
     }
 }
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    QuickSort(arr,0,arrSize-1,k-1);
    (*returnSize)=k;
    return arr;
}
```