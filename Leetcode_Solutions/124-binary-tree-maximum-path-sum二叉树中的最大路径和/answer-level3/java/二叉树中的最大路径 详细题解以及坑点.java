先推一波博客 https://blog.csdn.net/sakura_is_the_best/article/details/103809207

博客阅读效果更佳

这个题题意有点模糊，这个路径是不能有**回路**的，但是题目中也没有明确说明，算个大坑点。

思路就是递归，说是递归更有点像树形dp，cal(root)函数代表root节点一定被选而能得到的最大的路径长度且**该路径最多只经过一个root的一个子树**。

想知道这个信息必须知道cal(root.left)和cal(root.right)，cal(root)显然应该等于root.val+max(cal(root.left),cal(root.right)),这是是很显然的。

那么问题是为什么cal(root)代表的路径只能经过root的一个子树呢？这是因为无论对于什么样的树，这个满足题意的最长的路径，最多只可能有一个节点的两个子树都会被包含进去，否则就会有回路出现。

比如

![image.png](https://pic.leetcode-cn.com/4c511caa947a2f5e977e81398371b89b84c27e83891f9dfb9b02071788828787-image.png)

假如选择了7,11,2,4,5,8这条路径，很明显11节点和5节点的两个子树都被涉及，那么必然存在回路，比如7->11->2->11，这是不满足的题意的。所以cal(root)表示在root的两个子树中最多选择一个的最长路径。如果没有这个只选一个的限制，那么cal函数根本无法更新，因为你无法保证所有节点的cal函数总共有几个节点选择两个子树，如果超过1个节点选择两个子树，那么就不符合题意，整个cal函数都是错误的。

当然最后有可能有一个节点要选择两个子树，那么就在cal递归的过程中枚举到底是哪个子树会选择两个子树，然后用一个全局变量ans去保存这个节点，所有节点这个ans值最大的就是答案。

就是因为不能有回路的限制，造成cal返回值并不是最终答案，这也是这个题最坑的地方。

如果有不明白的地方还可以交流啊。

```
class Solution {
    int ans = -0x3f3f3f3f;
    public int cal(TreeNode root)
    {
        if(root==null)
           return 0;
        int l = cal(root.left);
        int r = cal(root.right);
        int now = root.val;
        if(l>0)
           now+=l;
        if(r>0)
           now+=r;
        ans = Math.max(now,ans);//若root节点最多选择两个子树可得到的最长路径
        int m = 0;
        m = Math.max(m,l);
        m = Math.max(m,r);
        return root.val+m;//cal返回值是只能在两个子树中选择一个所得到的最长路径
    }
    public int maxPathSum(TreeNode root) {
        cal(root);
        return ans;
    }
}

```
