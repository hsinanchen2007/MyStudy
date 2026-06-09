### 解题思路
由顶至底迭代二叉树，使用offerFirst不断将底部的数据插入头部

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
import javafx.util.Pair;
class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        LinkedList<List<Integer>> list = new LinkedList<>();
        if(root == null){
            return list;
        }
        LinkedList<Pair<TreeNode,Integer>> listNodes = new LinkedList<>();
        listNodes.offer(new Pair<>(root,1));
        List<Integer> listInt = new ArrayList<>();
        int temp = 1;
        while (!listNodes.isEmpty()) {
            Pair<TreeNode, Integer> poll = listNodes.poll();
            TreeNode key = poll.getKey();
            int value = poll.getValue();
            if(temp != value){
                list.offerFirst(listInt);
                listInt = new ArrayList<>();
                temp = value;
            }
            listInt.add(key.val);
            TreeNode left = key.left;
            TreeNode right = key.right;
            if(left != null){
                listNodes.offer(new Pair<>(left,value+1));
            }
            if(right != null){
                listNodes.offer(new Pair<>(right,value+1));
            }
        }
        if(!listInt.isEmpty()){
            list.offerFirst(listInt);
        }
        return list;
    }
}
```