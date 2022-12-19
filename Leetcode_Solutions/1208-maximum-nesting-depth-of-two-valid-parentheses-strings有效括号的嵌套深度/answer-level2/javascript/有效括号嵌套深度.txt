![sendpix2.jpg](https://pic.leetcode-cn.com/6450758be7012c842e813b517688159a54cef69577ea04f3b614283e951f5d68-sendpix2.jpg)

思路
    利用出入栈思想，由左到右一次遍历，且记录当前栈深度，即为嵌套深度
    将奇数深度和偶数深度分为两组即为题解

```
/**
 * @param {string} seq
 * @return {number[]}
 */
var maxDepthAfterSplit = function(seq) {
    let arr = [];
    let count = 0;
    for (let index in seq) {
        if (seq[index] === '(') {
            count++;
            arr.push(count%2);
        } else {
            arr.push(count%2);
            count--;
        }
    }
    return arr;
};
```
