![image.png](https://pic.leetcode-cn.com/8d5e30d31a63950aaf2b3d2f06bce6dab2fa51c369fd9865077ae24b5c4958d1-image.png)

```
class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> answer, left, right;
        
        answer = new ArrayList<Integer>();
        if(root == null)
            return answer;
        answer.add(root.val);
        left = rightSideView(root.left);
        right = rightSideView(root.right);
        answer.addAll(right);
        if(left.size() > right.size())
            answer.addAll(left.subList(right.size(), left.size()));
        return answer;
    }
}
```
