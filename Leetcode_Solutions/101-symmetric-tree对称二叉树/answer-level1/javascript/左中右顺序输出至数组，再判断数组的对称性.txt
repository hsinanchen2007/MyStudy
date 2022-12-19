效率肯定不是很好，但是逻辑也比较直观。<br>
体现了将问题转化为已解决问题的思路。<br>
致命缺点是二叉树节点特别多的时候,要先把整个二叉树转换为数组。<br>
例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
```
    1
   / \
  2   2
 / \ / \
3  4 4  3
```

按照左中右的顺序输出至数组是，[3,2,4,1,4,2,3],这时数组也是对称的。<br>
为了去除巧合情形，可以使用 节点值，层数 的形式；<br>
输出 ["3,3", "2,2", "4,3", "1,1", "4,3", "2,2", "3,3"];<br>
例如：
 
```
    1
   / \
  2   2
 /   / 
2    2 
```
不加层数输出的是[2,2,1,2,2]，数组是对称的;<br>
加上层数输出为["2,3", "2,2", "1,1", "2,3", "2,2"],数组就不是对称的了。<br>
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
 * @return {boolean}
 */
var isSymmetric = function (root) {
    if (root == null) {
        return true;
    }
    //左中右顺序递归二叉树
    var nums = [];
    search(nums, root, 1);
    //判断是否对称
    var i = 0, j = nums.length - 1;
    while (i < j) {
        if (nums[i] != nums[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
};
/**
 * 按照左中右顺序递归二叉树，输出至数组nums中
 * @param nums      输出
 * @param n         节点
 * @param k         层次
 */
function search(nums, n, k) {
    //左边
    if (n.left != null) {
        search(nums, n.left, k + 1);
    }
    //节点值，层次
    nums.push(n.val + ',' + k);
    //右边
    if (n.right != null) {
        search(nums, n.right, k + 1);
    }
}
```
