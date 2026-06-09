题目相当于求**某一个子树的和**与**树的其他部分和**的**乘积**的最大值，数学常识：**当两数和一定，那么当这俩数相等的时候，乘积最大**，
所以这题就是求**哪个子树的节点和**与**整个树的节点和**的一半最接近。
- 先求整个树的节点和，顺带把每个子树和存一下（否则会超时）
- dfs遍历，不断判断哪个子树的节点和**最接近整个树的和的一半**
```java
public class P3 {

    int sum, sub, abs;
    Map<TreeNode, Integer> map = new HashMap<>();

    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    public int maxProduct(TreeNode root) {

        sum = travel(root);
        abs = sum;

        getSub(root);
        int mod = (int)(1e9+7);
        int ans = (int)(((long) sub * (sum - sub))%mod);
        return ans;
    }

    public int travel(TreeNode root) {

        if (root == null) return 0;

        int sum = root.val;
        sum += travel(root.left);
        sum += travel(root.right);
        map.put(root, sum);
        return sum;
    }

    public void getSub(TreeNode root) {

        if (root == null) return;

        int s = map.get(root), a;

        if ((a = Math.abs(sum - 2*s)) < abs) {
            abs = a;
            sub = s;
        }
        getSub(root.left);
        getSub(root.right);
    }
}
```
