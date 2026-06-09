```java
public TreeNode deleteNode(TreeNode root, int key) {
    TreeNode parent = null;
    TreeNode curr = root;
    // 查找待目标结点
    while (curr != null && curr.val != key) {
        parent = curr;
        curr = (curr.val > key) ? curr.left : curr.right;
    } 
    // 如果待删除的元素存在
    if (curr != null) {
        // 判断其是否有孩子
        // 目标结点有两个子结点，则找到目标结点的前驱(或后继)的值替代，并删除此前驱(或后继)结点
        /* 本处以后继结点替换 */
        if(curr.left != null && curr.right != null){  
            TreeNode successor = curr;
            // 以下方法并非查找某结点后继结点的完整方法(以下方法没有考虑其没有右子树的情况)
            parent = curr;
            successor = curr.right;
            // 获取目标结点的后继结点及其父结点
            while (successor.left != null) {
                parent = successor;
                successor = successor.left;
            }
            // 将后继结点的值赋给目标结点
            curr.val = successor.val;
            // 然后将后继结点作为目标结点(因为后继结点没有左子树，
            // 所以问题转化为删除有一个子结点或没有子结点的结点的问题)
            curr = successor;          
        }
        // 获取目标结点的子结点(有可能为空结点)
        TreeNode child = (curr.left == null) ? curr.right : curr.left;
        // 判断其是否为根结点，若为根结点(且只有一个子结点(可能为空))，直接用子结点替换根结点
        if (parent == null) {
            root = child;
        } 
        // 若不为根结点，则将目标结点的父结点的相应链接指向该子结点
        else {
            if (parent.left == curr) {
                parent.left = child;
            } else {
                parent.right = child;
            }
        }      
        // help GC
        curr = null;       
    }
    return root;
}
```
