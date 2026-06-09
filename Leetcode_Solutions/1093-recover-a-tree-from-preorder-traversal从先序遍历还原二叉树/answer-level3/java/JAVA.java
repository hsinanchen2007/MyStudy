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
    public TreeNode recoverFromPreorder(String S) {
        char [] c = S.toCharArray();
        List<TreeNode> list = new ArrayList<>();
        int index = 0;//S中索引
        int roo = 0;
        while (index < c.length && c[index] != '-')
            roo = roo * 10 + c[index++] - '0';
        TreeNode root = new TreeNode(roo);
        list.add(root);
        int count = 0;//-数统计
        int cur = 0;//当前的数值
        int precount = 0;
        while (index < c.length){
            if (c[index] == '-'){
                count++;
                index++;
                continue;
            }
            while (index < c.length && c[index] != '-')
                cur = 10 * cur + c[index++] - '0';
            TreeNode node = new TreeNode(cur);
            if (count < list.size())
                list.set(count,node);
            else
                list.add(node);
            TreeNode father = list.get(count - 1);
            if (count > precount)
                father.left = node;
            else
                father.right = node;
            precount = count;
            count = 0;
            cur = 0;
        }
        return root;
    }
}
```