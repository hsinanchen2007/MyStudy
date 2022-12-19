### 解题思路
题目比较简单，这里只提几个关键地方
+ 最后一个索引位置是 `m+n-1`
+ nums2 并入完成后，合并已经结束（官方题解中还继续对nums1进行赋值）


### 提交结果
![image.png](https://pic.leetcode-cn.com/a195f1dbdc9c3af8437e96eb9ff0502bd94f6e46f4cc0b3a5484252e92c4616c-image.png)


### 代码

```javascript
/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
    let idx = m+n-1, i=m-1,j=n-1;
    // 当 nums2 并入完成
    while (j >= 0) {
        if (i>=0 && nums1[i] >= nums2[j]) {
            nums1[idx] = nums1[i];
            i--;
        } else {
            nums1[idx] = nums2[j];
            j--;
        }
        idx--;
    }
    return nums1;
};
```