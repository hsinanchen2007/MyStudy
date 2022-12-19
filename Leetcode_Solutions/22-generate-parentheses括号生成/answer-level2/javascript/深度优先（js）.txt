### 解题思路
![微信截图_20200408104750.png](https://pic.leetcode-cn.com/56eeffa87727ac44e06da73881bf9373f5182988f1955ce6bf381382bab4120c-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200408104750.png)


### 代码

```javascript
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    let res = [];
    /**
     * 递归 生成有效括号
     * @param {number} n 生成括号的对数
     * @param {string} temp 生成括号的模板
     * @param {number} left 生成括号的左侧起始位置，默认值0
     * @param {number} right 生成括号的右侧起始位置，默认值0
     * @return {string}
     */
    function creatBrackets ( n, temp, left, right) {
        left = left || 0;
        right = right || 0;
        if (left == n && right == n) {
            return res.push(temp);
        }
        left < n && creatBrackets (n, temp + '(', left+1, right);
        right < left && creatBrackets (n, temp + ')', left, right+1);
    }
    creatBrackets(n, '');
    return res;
};

```