![稿定设计导出-20200322-162631.png](https://pic.leetcode-cn.com/0f66a1ffa928fd6ef335c98f665f30edc1ca6c873cba21c8a05a1a4ae66f7f88-%E7%A8%BF%E5%AE%9A%E8%AE%BE%E8%AE%A1%E5%AF%BC%E5%87%BA-20200322-162631.png)

# 十进制转二进制
这是最简单的思路。但是时间复杂度是O(n^2)

```
/**
 * @param {number} num
 * @return {number[]}
 */
var countBits = function(num) {
    let result = [0];
    for (let i = 1; i <= num; i++) {
        let count = 0;
        let n = i;
        while (n) {
            count += n % 2; 
            n = n >> 1;
        }
        result[i] = count;
    }
    return result;
};
```

# 动态规划
动态规划最重要的是找出状态转移方程

十进制  =>    二进制
0      =>    0
1      =>    1
2      =>    10
3      =>    11
4      =>    100
5      =>    101
6      =>    110
7      =>    111
8      =>    1000
9      =>    1001
可以得出归纳方程，设 dp(n) 为数字n二进制中1的个数


```
/**
 * @param {number} num
 * @return {number[]}
 */
var countBits = function(num) {
    let result = [0];
    for (let i = 1; i <= num; i++) {
        if (i & 1) {
            result[i] = result[i - 1] + 1;
        } else {
            result[i] = result[i >> 1];
        }
    }
    return result;
};
```
# 更简洁的动态规划
上面的状态转移方程，其实可以转换为下面的方程。本质上还是一样的


```
/**
 * @param {number} num
 * @return {number[]}
 */
var countBits = function(num) {
    let result = [0];
    for (let i = 1; i <= num; i++) {
        result.push(result[i >> 1] + (i & 1));
    }
    return result;
};
```

******************

关注微信公众号【李一二】，看更多js算法题解。
添加微信sail19971026, 进入技术交流群。
