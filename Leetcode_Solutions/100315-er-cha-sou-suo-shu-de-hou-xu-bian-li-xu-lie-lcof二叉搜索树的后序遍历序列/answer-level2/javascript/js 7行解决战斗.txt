7行解决战斗
```js
/**
 * @param {number[]} postorder
 * @return {boolean}
 */
var verifyPostorder = function(postorder) {
    if (!postorder.length) return true;
    const top = postorder.pop();
    let i = postorder.length;
    while(postorder[i - 1] > top) i--;
    const left = postorder.slice(0, i);
    if (left.some(i => i > top)) return false;
    return verifyPostorder(left) && verifyPostorder(postorder.slice(i));
};
```
