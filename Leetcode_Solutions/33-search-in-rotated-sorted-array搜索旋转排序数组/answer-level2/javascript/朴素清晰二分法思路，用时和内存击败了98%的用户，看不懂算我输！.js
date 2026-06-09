![截屏2020-03-12上午11.56.04.png](https://pic.leetcode-cn.com/0829335ba5a2ae29b19ecd96622489edd353967181caa511d02e3cbe86833921-%E6%88%AA%E5%B1%8F2020-03-12%E4%B8%8A%E5%8D%8811.56.04.png)

### 解题思路
题目中要求时间复杂度为O(logN)，目的很明确，必须得用二分法进行解题。如果还不了解二分法的小伙伴建议先了解一下二分法。

本题的难点在于，二分法中的左指针和右指针该怎么去移，如果数组没有翻转过直接按正常的二分法思路来移动左右指针即可，但是一旦数组翻转过，情况就要细分下去了。

下面直接讲一下思路：
指定两个指针，left = 0; right = nums.length - 1; 然后有个中间指针mid = left + Math.floor((right - left) / 2);
对于二分法中的nums[mid] === target, nums[mid] > target, nums[mid] < target三种情况再细分，
分析过程中注意到：数组翻转后，其实可以看成两个有序的数组拼接在一起，右半部分的数组肯定比左半部分的数组的第一位都要小，
举个例子，nums = [4,5,6,7,0,1,2]，左半部分数组是有序的：[4,5,6,7]， 右半部分也是有序的: [0,1,2]；
且右半部分的数组内的数永远小于左半部分数组的第一位，也就是nums[left]，而左半部分数组内的数都是大于nums[left]。
这个规律有什么用呢，通过这个规律可以判断出nums[mid]以及target在哪一部分数组中，并根据这一判断来移动左右指针不断逼近target对应的索引。

逻辑判断如下：
1. nums[mid] === target，直接返回mid；
2. nums[mid] > target:
    a. 如果数组没有翻转，则按照正常的二分法解法进行左右指针的取值
    b. 如果数组翻转了，则需要进一步判断
        ① 如果target小于数组的第一位，说明target的位置在右半部分数组中，此时需要判断一下mid的位置
            I. 如果nums[mid] > nums[left]，说明mid在左半部分，mid位置在target对应索引的左边，所以需要将左指针往右移 left = mid + 1；
            II. 反之，说明mid也在右半部分，target和mid处于同一部分的数组中，又有nums[mid] > target，所以需要将右指针往左移 right = mid - 1；
        ② 如果target大于数组的第一位，说明target的位置在左半部分数组中，而nums[mid] > target > nums[left]，毋容置疑，mid也在左半部分数组中，
           所以，直接移动右指针往target靠，right = mid - 1;
3. nums[mid] < target:
    a. 如果数组没有翻转，则按照正常的二分法解法进行左右指针的取值
    b. 如果数组翻转了，则需要进一步判断
        ① 如果target小于于数组的第一位，说明target的位置在右半部分数组中，而nums[mid] < target < nums[left]，毋容置疑，mid也在左半部分数组中，
           所以，直接移动左指针往target靠，left = mid + 1;
        ② 如果target大于数组的第一位，说明target的位置在左半部分数组中，此时需要判断一下mid的位置
            I. 如果nums[mid] > nums[left]，说明mid在左半部分，nums[mid] < target，所以mid位置在target对应索引的左边，所以需要将左指针往右移 left = mid + 1；
            II. 反之，如果nums[mid] < nums[left]，说明mid在右半部分，mid的位置必然处于target的右侧，所以需要将右指针往左移 right = mid - 1；
    
下面是代码的实现：     
### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    if (!nums.length) return -1;
    let left = 0;
    let right = nums.length - 1;
    while (left <= right) {
        let mid = left + Math.floor((right - left) / 2);
        if (nums[left] === target) return left;
        if (nums[right] === target) return right;
        if (nums[mid] === target) return mid;
        if (nums[mid] > target) {
            if (nums[left] < nums[right]) {
                right = mid - 1;
                continue;
            }
            if (target < nums[left]) {
                if (nums[mid] > nums[left]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else if (target > nums[left]) {
                right = mid - 1;
            }
        } else if (nums[mid] < target) {
            if (nums[left] < nums[right]) {
                left = mid + 1;
                continue;
            }
            if (target < nums[left]) {
                left = mid + 1;
            } else if (target > nums[left]) {
                if (nums[mid] > nums[left]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
    }
    return -1;
};
```