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
    public void recoverTree(TreeNode root) {
        List<TreeNode> stack = new ArrayList<>();
        List<TreeNode> list = new ArrayList<>();
        while (root != null || !stack.isEmpty()){
            if (root != null){
                stack.add(root);
                root = root.left;
            }
            else {
                TreeNode remove = stack.remove(stack.size() - 1);
                list.add(remove);
                root = remove.right;
            }
        }
        TreeNode[] treeNodes = list.toArray(new TreeNode[0]);
        //采用插入排序 这里转换为数组进行排序
        for (int i = 1; i < treeNodes.length; i++) {
            //将元素(i)插入到[0，i-1]中
            int k = i;
            for(int j = i - 1; j >= 0 ; j--){
                //此时有序
                if (treeNodes[k].val > treeNodes[j].val)
                    break;
                else {
                    int temp = treeNodes[k].val;
                    treeNodes[k].val = treeNodes[j].val;
                    treeNodes[j].val = temp;
                    k--;
                }
            }
        }
    }
}
```