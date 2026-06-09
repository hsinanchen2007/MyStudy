```
var constructMaximumBinaryTree = function(nums) {
    if (!nums.length) return null;
    let max = Math.max(...nums);
    let index = nums.indexOf(max);
    let root = new TreeNode(max);
    let buildTree = (node, index, arr) => {
        if (arr.length === 1) return;

        let lArr = index === 0 ? []: arr.slice(0, index);
        if (lArr.length){
            let lmax = Math.max(...lArr);
            let lindex = lArr.indexOf(lmax);
            let lNode = new TreeNode(lmax);
            node.left = lNode;
            buildTree(node.left, lindex, lArr);
        }

        let rArr = index === arr.length - 1 ? []: arr.slice(index + 1);
        if (rArr.length){
            let rmax = Math.max(...rArr);
            let rindex = rArr.indexOf(rmax);
            let rNode = new TreeNode(rmax);
            node.right = rNode;
            buildTree(node.right, rindex, rArr);
        }
    };
    buildTree(root, index, nums);
    return root;
};
```

前端算法库：https://github.com/cunzaizhuyi/js-leetcode  
这里记录了我刷过的近500道LeetCode的题解，