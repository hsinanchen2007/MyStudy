### 解题思路
双指针，执行用时:60 ms

### 代码

```javascript
var merge = function (nums1, m, nums2, n) {
    // 确定 nums1 与 nums2 的遍历起点
    let i = m - 1, j = n - 1;
    while (i >= 0 && j >= 0) {
        if (nums1[i] <= nums2[j]) {
            nums1[i + j + 1] = nums2[j];
            j--;
        } else {
            nums1[i + j + 1] = nums1[i];
            i--;
        }
    }
    // nums1数组遍历结束，nums2中还有元素，则将nums2剩余元素一一填如nums1
    if (i < 0) {
        nums2.slice(0, j + 1).map((target, index) => {
            nums1[index] = target;
        })
    }
};
```
![扫码_搜索联合传播样式-标准色版.png](https://pic.leetcode-cn.com/f48ff8c7de8ebd96afe76391439767fa72cabcd83ddea65dc957787c4ebc6ca5-%E6%89%AB%E7%A0%81_%E6%90%9C%E7%B4%A2%E8%81%94%E5%90%88%E4%BC%A0%E6%92%AD%E6%A0%B7%E5%BC%8F-%E6%A0%87%E5%87%86%E8%89%B2%E7%89%88.png)