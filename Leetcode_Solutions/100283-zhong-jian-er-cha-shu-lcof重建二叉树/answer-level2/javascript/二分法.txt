### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {number[]} preorder
 * @param {number[]} inorder
 * @return {TreeNode}
 */
var buildTree = function(preorder, inorder) {
    // 过滤
    if(!preorder.length || !inorder.length){
        return null
    }

    // 根据先序排序：根左右
    //所以根就preorder第一个
    const rootValue = preorder[0];
    // 根据中序排序 ：左根右
    //找出根值的下标，进行划分左右区间
    let rootValueIndex = inorder.indexOf(rootValue);
    // 构建树
    const root = new TreeNode(rootValue);
    // 构建左右
    // 根据先序排序：根左右
    //第一个参数：
    //preorder第二个元素是左区的第一个根节点,所以从第二个元素截取到 根植的下标（1，根植）。之所以+1。是因为slice特性的原因（包左不包右）
    //然后inorder左边就是0到根植的下标，取左期间
    root.left = buildTree(preorder.slice(1,rootValueIndex+1),inorder.slice(0,rootValueIndex))
    //然后preorder截取根值之后，所以+1，第二个参数就是拿inorder右区间
    root.right = buildTree(preorder.slice(rootValueIndex+1),inorder.slice(rootValueIndex+1));
    return root
};
```