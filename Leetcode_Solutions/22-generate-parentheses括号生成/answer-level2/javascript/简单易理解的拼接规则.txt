### 解题思路
见备注即可。
每个位置添加的括号，只要满足他前面的左括号数量不小于右括号就行。
最后一个括号肯定是右括号；

### 代码

```javascript
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    const result = [];
    // 获取拼接规则
    function getRule (n, front) {
        let leftLength = 0;
        let rightLength = 0;
        for (let i = 0; i < front.length; i++) {
            if (front[i] === '(') {
                leftLength++;
            } else {
                rightLength++;
            }
        }
        // 右括号全部用完，表示结束
        if (rightLength === n) {
            result.push(front);
            return;
        }
        // 从左往右拼接时，做括号数量必须大于右括号
        if (leftLength > rightLength) {
            // 左括号时没用完时，才可以继续添加左括号
            if (leftLength < n) {
                getRule(n, front + '(');
            }
            getRule(n, front + ')')
        }
        // 左右括号数量相等时，只能拼右括号
        if (leftLength === rightLength) {
            getRule(n, front + '(');
        }
    }
    getRule(n, '');
    return result;
};
```