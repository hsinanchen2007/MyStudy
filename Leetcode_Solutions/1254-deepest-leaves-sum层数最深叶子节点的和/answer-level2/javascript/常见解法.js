### 解题思路
## 题目
给你一棵二叉树，请你返回层数最深的叶子节点的和。

 

示例：
      1
     / \
    2   3
   / \   \
  4   5   6
 /         \
7           8

输入：root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
输出：15
 

提示：

树中节点数目在 1 到 10^4 之间。
每个节点的值在 1 到 100 之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/deepest-leaves-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

## 思路
dfs 前序遍历 获取深度
dfs 前序遍历 获取总和

## 测试用例
[1,2,3,4,5,null,6,7,null,null,null,null,8]
[]
[7]
[3,4,7,5,null,null,8,6,null,null,9]
[3,4,9,null,5,10,11,6,7,null,null,13,12,null,null,null,8,null,14,null,16,null,null,null,15]

### 代码

```javascript
/**
 * @param {TreeNode} root
 * @return {number}
 */
var deepestLeavesSum = function(root) {
  console.log(root)
  let len = getTreeDepth(root);
//   console.log(`len: ${len}`)
//   console.log(root);
  let sum = getTreeDepthSum(root, 1, len);
//   console.log(`sum: ${sum}`)
  return sum;
};

/**
 * 
 * @param {*} root
 * @returns {number}
 */
var getTreeDepth = function(root) {
  if(root === null) 
    return 0;
  return Math.max(getTreeDepth(root.left), getTreeDepth(root.right)) + 1;
}

var getTreeDepthSum = function(root, dep, len) {
  if (root === null)
    return 0;
  if (dep === len && root !== null) {
    return root.val;
  }
  return getTreeDepthSum(root.left, dep + 1, len) + getTreeDepthSum(root.right, dep + 1, len);
}
```