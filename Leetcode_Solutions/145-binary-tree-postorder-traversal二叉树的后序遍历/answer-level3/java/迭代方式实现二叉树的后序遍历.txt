### 解题思路
后序遍历实现相对前序遍历,中序遍历稍微有点复杂度,大家看图了解一下,后序遍历是先左，再右,最后是根节点
这里借助栈实现,关键点在于父节点和右子节点顺序问题,需要引入一个属性表示右子节点是否已经访问过
这里需要辅助的来判断一个节点的右节点是否已经在访问过，定义了Pair,附加一个布尔类型的数据来代表该节点的右节点是否已经访问过了
![tree遍历方式.jpg](https://pic.leetcode-cn.com/84fede9f0ad17db6dc88144364a7c61c2b0434f394e31fc57c3a48ef2563558a-tree%E9%81%8D%E5%8E%86%E6%96%B9%E5%BC%8F.jpg)
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
class Pair{
    private TreeNode curNode;
    private boolean isBacktrack;
    public Pair(TreeNode node, boolean isBacktrack){
        this.isBacktrack=isBacktrack;
        this.curNode=node;
    }
    public boolean isBacktrack() {
        return isBacktrack;
    }

    public TreeNode getCurNode() {
        return curNode;
    }

    public Pair setBacktrack() {
        isBacktrack =!isBacktrack;
        return this;
    }
}
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        Stack<Pair> stack=new Stack<>();
        List<Integer> traversal = new ArrayList<>();
        TreeNode cur=root;
        while (cur!=null||!stack.isEmpty()){

            if(cur!=null){
                stack.push(new Pair(cur,false));
                cur=cur.left;
            }else {
                Pair pair=stack.pop();
                cur=pair.getCurNode();
                /**
                当一个节点的右节点为null时,说明到该节点访问结束,继续回退,
                或者该节点的右节点不为null,并且已经访问过了,此时也要回退*/
                if(cur.right==null||pair.isBacktrack()){
                    traversal.add(cur.val);
                    cur=null;
                    continue;
                }
                /**
                   此时右节点不为null时候,cur节点要等要右节点结束才能,这时候需要设置可以回退,
                   以为这下次再出现该节点时,直接判断isBacktrack,就可以知道该节点的右节点是否已经访问过了。
                */
                if(cur.right!=null){
                    stack.push(pair.setBacktrack());
                    cur=cur.right;
                }
            }
        }
        return traversal;
    }
}
```