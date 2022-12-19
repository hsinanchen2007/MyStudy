### 解题思路
根据[精选题解](https://leetcode-cn.com/problems/generate-parentheses/solution/hui-su-suan-fa-by-liweiwei1419/)写的JavaScript版动态规划版的题解。

### 代码

```javascript
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function (n) {
    // 动态规划方法
    if (n === 0) {
        return [];
    }

    // 第一个括号一定时左括号'('
    // 所有的可能性一定是( + 'dp[j]' + ) + 'dp[i-j-1]'
    // j从0开始，最多不超过i-1，那么右边的可能性就是i-j-1，因为两边相加一定等于i-1
    // 最终的结果n，可以在n-1的基础上得出来的
    // 于是用result数组来存放0-n每个数对应的结果，最终取result[n]
    const result = [];
    // n=0时结果就是空数组
    result[0] = [''];

    for (let i = 1; i <= n; i++) {
        // 将1到n对应的方案都列出来
        const cur = [];
        for (let j = 0; j < i; j++) {
            // 遍历，在n=i-1的基础上得出n=i情况下的所有方案
            const str1 = result[j];
            const str2 = result[i - j - 1];
            str1.forEach((s1) => {
                str2.forEach((s2) => {
                    const curStr = '(' + s1 + ')' + s2;
                    cur.push(curStr);
                })
            })
        }
        result.push(cur);
    }

    return result[n];
};


```