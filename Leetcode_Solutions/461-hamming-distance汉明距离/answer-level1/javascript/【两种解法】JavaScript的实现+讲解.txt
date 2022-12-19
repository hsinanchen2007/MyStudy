
## 解法 1：使用掩码

这里使用掩码对 x 和 y 进行 `&` 运算。若 x 和 y 在此位上的二进制不同，那么相与的结果不同。

代码实现如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/hamming-distance/
// 原文地址：https://xxoo521.com/2020-03-04-hamming-distance/
var hammingDistance = function(x, y) {
    let dis = 0;
    let mask = 0x01;
    let times = 0;
    while (times < 31) {
        if ((x & mask) !== (y & mask)) {
            ++dis;
        }
        mask = mask << 1;
        ++times;
    }

    return dis;
};
```

## 解法 2: 布赖恩·克尼根算法（推荐）

我也是看了官方的题解才知道这算法竟然有名字（震惊），它用于快速判断二进制中有多少个 1。它是借助 `num & (num - 1)` 来直接去除 num 的二进制中最右边的 1。

相较于普通移位判断，布赖恩·克尼根算法是高效的：它直接跳过了二进制中的 0，有多少个 1 就判断多少次。

在使用布赖恩·克尼根算法之前，需要借助 `^` 运算，让不同的位变 1，相同的位变 0。最后再统计二进制中有多少 1 即可。

代码实现如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/hamming-distance/
// 原文地址：https://xxoo521.com/2020-03-04-hamming-distance/
/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var hammingDistance = function(x, y) {
    let v = x ^ y; // 异或：相同位为0，不同位为1
    let dis = 0;
    while (v) {
        v = v & (v - 1);
        ++dis;
    }
    return dis;
};
```

**注意**：这种思路在[《剑指 offer - 二进制中 1 的个数》](https://xxoo521.com/2019-12-31-number-of-one/)中也有应用。

## 更多资料

**若有错误，欢迎指正。若对您有帮助，请给个「关注+点赞」，您的支持是我更新的动力** 👇

-   **📖Blog：[剑指 Offer + Leetcode 题解](https://xxoo521.com/algorithm/)**
-   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
-   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
