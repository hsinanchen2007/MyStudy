
## 思路分析
通过深度遍历，记录路径上的计算结果，最后累加。

路径上的结果数字串计算方式如下：
```
num = num*10 +root.val;
```


## 代码实现
```java
class Solution {
    
    private int sum = 0;
    
    public int sumNumbers(TreeNode root) {
        helper(root, 0);
        return sum;
    }
    
    public void helper(TreeNode root, int num){
        if(root==null) return;
        num = num*10 +root.val;
        if(root.left==null&&root.right==null){
            sum+=num;
        }
        helper(root.left, num);
        helper(root.right, num);
    }
}
```