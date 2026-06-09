
## 解法：二分查找

利用二分查找，整体流程是：

-   left 指向 0，right 指向最后一个元素
-   计算中间坐标 mid：
    -   如果`mid = nums[mid]`，说明`[0, mid]`范围内不缺失数字，left 更新为 mid + 1
    -   如果`mid < nums[mid]`，说明`[mid, right]`范围内不缺失数字，right 更新为 mid - 1
-   检查 left 是否小于等于 mid，若成立，返回第 2 步；否则，向下执行
-   返回 left 即可

注意，根据题意，可以知道`mid > nums[mid]`这种情况不存在。

代码实现如下：

```javascript
// ad地址：https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof/
// 原文地址：https://xxoo521.com/2020-03-14-missing-number/
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    let left = 0,
        right = nums.length - 1;
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        if (mid === nums[mid]) {
            left = mid + 1;
        } else if (mid < nums[mid]) {
            right = mid - 1;
        }
    }

    return left;
};
```

## 更多资料

**整理不易，若对您有帮助，请给个「关注+点赞」，您的支持是我更新的动力** 👇

-   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
-   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
-   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
