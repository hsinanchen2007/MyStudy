### 要点
1. 假设你非常暴力，把每一条路径数组都记录后求解也是可以的，就是性能跟不上...这里不过多介绍了。

2. 理解递归的特性，它记录当层递归的变量。
	如果你求出了最后一层的数字是 495，在返回上一层的时候系统会帮你把 49记录下来
也就是说 4 -> 49 -> 495 返回的时候就是 495 -> 49 -> 4。
### 解法
#### 代码片段
```java
public int sumNumbers(TreeNode root) {
	if (root == null) {//0.终止条件
		return 0;
	}
	int[] result = new int[1];//1.记录结果
	sumNumbersHelper(root, 0, result, 0);//3.求解结果
	return result[0];//2.返回结果
}

public void sumNumbersHelper(TreeNode root, int preSum, int[] ints, int h) {
	if (root == null) {//4.终止条件
		return;
	}
	int nSum = preSum * 10 + root.val;//5.到达当前层的数字是 上一层和*10+当前数字
	if (root.left == null && root.right == null) {//8.当到达叶子节点的时候将这个数字统计到结果
		ints[0] += nSum;
	}
	sumNumbersHelper(root.left, nSum, ints, h + 1);//6.计算左子树的和
	sumNumbersHelper(root.right, nSum, ints, h + 1);//7.计算右子树的和
}
```


---
## 结尾 
##### [1.博客地址](https://blog.csdn.net/weixin_42322309)
##### [2.源代码仓库](https://gitee.com/Gre-Z/Algorithm")
> 如果你在代码里看到了用 数字标记的注释 如 //1.xxx 这是我写代码的顺序，希望能给你一点启发。