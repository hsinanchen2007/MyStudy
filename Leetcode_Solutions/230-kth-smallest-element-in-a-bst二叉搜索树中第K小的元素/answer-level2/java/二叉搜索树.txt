### 解题思路
提到二叉搜索树最应该想到的就是中序遍历是一个有序数组。
然后有序数组中找指定大小的数不是就是下表-1嘛。
不知道数组大小是多少，就用list存储就好了。

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
    List<Integer> list = new ArrayList<>();
    public void midorder(TreeNode node){
        if(node == null)
            return;
        
        midorder(node.left);
        list.add(node.val);
        midorder(node.right);
    }

    public int kthSmallest(TreeNode root, int k) {
        midorder(root);
        return list.get(k-1);
    }
}
```