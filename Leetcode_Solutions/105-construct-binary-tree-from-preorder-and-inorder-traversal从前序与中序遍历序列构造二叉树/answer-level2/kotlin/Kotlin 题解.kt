```kotlin
private fun buildTree0(preorder: IntArray, inorder: IntArray): TreeNode? {
    if (preorder.isEmpty()) {
        return null
    }

    // 确定 root 节点
    val tree = TreeNode(preorder[0])

    // 定位中序遍历中 root 节点的位置
    val rootValIndex = inorder.indexOf(tree.`val`)

    // 构建左子树, 0 表左边到头了
    if (rootValIndex != 0) {
        tree.left = buildTree0(
                preorder.sliceArray(1 until rootValIndex - 0 + 1),
                inorder.sliceArray(0 until rootValIndex)
        )
    }

    // 构建又子树, inorder.size - 1 表示右边到头了
    if (rootValIndex != inorder.size - 1) {
        tree.right = buildTree0(
                preorder.sliceArray(rootValIndex - 0 + 1 until preorder.size),
                inorder.sliceArray(rootValIndex + 1 until inorder.size)
        )
    }

    return tree
}

```
