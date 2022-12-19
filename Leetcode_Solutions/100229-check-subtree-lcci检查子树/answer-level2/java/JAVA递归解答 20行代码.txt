### 解题思路
要标识t2第一个节点匹配要标识，因为在第一个节点未匹配时，往上传输返回值时，是自己的左子树和右子树中有一个返回为true；该节点向上返回true;而当第一个节点匹配上后，要自己左右节点全部完全匹配，才能返回true
### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    private boolean flag =false; 
    public boolean checkSubTree(TreeNode t1, TreeNode t2) {//这里要迭代的去核实当前节点和所需要核实的节点是否一样
    if(t1==null&&t2==null){//空指针匹配上，一直匹配到空指针也全匹配上
        return true;
    }
    if(t1==null||t2==null){
        return false;
    }
    if(t1.val==t2.val){
        if(!flag){
            flag =true;
        }
        return checkSubTree(t1.left,t2.left)&&checkSubTree(t1.right,t2.right);//当前节点合格，看是否子树合格
    }
    if(!flag){//t2第一个未匹配上，继续左右去匹配第一个
        return checkSubTree(t1.left,t2)||checkSubTree(t1.right,t2);
    }else{//第一个已经匹配上了,有任何一个没匹配上 都应该返回false    
        return false;
    }
    }
}
```