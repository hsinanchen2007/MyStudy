/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/24
 *
 * 解题思路: 二叉树的遍历和比骄傲
 *
 */
```
     //遍历s 每到一个节点就比较 s t
    public boolean isSubtree(TreeNode s, TreeNode t) {

        //s 为空的话 s t不相同
        if(s == null){
            return false;
        }

        //s t 相同返回true
        if(InOrder(s,t)){
            return true;
        }

        //s t 不相同继续寻找
        boolean a = isSubtree(s.left,t);
        boolean b = isSubtree(s.right,t);

        //s 的一个子树和t 相同返回true
        return a||b;
    }

    //判断两个树是否相同
    public boolean InOrder(TreeNode s, TreeNode t){

        //都为空 相同
        if(s == null && t == null) return true;
        //不相同
        if(s == null || t == null) return false;
        if(s.val != t.val){
            return false;
        }

        //左右子树递归
        boolean l = InOrder(s.left,t.left);
        boolean r = InOrder(s.right,t.right);

        //两个子树相同
        if(l && r){
            return true;
        }
        //不相同
        return false;
    }
```