矩形层次遍历其实只是在遍历的基础上进行了方形的判断。
当从左向右，只需要将层次遍历从0->n-1即可，当从右向左的时候从n-1 -> 0，然后添加到数组的时候，每次进行insert到索引0️⃣，这样子数组存储的node也是按照从左→右的顺序。

java 速度超过100%

[github leetcode 各种题解 欢迎start 欢迎交流](https://github.com/ifgyong/leetCode/wiki/%5Bleetcode--0103%5D%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E9%94%AF%E9%BD%BF%E5%BD%A2%E5%B1%82%E6%AC%A1%E9%81%8D%E5%8E%86)

```
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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
                List<List<Integer>> ret = new ArrayList<>();
        boolean toRight = false;
        if (root == null)return ret;
        List<Integer> top = new ArrayList<>();
        top.add(root.val);
        ret.add(top);
        List<TreeNode> nodes = new ArrayList<>();
        nodes.add(root);
        while (nodes.size()>0){
            List<TreeNode> subNodes = new ArrayList<>();
            List<Integer> subInt = new ArrayList<>();
            if (toRight){
                for (int i = 0; i < nodes.size(); i++) {
                    TreeNode n = nodes.get(i);
                    if (n.left != null){
                        subNodes.add(n.left);
                        subInt.add(n.left.val);
                    }
                    if (n.right != null){
                        subNodes.add(n.right);
                        subInt.add(n.right.val);
                    }

                }
                nodes = subNodes;
            }else {
                for (int i = nodes.size()-1; i > -1; i--) {
                    TreeNode n = nodes.get(i);
                  if (n.right != null){
                        subNodes.add(0,n.right);
                        subInt.add(n.right.val);
                    }

                    if (n.left != null){
                        subNodes.add(0,n.left);
                        subInt.add(n.left.val);
                    }
                }
                nodes = subNodes;
            }
            if (subInt.size()>0) ret.add(subInt);//添加一层的int
            toRight = !toRight;
        }
        return ret;
    }
}
```