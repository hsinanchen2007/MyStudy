### 解题思路
本来这道题我也不会，尝试了很多方法，但是题解才知道，原来还有深度优先搜索（DFS）和广度优先搜索（BFS）。
理解+记忆，写出了这道题。
希望再次遇到类似的问题，自己能独立解出来
通过这几次打卡的总结：类型二维数组遍力的，一般用广度优先搜索；类似分情况的，比如可能出画二分树结构的，一般用深度搜索。
### 代码

```javascript
/**
 * @param {number} n
 * @return {string[]}
 * 之前做过一个机器人移动的题，用到的就是广度优先搜索（BFS）+剪枝
 * 这道题用到的是深度优先搜索（DFS）+剪枝
 * 对象的深拷贝，用到的也是DFS
 */

var generateParenthesis = function (n) {
    let result = [];
    /**
     * @params {number} left 字符串中左括号的数量
     * @params {number} right 字符串中右括号的数量
     */
    function generate(str, left, right) {
        if (str.length === n * 2) {
            result.push(str);
            return;
        }
        if (left < n) {
            generate(`${str}(`, left + 1, right);
        }
        if (left > right) {
            generate(`${str})`, left, right + 1)
        }
    }

    generate('', 0, 0);

    return result;
};
```