参考[小超王一郎的题解](https://leetcode-cn.com/problems/path-sum-iii/solution/javajie-fa-shi-jian-100-kong-jian-93-by-xiao-chao-/)，这里在for循环里把i=p带上，不过都是一个意思啦。


先看代码。
```
class Solution {
    public int pathSum(TreeNode root, int sum) {
        return helper(root, sum, new int[1000], 0); //0表示根
    }

    //array数组存储某一次递归时所遍历结点的结果值，p表示当前节点的位置
    public int helper(TreeNode root, int sum, int[] array, int p){
        if(root == null)    return 0;
        array[p] = root.val;
        int temp = 0;
        int n = 0;
        for(int i=p; i>=0; i--){
            temp += array[i];
            if(temp == sum){
                n ++;
            }
        }
        int left = helper(root.left, sum, array, p+1);
        int right = helper(root.right, sum, array, p+1);
        return n+left+right;
    }
}
```

感觉有点难理解的可能是array数组和p，借助题目的例子来解释。
![0.png](https://pic.leetcode-cn.com/445293dd9a65d1dfbfc81b492167ac855133b2393dea0c61fe059d02829528ac-0.png)
对于根节点10，也是我们需要求的，p=0, array[0]=10，因为它不等于8，上面也没有父节点了所以n=0；他的左子节点5，右子节点-3，我们来看5。因为递归了一次，这个时候p=1，array[1]=5,array[0]=10，发现n还是0，它的路径数应该是0+left+right。对于他的left，即节点3，此时p=2, array[2]=3，array[1]=5,array[0]=10，发现temp=3+5的时候等于sum，但3+5+10!=8，所以n=1。

所以借助p和数组array可以将当前节点所在路径上的各个节点的结果都储存下来。

我一开始忘了考虑0和负数，以为只要有一个temp等于sum之后就再加别的array元素只会更大，所以n最多只能等于1然后提前break。提交遇到[0,1,1],1 发现输出2预期4才知道应该给n加到头。
