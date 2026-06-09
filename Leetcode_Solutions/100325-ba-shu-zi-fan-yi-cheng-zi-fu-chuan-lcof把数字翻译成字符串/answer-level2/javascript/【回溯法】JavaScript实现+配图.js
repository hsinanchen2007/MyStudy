
## 解法：回溯法

这题其实就是求解空间树中，从定点到叶节点的路径总数。需要注意的是，每次可以选择 1 位数字，或者合法的 2 位数字（`10 <= n <= 25`）。

以 123 为例，它的解空间树如下：

![](https://pic.leetcode-cn.com/d45e84ada4f9261739cf1df20178321e79b9c55e1f32c979e534107e1c9bd231.jpg)

可以看到，从图中可以看到，一共有三种合法的翻译方式：

-   1、23
-   1、2、3
-   12、3

代码实现如下：

```javascript
// ac地址： https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/
// 原文地址：https://xxoo521.com/2020-03-10-num-to-str/

/**
 * @param {number} num
 * @return {number}
 */
var translateNum = function(num) {
    let result = 0;
    traceback(num + "", 0);
    return result;

    /**
     * @param {string} str
     * @param {number} start
     */
    function traceback(str, start) {
        if (start >= str.length) {
            ++result;
            return;
        }

        traceback(str, start + 1);
        const sub = str.substr(start, 2);
        if (sub.length === 2 && sub >= "10" && sub <= "25") {
            traceback(str, start + 2);
        }
    }
};
```

## 更多资料

**整理不易，若对您有帮助，请给个「关注+点赞」，您的支持是我更新的动力** 👇

-   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
-   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
-   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
