### 解题思路
flag为true时：
    表示从头部取数据(pollFirst),而下一轮的数据得正序(左->右)添加到尾部(addLast),因为下一轮数据从尾部取，并且得逆序出来。
flag为flase时：
    表示从尾部取数据(pollLast),而下一轮的数据得逆序(右->左)添加到头部(addFirst),因为下一轮数据从头部取，并且得顺序出来。

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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> resList = new ArrayList<>();
        if(root == null) return resList;
        List<Integer> innerList = new ArrayList<>();
        //创建双向队列
        LinkedList<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        boolean flag = true;
        while(!queue.isEmpty()){
            int size = queue.size();
            for(int i=0;i < size;i++){
                TreeNode node = flag?queue.pollFirst():queue.pollLast();
                innerList.add(node.val);
                if(flag){
                    if(node.left != null) queue.addLast(node.left);
                    if(node.right != null) queue.addLast(node.right);
                }else{
                    if(node.right != null) queue.addFirst(node.right);
                    if(node.left != null) queue.addFirst(node.left);
                }
            }
            resList.add(new ArrayList<>(innerList));
            innerList.clear();
            flag = !flag;
        }
        return resList;
    }
}
```