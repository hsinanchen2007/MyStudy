```
/**
 * 问题的本质即是怎样将 n 个左括号和 n 个右括号填充到 2n 个空间中 
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    let list = [];
    _gen(0, 0, n, '');
    return list;

    /**
     * left: 左边的括号使用
     */
    function _gen (left, right, n, result) {
        if (left === n && right === n) {
            list.push(result);
            return;
        }

        // 左括号可以无限制的放
        if (left < n) {
            _gen(left + 1, right, n, result + '(');
        }

        // 放置右括号时，一定要保证当前排列中左括号的数量大于右括号
        if (left > right && right < n) {
            _gen(left, right + 1, n, result + ')');
        }
    }
};
```
