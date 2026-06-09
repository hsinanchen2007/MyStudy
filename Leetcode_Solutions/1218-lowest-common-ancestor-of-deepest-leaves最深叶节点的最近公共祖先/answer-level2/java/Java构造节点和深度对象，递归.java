![image.png](https://pic.leetcode-cn.com/7b9264ab5478592e6b8669c5935901cd12c9a74c31a72e27ff0ddf66f7f910f2-image.png)
思路：
构造一个节点和高度值的对象，遍历到最后，判断左右获取到的节点对象的高度，左右都不为null的话，则此时需要取祖先节点返回，此时需要设置祖先节点高度为最深叶节点深度。
如果左右节点中有为空的，则左边为null返回右边，右边为null返回左边，都为null则返回自身。
```java
class ANode {
        TreeNode node;
        int dep;

        public ANode(TreeNode node, int dep) {
            this.node = node;
            this.dep = dep;
        }
    }

    public TreeNode lcaDeepestLeaves(TreeNode root) {
        if (root == null) return null;
        // 返回节点
        return helper(new ANode(root,0)).node;
    }

    // 找到左边的最深节点父节点，找到右边最深节点父节点，如果左右深度相同
    // 返回跟节点
    public ANode helper(ANode aNode) {
        if (aNode.node == null) return null;
        // 左右深度优先搜索
        ANode leftNode = helper(new ANode(aNode.node.left, aNode.dep + 1));
        ANode rightNode = helper(new ANode(aNode.node.right, aNode.dep + 1));
        // 如果左右都不为空，判断左右高度，高度相同
        // 返回祖先节点，同时让祖先节点告诉为子节点深度
        if(leftNode != null && rightNode != null){
            if(leftNode.dep > rightNode.dep){
                return leftNode;
            }else if(leftNode.dep < rightNode.dep){
                return rightNode;
            }else{
                aNode.dep = leftNode.dep;
                return aNode;
            }
        }
        // 左边为空，返回右边
        if(leftNode == null && rightNode != null){
            return rightNode;
        }
        // 右边为空，返回左边
        if(rightNode == null && leftNode != null){
            return leftNode;
        }
        // 直接返回根节点
        return aNode;
    }
```