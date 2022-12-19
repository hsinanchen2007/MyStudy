### 解题思路
如果将大树的先序遍历结果认为是s1，小树的先序遍历是s2，这个问题等价于s2是否为s1的子串

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
    public boolean isSubtree(TreeNode s, TreeNode t) {
        String str1 = preOrder(s), str2 = preOrder(t);
        return kmp(str1.toCharArray(), str2.toCharArray()) >= 0;
    }

    private int kmp(char[] arr, char[] target){
        int[] next = getNextArray(target);
        int i = 0, j = 0;
        while(i < arr.length && j < target.length){
            if(arr[i] == target[j]){
                i++;
                j++;
            } else if(next[j] != -1){
                j = next[j];
            } else {
                i++;
                j = 0;
            }
        }
        if(j == target.length)
            return i - j;
        return -1;
    }

    private int[] getNextArray(char[] arr){
        int[] next = new int[arr.length + 1];
        next[0] = -1;
        next[1] = 0;
        int c = 0, index = 1;
        while(index < arr.length){
            if(arr[c] == arr[index])
                next[++index] = ++c;
            else if (c == 0){
                next[++index] = 0;
            } else {
                c = next[c];
            }
        }
        return next;
    }

    private String preOrder(TreeNode head){
        StringBuilder sb = new StringBuilder();
        Stack<TreeNode> stack = new Stack<TreeNode>();
        stack.push(head);
        while (!stack.isEmpty()) {
            TreeNode node = stack.pop();
            if (node == null)
                sb.append("(*)");
            else {
                sb.append("(" + String.valueOf(node.val) + ")");
                stack.push(node.left);
                stack.push(node.right);
            }
        }
        return sb.toString();
    }
}
```