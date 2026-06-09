- 结论
    - 维护一个单调递减的栈，以及最新pop出来的值。待push进栈的节点值必须大于已经pop出来的所有元素的值，才能是合法的BST。
- 思路
    - BST的性质是左子树小于root，右子树大于root，所以校验这个性质即可。
    - 单调递减栈的单调性用来假设root到左子树的性质正确，再用`待push进栈的节点值必须大于已经pop出来的所有元素的值`来校验root到右子树的性质
    - 得益于单调性，`已经pop出来的所有元素的值`是不断递增的，所以用最新的值来校验即可

> 时间复杂度：O(n)，每个元素最多进出栈各1次

js实现如下
```js
var verifyPreorder = function(preorder) {
    const stack = [];
    let currMax = -Infinity;
    for (let n of preorder) {
        while (stack.length && n > stack[stack.length - 1]) currMax = stack.pop();
        if (n < currMax) return false;
        stack.push(n);
    }
    return true;
};
```
