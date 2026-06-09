执行用时 :0 ms, 在所有 java 提交中击败了100.00%的用户
内存消耗 :34.8 MB, 在所有 java 提交中击败了44.52%的用户

```
//answer[0]存当前的值;answer[1]存父节点需要乘上的权重
class Solution {
    public int sumNumbers(TreeNode root) {
        return sumNumbersHelper(root)[0];
    }

    private int[] sumNumbersHelper(TreeNode root){
        int[] answer, left, right;

        answer = new int[2];
        if(root == null)
            return answer;
        if(root.left == null && root.right == null){
            answer[0] = root.val;
            answer[1] = 10;
            return answer;
        }
        left = sumNumbersHelper(root.left);
        right = sumNumbersHelper(root.right);
        answer[0] = root.val * left[1] + left[0] + root.val * right[1] + right[0];
        answer[1] = (left[1] + right[1]) * 10;
        return answer;
    }
}
```
