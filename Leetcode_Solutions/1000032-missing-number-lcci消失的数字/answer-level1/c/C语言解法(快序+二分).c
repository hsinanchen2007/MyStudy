### 解题方法选择
此题解法有很多种，如异或、以空间换时间等等。
此解法使用快速排序和二分法。

### 为什么应用此解法

二分法适合在排序好的组中查找某个特定数或者某个特定段，如 *“排序数组中为k的数”、“排序数组中等于k的数左右边界”*等等。而此题可以翻译为在排序好的数组中找出**第一个**上标i和nums[i]不同的数，可以通过二分法来解决。

此题给出的是未排序数组，所以要进行排序，这里选择快速排序，因为其时间复杂度相对较低。
插播一句：快速排序能解决很多问题，比如*“输出排序后的前k个数”、“排序后的第k个数”、“第k大（小）的数”*，这些题通过快速排序解决会有比较低的时间复杂度。

### 代码部分解释
代码中的快速排序部分不进行解释，可以网上自行查找
这里对二分法模板进行讲解：

二分法有很多模板，首先在left和right选择上，会发现有的题有right=numsSize或者numsSize-1，在while循环中，有left<right或者left<=right的，其实这些选择对应于不同的题目需求。

1. 模板一：最基本的模板
此模板一般用来操作排序数组中的某个特定数，比如“查找数组中某一元素下标”、以及平方根问题；
但是需要注意，循环条件是left<=right，也就是说，在while结束后left和right并不相等
```
int left = 0, right = nums.size() - 1;
  while(left <= right){
    int mid = left + (right - left) / 2;
    if(nums[mid] == target){ return mid; }
    else if(nums[mid] < target) { left = mid + 1; }
    else { right = mid - 1; }
  }
```
2. 模板二：右开边界
右开边界是指：right=numsSize，所以区间可以表示为[left,right)，由于是右开边界，所以while循环中是right=mid，而不是mid-1；
这个模板主要用来查找邻居，举个例子，在一个排序数组中，想查找第一个等于k的数或者查找最后一个等于k的数，或者查找等于k的数的左右边界，使用此模板最好
比如此题：[https://leetcode-cn.com/problems/remove-element/]()
也用此模板给出了解答：[https://leetcode-cn.com/problems/remove-element/solution/cpai-xu-er-fen-fa-by-kintsugi/]()
```
int left = 0, right = nums.size();
  while(left < right){
    int mid = left + (right - left) / 2;
    if(nums[mid] == target){ return mid; }
    else if(nums[mid] < target) { left = mid + 1; }
    else { right = mid; } //注意right不是mid-1
  }
```

这些模板更加详细的解释可以在[https://leetcode-cn.com/explore/learn/card/binary-search]()找到



### 代码

![image.png](https://pic.leetcode-cn.com/225123d9442eb8a8549ed0977a516d48bf13505d3596281959a52b9d39c4a543-image.png)


```c
 int Partition(int *A, int low, int high){
    int pivot=A[low];
    while(low<high){
        while(low<high && A[high]>=pivot) high--;
        A[low]=A[high];
        while(low<high && A[low]<=pivot) low++;
        A[high]=A[low];
    }
    A[low]=pivot;
    return low;
 }

 void QuickSort(int *A, int low, int high){
    if(low<high){
        int PartitionPos = Partition(A,low, high);
        QuickSort(A,low,PartitionPos-1);
        QuickSort(A,PartitionPos+1, high);
    }

 }

int missingNumber(int* nums, int numsSize){
    QuickSort(nums, 0, numsSize-1);
    int left=0, right=numsSize;
    while(left<right){
        int mid=left+(right-left)/2;
        if(nums[mid]==mid){
            left=mid+1;
        }
        else{
            right=mid;
        }
    }
    return left;

}
```