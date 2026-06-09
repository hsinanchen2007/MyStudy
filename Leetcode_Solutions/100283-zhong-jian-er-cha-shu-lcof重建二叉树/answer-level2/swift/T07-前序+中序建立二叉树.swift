### 解题思路
对inorder进行一次遍历即可,然后利用递归获取root的左右节点。

### 代码

```swift
class Solution {
    func buildTree(_ preorder: [Int], _ inorder: [Int]) -> TreeNode? {
        if preorder.count == 0 || inorder.count == 0 {
            return nil
        }
        
        //构建二叉树根结点
        let root: TreeNode? = TreeNode.init(preorder[0])
        
        //对中序序列进行遍历
        for (index, num) in inorder.enumerated() {
            // 如果找到根节点
            if num == preorder[0] {
                root?.left = buildTree(
                                Array(preorder[1..<index+1]),
                                Array(inorder[0..<index])
                            )
                root?.right = buildTree(
                                Array(preorder[index+1..<preorder.endIndex]), 
                                Array(inorder[index+1..<inorder.endIndex])
                            )
            }
        }
        
        return root
        
    }
}
```