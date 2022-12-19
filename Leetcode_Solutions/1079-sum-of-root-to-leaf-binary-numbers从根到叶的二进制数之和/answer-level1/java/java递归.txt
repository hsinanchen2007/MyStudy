
 二进制计算方式，假设二进制为1111
```
(2^3)*1+(2^2)*1+(2^1)*1+(2^0)*1 = ((1*2+1)*2+1)*2+1
```

```
class Solution {
    int sum = 0;
    public int sumRootToLeaf(TreeNode root) {
        if(root == null){
            return 0;
        }
        sumNode(root,0);
          return sum;
    }

    private void sumNode(TreeNode root, int num){
        if(root == null){
            return;
        }
        num += root.val;
        if(root.left == null && root.right == null){
            sum += num;
        }
        sumNode(root.left, num*2);
        sumNode(root.right, num*2);
        return;
    }
}
```