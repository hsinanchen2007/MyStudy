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
class Solution {
    public static int kthLargest(TreeNode root, int k) {
        List<Integer> list = new ArrayList<>();
        find(root,k,list);
        //System.out.println(list.toString());
        return list.get(k - 1);
    }

    public static void find(TreeNode root, int k, List<Integer> list) {
        if (root == null) return;
        find(root.right, k, list);
        if(list.size() >= k){
            return;
        }
        list.add(root.val);
        find(root.left,k,list);
    }
}
```