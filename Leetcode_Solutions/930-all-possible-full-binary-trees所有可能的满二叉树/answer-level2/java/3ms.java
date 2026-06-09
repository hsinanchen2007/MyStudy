### 解题思路
注释

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
    public List<TreeNode> allPossibleFBT(int N) {
        if ((N&1)==0)//N为偶数不可能满二叉树
            return new ArrayList<>(0);
        List<TreeNode> list =new ArrayList<>();
        if (N==1) {//N为1返回当前节点
            list.add(new TreeNode(0));
            return list;
        }
        --N;//N的值应减一，因为去掉了根节点
        for (int i=1;i<N;i+=2){//i为N重分给左节点的节点数，每次加2因为每次向下分配都要多两个节点
            List<TreeNode> left=allPossibleFBT(i);//这里list存着分配i个节点后的左节点的所有情况list
            List<TreeNode> right=allPossibleFBT(N-i);
            for (TreeNode nodeL:left){
                for (TreeNode nodeR:right){//双重循环，分别把左右节点的各种情况赋予根节点的左右节点，并存储
                    TreeNode root=new TreeNode(0);
                    root.left=nodeL;
                    root.right=nodeR;
                    list.add(root);
                }
            }
        }
        return list;
    }
}
```