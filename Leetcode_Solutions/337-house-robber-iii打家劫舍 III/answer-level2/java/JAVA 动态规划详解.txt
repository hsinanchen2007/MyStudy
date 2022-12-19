这题其实很像打家劫舍第一题

我们先把节点标记一下
![2019-08-30_191623.png](https://pic.leetcode-cn.com/882e52fdfdaac94a096ab22f9390504b5d64fa64c7acc7301b8f78e965d8b06f-2019-08-30_191623.png)

对于每个根节点来说，都有取和不取。

- 如果取，那么就不能取儿子，只能取孙子。
- 如果不取，那么可以取儿子或孙子
- 因为点都是正数，所以如果要取的话肯定不会只取一边，两边都会取

所以对于上面数据来说，有两种取法
1：取点1、4、5、6
2：取点2、3

看到这里，有没有发现跟打家劫舍1差不多？

我们可以把它当作打家劫舍第一题来看，第三层总和对应下标0，第二层总和对应下标1，第一层总和对应下标2

那么按这个数据翻译成第一题是这样的`num`={4,9,3}。

那么边界是什么？
叶子节点。
对于叶子节点，我们可以假设它的儿子和孙子都为0，那么是这样的
![无标题.png](https://pic.leetcode-cn.com/e99739e2589b786ad8ba86dc76e33d433587c7ebbc0d6f9291534fd2c055fc1f-%E6%97%A0%E6%A0%87%E9%A2%98.png)

写到这里，思路就跟第一题差不多了，我们只要遍历节点去处理就好了，定义一个长度为2的数组(0表示下一层，1表示下下层)，分别表示节点的下面两层的最大值。

```
public static int rob(TreeNode root) {
	int[] ans = pre(root);
    return Math.max(ans[0], ans[1]);
}
public static int[] pre( TreeNode root ) {
	int[] ans = new int[2];//
	if ( root == null ) return ans;//空
	int[] left = pre(root.left);//左子树
	int[] right = pre(root.right);//右子树
	ans[0] = Math.max(left[0]+right[0], left[1]+right[1]+root.val);//包不包含根节点，取较大值
	ans[1] = left[0] + right[0];//为上一层
	return ans;
}

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) { val = x; }
}
```


很少写题解，写得不好请见谅~(￣▽￣)~*
