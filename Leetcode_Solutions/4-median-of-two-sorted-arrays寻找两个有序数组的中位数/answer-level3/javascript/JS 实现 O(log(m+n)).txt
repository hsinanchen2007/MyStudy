# 原理展示：
两个数组 **A [1,2,3,4,5,6,7,8]**, **B [3,4,5,6,7,8,9,10]**
![image.png](https://pic.leetcode-cn.com/c56c8f1aacc982d30bed4f6cf5e31d100d98ec0e3305a1fe053c366111a0f6a7-image.png)
1. 两个数组二分 i=4, j=4, beforeI=0
![image.png](https://pic.leetcode-cn.com/1cd5d35641128d2347d2227282bd19cd5af2f539d8b8f9f9b8646140b5ed68fa-image.png)
**比较: A[3] <= B[4] 成立，B[3] <= A[4] 不成立**
2. i 右移两位(*(i-beforeI)/2*), j 同样左移两位  i=6,j=2,beforeI=4
![image.png](https://pic.leetcode-cn.com/59e1004e516e7d7fed5c3778cc606d0c36b5e789c8d77a00bc77b0417fc45751-image.png)
**比较: A[5] <= B[2] 不成立，B[1] <= A[6] 成立**
3. i 左移1位(*(i-beforeI)/2*), j 同样左移1位    i=5,j=3, beforeI=6
![image.png](https://pic.leetcode-cn.com/1492f029a2104805569f5de7d992b8c527fb27a4d8962a15fe223f6c4b33d61d-image.png)
**比较: A[5] <= B[2] 成立，B[1] <= A[6] 成立**
中间值 (Max(A[4],B[2]) + Min(A[5],B[3])) / 2 = 5.5

# O(log(m+n))
```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */

// 判断最小数，undefined 忽略，最多只有一个为undefined
function min(a,b) {
    if(a === undefined) return b
    if(b === undefined) return a
    return Math.min(a,b)
}
// 判断最大数，undefined 忽略，最多只有一个为undefined
function max(a,b) {
    if(a === undefined) return b
    if(b === undefined) return a
    return Math.max(a,b)
}

var findMedianSortedArrays = function (nums1, nums2) {
    // 短的数组作为nums1，可以减少二分的次数
    if (nums1.length > nums2.length) {
        let temp = nums1
        nums1 = nums2
        nums2 = temp
    }

    let len1 = nums1.length, len2 = nums2.length
    // 两个数组取中间，因为存在奇数，所以nums1 默认floor， nums2 默认 ceil，以保证 左右两侧的数量差不大于1
    let i = Math.floor(len1 / 2), j = Math.ceil(len2 / 2)
    let beforeI = 0
    
    while (true) {
        // A[L] < B[R] B[L] < A[R] 此时数量相等，满足左侧均小于右侧
        // 存在边界情况，即 两数组不相交，此时A[L]、A[R]、B[L]、B[R]可能不存在(即为undefined)，此时不做比较，直接取中间数
        if (
            (nums1[i - 1] === undefined || nums2[j] ===undefined || nums1[i - 1]<= nums2[j])
            &&
            (nums2[j - 1]===undefined ||  nums1[i] === undefined || nums2[j - 1]<= nums1[i])
        ) {
            let leftLen = i + j, rightLen = len1 + len2 - i - j;
            // 左侧数量 === 右侧数量，取 左侧最大值 和 右侧最小值 平分
            if (leftLen === rightLen) {
                return (max(nums1[i - 1], nums2[j - 1]) + min(nums2[j], nums1[i])) / 2
            }
            // 左侧数量 > 右侧数量，中位数为左侧最大值
            if (leftLen - 1 === rightLen) return max(nums1[i - 1], nums2[j - 1]);
            // 左侧数量 < 右侧数量，中位数为右侧最小值
            if (leftLen + 1 === rightLen) return min(nums2[j], nums1[i])
        } else if (nums1[i - 1] > nums2[j]) {
            // A[L] > B[R], i 左移半 j 右移同样
            let step = Math.max(Math.floor((i-beforeI) / 2), 1)
            beforeI = i
            i -= step
            j += step
            continue
        } else if (nums2[j - 1] > nums1[i]) {
            // B[L] > A[R], i 右移半 j 左移同样
            let step = Math.max(Math.floor((i - beforeI) / 2), 1)
            beforeI = i
            i += step
            j -= step
            continue
        }
    }
};
```
# O((m+n)/2) => O(n)
```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function (nums1, nums2) {
    let nums = []
    let i =0,j=0;
    let total = nums1.length+nums2.length
    let mid = Math.floor(total/2) + 1
    while(true) {
        if(nums.length === mid) {
            if( total%2 === 1) {
                return nums[mid-1]
            }else{
                return (nums[mid-1]+nums[mid-2])/2
            }
        }
        if(i < nums1.length && j === nums2.length) {
            nums.push(nums1[i])
            i++;
            continue
        }
        if(i === nums1.length && j < nums2.length) {
            nums.push(nums2[j])
            j++;
            continue
        }
        if(nums1[i] < nums2[j]) {
            nums.push(nums1[i])
            i++;
            continue
        }else{
            nums.push(nums2[j])
            j++;
            continue
        }
    }
};
```