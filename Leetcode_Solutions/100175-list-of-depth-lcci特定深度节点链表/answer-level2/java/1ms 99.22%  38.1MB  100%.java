### 解题思路
此处撰写解题思路

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
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<ListNode> res = new ArrayList<>();
    public ListNode[] listOfDepth(TreeNode tree) {
        inorder(tree, 0);
        ListNode[] arrays = new ListNode[res.size()];
        for(int i = 0; i < arrays.length; i++){
            arrays[i] = res.get(i);
        }
        return arrays;
    }
    
    public void inorder(TreeNode tree, int level){
        if(tree == null)
            return;
        
        if(res.size() <= level){
            res.add(new ListNode(tree.val));
        }else {
            ListNode tmp = res.get(level);
            while(tmp.next != null){
                tmp = tmp.next;
            }
            tmp.next = new ListNode(tree.val);
        }
        
        inorder(tree.left, level + 1);
        inorder(tree.right, level + 1);
    }
    
}
```