```

var sumOfLeftLeaves = function(root) {
    if(!root) return 0;
    let sum = 0;


    let fn = (curNode) => {
        if(curNode.left && (!curNode.left.left && !curNode.left.right)){
            sum += curNode.left.val;

        }
        if(curNode.left){
            fn(curNode.left)
        }
        if(curNode.right){
            fn(curNode.right)
        }
    }
    fn(root)
    return sum;
};
```

我的前端算法库：https://github.com/cunzaizhuyi/js-leetcode