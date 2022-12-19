    
![image.png](https://pic.leetcode-cn.com/cebf7905099738d14e1e5d79dc5c06069befeab4bcbe9328d8aba02abefc67f9-image.png)

public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        TreeNode node;
        if(t1!=null&&t2!=null){
            node = new TreeNode(t1.val+t2.val);
            node.left = mergeTrees(t1.left,t2.left);
            node.right = mergeTrees(t1.right,t2.right);
        }else if(t1!=null){
            node = t1;
        }else if(t2!=null){
            node = t2;
        }else{
            return null;
        }
        return node;
    }