### 代码

```javascript
var isBalanced = function(root) {
    return judge(root) !== -1
};

const judge = (root) => {
    if(root == null){
        return 0
    }
    let left = judge(root.left);
    if(left === -1){
        return -1
    }
    let right = judge(root.right);
    if(right === -1){
        return -1
    }
    return Math.abs(left - right) > 1 ? -1 : Math.max(left, right) + 1
}
```