不是很理解不使用额外空间是什么意思？存答案的数组还是需要的吧，临时几个变量也是需要的吧，那就没啥问题。
其实就是如果当前数的数量比之前的最大数量大，那就清空数组，塞进当前数。如果和最大值一样，就追加数组
```
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var findMode = function(root) {
    let ans = [], maxCount = 0, count = 0, last = null;
    search(root);
    function search(node) {
        if (node === null) {
            return;
        }
        search(node.left);
        if (last === node.val) {
            count++;
        } else {
            count = 1;
        }
        if (maxCount === count) {
            ans.push(node.val);
        } else if (maxCount < count) {
            ans = [node.val];
            maxCount = count;
        }
        last = node.val;
        search(node.right);
    }
    return ans;
};
```
