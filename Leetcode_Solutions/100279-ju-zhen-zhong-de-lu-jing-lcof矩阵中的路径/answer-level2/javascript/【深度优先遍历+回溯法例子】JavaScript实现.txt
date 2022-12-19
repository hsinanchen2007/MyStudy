
## 解法：深度优先遍历 + 回溯

准备两个函数`exist()` 和 `__exist()`。

`exist()` 用于循环遍历网格，当前元素等于单词的第一个字母时，进入 `__exist()` 函数。代码实现如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/word-search/
// 原文地址：https://xxoo521.com/2020-02-17-word-search/

/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var exist = function(board, word) {
    const rowNum = board.length;
    const colNum = board[0].length;

    for (let i = 0; i < rowNum; ++i) {
        for (let j = 0; j < colNum; ++j) {
            if (board[i][j] === word[0]) {
                const isExist = __exist(board, word, i, j, {});
                if (isExist) return true; // 找到就返回
            }
        }
    }
    return false;
};
```

`__exist()` 函数是从指定位置开始，按照“上下左右”四个方向递归遍历，直到找到/找不到所有匹配的字母为止。代码实现如下：

```javascript
/**
 * @param {character[][]} board
 * @param {string} word
 * @param {number} row
 * @param {number} col
 * @param {object} visited
 * @return {boolean}
 */
function __exist(board, word, row, col, visited) {
    // 单词中字母全部匹配，说明可以搜索到，返回true
    if (!word.length) {
        return true;
    }

    const key = `${row}-${col}`;
    // 越界、之前访问过、单词首字母和当前元素不相同，返回false
    if (
        row >= board.length ||
        row < 0 ||
        col >= board[0].length ||
        col < 0 ||
        visited[key] ||
        board[row][col] !== word[0]
    ) {
        return false;
    }

    visited[key] = true;
    word = word.slice(1);
    // 下、上、右、左搜索（顺序不重要）
    const success =
        __exist(board, word, row + 1, col, visited) ||
        __exist(board, word, row - 1, col, visited) ||
        __exist(board, word, row, col + 1, visited) ||
        __exist(board, word, row, col - 1, visited);

    // success为false时，就是回溯
    visited[key] = success;
    return success;
}
```

代码中如果 success 为 false，说明以当前元素为出发点，搜索剩余字母失败。那么应该将`visited[key]`重置为 false，以方面其他路径使用。

例如对于以下数组，要搜索`abbcbd`。按照代码里的方向搜索逻辑，会先找到 abbd，然后发现查找失败，此时就要回溯。否则当按照正确方向找来时，visited 中的值是错误的。

```
a b b
d b c
```

## 更多资料

-   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
-   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
-   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
