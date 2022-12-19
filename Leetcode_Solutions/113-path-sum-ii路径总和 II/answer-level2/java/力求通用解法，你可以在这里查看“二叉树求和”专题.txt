### 要点
[【LeetCode算法修炼+动画演示】—— 112. 路径总和](https://blog.csdn.net/weixin_42322309/article/details/104222075)
思路是一样的，仅仅是这里需要将走过的节点记录下来。
### 解法
用什么来记录行走的路径呢？ 
没错 用 ```ArrayList```数组记录啦，因为封装了一些常用的方法来移除和增加数组元素。
#### 代码片段
```java
//	113. 路径总和 II
public List<List<Integer>> pathSumII(TreeNode root, int sum) {
	List<List<Integer>> lists = new ArrayList<>();//1.初始化存放结果的二维数组。
	pathSumIIHelper(root, lists, sum, new ArrayList<Integer>());
	return lists;//2.返回结果数组。
}

public void pathSumIIHelper(TreeNode head, List<List<Integer>> lists, int sum, List<Integer> list) {
	if (head == null) {//3.终止条件。
		return;
	}
	list.add(head.val);//4.添加元素到记录当前路径的数组。
	if (head.val == sum && head.left == null && head.right == null) {
		lists.add(new ArrayList<>(list));//8.拷贝当前路径数组到结果数组，你需要拷贝数组！！！
	}
	pathSumIIHelper(head.left, lists, sum - head.val, list);//5.遍历左子树。
	pathSumIIHelper(head.right, lists, sum - head.val, list);//6.遍历右子树。
	list.remove(list.size() - 1);//7. 移除当前路径的最后一个元素。
}
```
[1.博客地址](https://blog.csdn.net/weixin_42322309)
[2.相关源代码地址](https://gitee.com/Gre-Z/Algorithm)
