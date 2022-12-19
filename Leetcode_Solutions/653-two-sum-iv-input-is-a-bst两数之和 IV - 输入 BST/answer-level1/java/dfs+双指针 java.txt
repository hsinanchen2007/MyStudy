### 解题思路
中序遍历后就是一个递增的list,然后双指针

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
    List<Integer> arr = new ArrayList<>();

    
    public boolean findTarget(TreeNode root, int k) {
        dfs(root);
        int l=0,r=arr.size()-1;
        while(l<r){
            int val = arr.get(l)+arr.get(r);
            if(val==k) return true;
            else if(val>k) r--;
            else if(val<k) l++;
        }
        return false;
    }


    void dfs(TreeNode node){
        if(node!=null){
        dfs(node.left);
        arr.add(node.val);
        dfs(node.right);
        }
    }
}
```