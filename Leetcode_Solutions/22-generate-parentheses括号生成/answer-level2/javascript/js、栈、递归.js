### 解题思路
使用栈和递归，记录剩余的左括号和待匹配的左括号即可
![image.png](https://pic.leetcode-cn.com/79efd56f4374e6d54b9a7267ea8aa73b69f34de737a6e6d08e26c0967d12a9b4-image.png)
应该还可以用剪枝、栈代替递归优化
### 代码

```javascript
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    let res = [];
    function digui(stack, leftNum, str) {
        if (stack < 0 || leftNum < 0) return;
        if (stack === 0 && leftNum === 0) {
            res.push(str);
            return;
        }
        digui(stack - 1, leftNum, str+')');
        digui(stack + 1, leftNum - 1, str + '(');
    }
    digui(0, n, '');
    return res;
};
```