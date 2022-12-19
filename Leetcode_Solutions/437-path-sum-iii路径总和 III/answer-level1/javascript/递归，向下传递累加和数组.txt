### 代码
每到一个深度为N的节点时，会计算N次，并向下传递长度为N+1的数组

```javascript
var pathSum = function(root, sum) {
    if(!root) {
        return 0
    }
    const num = []
    if(root.val === sum) {
        // 最后获取的是num的长度，传值不重要
        num.push('')
    }
    RecursiveFunc(root.left, sum, num, [root.val])
    RecursiveFunc(root.right, sum, num, [root.val])
    return num.length
};

function RecursiveFunc(node, sum, num, parentSumArr) {
    if(!node) {
        return
    }
    if(node.val === sum) {
        num.push('')
    }
    for(let i = 0; i<parentSumArr.length; i++) {
        if(parentSumArr[i] + node.val === sum) {
            num.push('')
        }
        parentSumArr[i] = parentSumArr[i] + node.val
    }
    parentSumArr.push(node.val)
    RecursiveFunc(node.left, sum, num, [].concat(...parentSumArr))
    RecursiveFunc(node.right, sum, num, [].concat(...parentSumArr))
}
```