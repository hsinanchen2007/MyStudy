# 题目描述
给定两个大小为**m**和**n**的有序数组**nums1**和**nums2**。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为**O(log(m + n))**。

你可以假设**nums1**和**nums2**不会同时为空。

**示例 1**:

```
nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
```
**示例 2**:

```
nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5
```

# 题目分析
根据他的要求——算法的时间复杂度为**O(log(m + n))**，实际上我们就可以猜测我们最后的算法应该是分治法。但是，问题正在于如何将该问题转换为对应的分治法所能求解的模型，这是这道题的难点。这里，我做题的时候借鉴了官方的题解，这里总结一下经验。

首先，我们需要把抽象的语言描述转换为具体的数学描述。实际上，如果我们从两个数组中分别选取一个标志——index1、index2，从而将每一个数组分为两部分——对于nums1来说，分为了`[0, index1 - 1]`和`[index1, nums1Size]`；对于nums2来说，分为了`[0, index2 - 1]` 和 `[index2, nums2Size]`。
那么实际上，我们转换的具体的数学描述就是index1、index2需要满足如下要求

1.  `[0, index1 - 1] + [0, index2 - 1]` 的集合并**比**`[index1, nums1Size] + [index2, nums2Size]` 的集合并的元素个数相等或少一，也就是`(index1 - 1 + 1) + (index2 - 1 + 1) = (nums1Size + nums2Size) >> 1`
2.  确保左边的最大值小于等于右边的最小值，也就是`nums1[index1 - 1] <= nums2[index2]`,并且`nums2[index2 - 1] <= nums1[index1]`

那么如果满足以上条件的话，我们进行分析，则实际上，如果数组的大小之和为奇数，那么最终的答案就是`(double)min(nums1[index1], nums2[index2])`；如果数组的大小之和为偶数的话，那么明显的最终的答案就是`(max(nums1[index1 - 1], nums2[index2 - 1]) + min(nums1[index1], nums2[index2])) / 2.0`

所以，基本的思路定下来后，我们进行具体的分析就行了
根据条件1，实际上也就是`index1 + index2 = (nums1Size + nums2Size) >> 1`,那么实际上只要`index1`确定，那么为了满足条件1，则`index2`也随之确定了下来。那么接下来，仅仅需要满足条件2就行。
实际上，这里就变成了一个二分问题——如果不满足条件二的话，实际上只有两种可能，要么`nums1[index1 - 1] > nums1[index2]`，要么`nums2[index2 - 1] > nums2[index1]`。

而实际上这两种情况正好是二分法的两种情况：
1. `nums1[index1 - 1] > nums2[index2]`这种情况明显就是index1选的值过大，那么只要通过二分法将index1缩小即可
2. `nums2[index2 - 1] > nums1[index1]`这种情况明显就是index1选的值过下，那么只要通过二分法将index1增大即可。

当然，还需要注意一下细节——index1进行二分的时候，按照二分的流程，是需要知道index1的范围的，这里的范围也很好确定
```
0 <= index1 <= nums1Size && 0 <= index2 <= nums2Size
```
当取边界的时候，也就是代表左半边数组或右半边数组为空，还需要注意一下边界情况的判断比较，这个我们通过主观感觉就可以判断——如果左边为空或右半边为空，那么自然的，任何的数都比空小，任何的数都比空大，也就是当判断的两边任何一边有非法情况的话（Ex：nums1[-1] < nums2[num2Size]，两边都是非法的情况，属于至少有一边是非法的情况，则直接成立），我们都默认是成立的。

下面是源代码
```
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    // 如果下标非法，则任何判断都是成立的

    int mid = (nums1Size + nums2Size) >> 1, min = (mid - nums2Size) > -1 ? (mid - nums2Size) : 0, max = nums1Size > mid ? mid : nums1Size, index1 = (min + max) >> 1, index2 = mid - index1;

    if(!nums1Size) {
        return (nums2Size % 2) ? (double)nums2[nums2Size >> 1] : ((nums2[nums2Size >> 1] + nums2[(nums2Size >> 1) - 1]) / 2.0);
    }else if(!nums2Size){
        return (nums1Size % 2) ? (double)nums1[nums1Size >> 1] : ((nums1[nums1Size >> 1] + nums1[(nums1Size >> 1) - 1]) / 2.0);
    }

    while(true){
        if(((index1 < 1) || (index2 >= nums2Size) || nums1[index1 - 1] <= nums2[index2]) && ((index2 < 1) || (index1 >= nums1Size) || nums2[index2 - 1] <= nums1[index1])) {
            break;
        }else if((index1 < 1) || (index2 >= nums2Size) || nums1[index1 - 1] <= nums2[index2]){
            min = index1 + 1;
            index1 =  index1 + 1;
        }else{
            max = index1 - 1;
        }
        index1 = min + ((max - min) >> 1);
        index2 = mid - index1;
    }
    if(index1 < 1){
        max = nums2[index2 - 1];
    }else if(index2 < 1){
        max = nums1[index1 - 1];
    }else{
        max = nums1[index1 - 1] > nums2[index2 - 1] ? nums1[index1 - 1] : nums2[index2 - 1];
    }

    if(index1 >= nums1Size){
        min = nums2[index2];
    }else if(index2 >= nums2Size){
        min = nums1[index1];
    }else{
        min = nums1[index1] < nums2[index2] ? nums1[index1] : nums2[index2];
    }

    return ((nums1Size + nums2Size) % 2) ? ((double)min) : ((min + max) / 2.0);
}
```
