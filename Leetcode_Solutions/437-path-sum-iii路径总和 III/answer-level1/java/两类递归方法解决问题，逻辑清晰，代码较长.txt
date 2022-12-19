基本碰到树的问题就是要递归解决了，但是开始的递归犯了一个错误，我试图使用原方法递归
1、递归跳出的条件是root==null，这个毫无疑问
2、如果sum=root.val则return 1+多个递归树，反之return 多个递归树
3、递归树分为，包含/不包含root，左节点/右节点
递归方法刚开始我是这样写的：
```
    public int pathSum(TreeNode root, int sum) {
        if (root == null) {
            return 0;
        }
        if (sum == root.val) {
            return 1 + pathSum(root.left, sum) + pathSum(root.right, sum)
                    + pathSum(root.left, sum - root.val) + pathSum(root.right, sum - root.val);
        }else{
            return pathSum(root.left, sum) + pathSum(root.right, sum)
                    + pathSum(root.left, sum - root.val) + pathSum(root.right, sum - root.val);
        }
    }
```
显然结果不对，问题出在哪里呢，这个递归从运算上是无问题，然后使用测试用例我发现命中了10，-2这两个节点，问题显而易见，不连接的路径也计入了，那么如何避免？
只需要当我们选取root节点时，接下来的遍历，使用另外一个递归方法，该递归方法前提是已经包含了上级节点，则不允许舍弃当前节点去求子树的和
不选取root节点简单，使用原递归方法即可，最终代码如下：
```
class Solution {
    public int pathSum(TreeNode root, int sum) {
        if (root == null) {
            return 0;
        }
        if (sum == root.val) {
            return 1 + pathSum(root.left, sum) + pathSum(root.right, sum)
                    + pathSumHas(root.left, sum - root.val) + pathSumHas(root.right, sum - root.val);
        }else{
            return pathSum(root.left, sum) + pathSum(root.right, sum)
                    + pathSumHas(root.left, sum - root.val) + pathSumHas(root.right, sum - root.val);
        }
    }

    int pathSumHas(TreeNode root, int sum) {
        if (root == null) {
            return 0;
        }
        if (sum == root.val) {
            return 1
                    + pathSumHas(root.left, sum - root.val) + pathSumHas(root.right, sum - root.val);
        }else{
            return
                    pathSumHas(root.left, sum - root.val) + pathSumHas(root.right, sum - root.val);
        }
    }
}
```

20:57	info
			解答成功:
			执行耗时:32 ms,击败了20.48% 的Java用户
			内存消耗:39.5 MB,击败了69.23% 的Java用户

时间上略长了，原因应该是一些跳出的条件没有判断，导致每次都判断到null的节点才结束，例如当前节点如果左右无节点，直接通过比较当前节点的val和sum即可返回结果，而不需要多重递归，增加这个跳出条件后
21:00	info
			解答成功:
			执行耗时:31 ms,击败了29.58% 的Java用户
			内存消耗:39.5 MB,击败了71.43% 的Java用户
也不是很尽如人意，不过逻辑无问题，优化可以再考虑了