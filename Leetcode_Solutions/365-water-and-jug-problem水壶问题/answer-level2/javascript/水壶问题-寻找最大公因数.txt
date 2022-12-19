### 解题思路
![image.png](https://pic.leetcode-cn.com/fb0315848883bfc698379385c94e34167096c2466b50d1c1743c81ad6964d084-image.png)

不看题解`一脸懵逼`，看了[题解](https://leetcode-cn.com/problems/water-and-jug-problem/solution/hu-dan-long-wei-liang-zhang-you-yi-si-de-tu-by-ant/)`满脸懵逼`，看了[视频](https://www.youtube.com/watch?v=0Oef3MHYEC0)稍微恍然大悟；


这是视频博主给出的两个思路，画的转移路线；一个是向5倒满，一个是先向3倒满；
![image.png](https://pic.leetcode-cn.com/0a9ccf01f1d8b179a2b5154ea7cb2dc546d4b809c1db44344b62fa85060646c2-image.png)

如果有解，那么最后的点肯定会位于坐标轴最外一圈，即下面四种情况：
 - X满，y随意，即坐标轴右侧线；
 - X空，Y随意，即坐标轴左侧线；
 - Y满，x随意，即坐标轴上侧线；
 - Y空，x随意，即坐标轴下侧线；

那为什么要找最大公因数呢？根据上面描述有：ax + by = z；[贝组定理](https://baike.baidu.com/item/%E8%A3%B4%E8%9C%80%E5%AE%9A%E7%90%86/5186593?fromtitle=%E8%B4%9D%E7%A5%96%E5%AE%9A%E7%90%86&fromid=5185441)  

假设存在公因数K, 使得: x = i * k; y = j * k;
则上面的方程可以转换为：a * i * k + b * i * k = k * (a*i + b*j) = k * (c + d) = z; 即只需要k 同时也是 z的约数，就证明a和不是存在的；所以：
 - 第一步找x, y的最大公因数k；
 - 第二步判断k 是否也是z的约数；

### 代码

```javascript
/**
 * @param {number} x
 * @param {number} y
 * @param {number} z
 * @return {boolean}
 */
var canMeasureWater = function(x, y, z) {
    if (z === 0) {
        return true;
    }
    // 以题目要求，只有两个桶，如果相加很不到目标值，那么肯定无解
    if (x + y < z) {
        return false;
    }

    let big = Math.max(x, y);
    let small = Math.min(x, y);
    // 如果small为0，那么就只有看其中另一个容器是否是目标值的因数
    if (small === 0) {
        return z % big === 0;
    }
    // 寻找最大公因数；
    while (big % small !== 0) {
        let temp = small;
        small = big % small;
        big = temp;
    }

    return z % small === 0;
};
```