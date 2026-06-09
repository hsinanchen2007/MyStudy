1. 找到最大值的index和value，使用Max类型存放返回数据
2. 分割并遍历左右子树
3. 注意：如果左右子树不存在，记得返回一个null节点，不然不能通过leetcode的编译
```javascript
const constructMaximumBinaryTree = function(nums) {
    if(!nums.length) return null;
    let max = findMax(nums);
    
    let node = new TreeNode(max.val);
    let left = nums.slice(0, max.idx);
    let right = nums.slice(max.idx+1);

    node.left = constructMaximumBinaryTree(left);
    node.right = constructMaximumBinaryTree(right);
    return node;
};

class Max{
    constructor(val, idx) {
        this.val = val;
        this.idx = idx;
    }
}

const findMax = function(nums) {
    if(!nums.length) return;
    let max = new Max(0,0);
    nums.forEach((el,idx)=> {
        if(el>max.val) {
            max.val = el;
            max.idx = idx;
        }
    })
    return max;
}
```