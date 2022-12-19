问题：

数组排序之后的相邻数的最大差值；

嗯，你可以排序，然后找相邻的最大差值。

但是你觉得这么简单我写他干啥。

最优解：时间复杂度O(N)，空间O(1)


那我们开始说这种方法：

1）遍历所有数，找到最小值和最大值：min和max

2）设数组长度为n，我们准备n+1个桶

3）把max放进最后一个桶里，min放到第一个桶里

4）每一个桶都负责放一个范围内的数字，负责的范围大小是(max-min)/n。

（比如长度为10，最小值为10，最大值为110，那么准备11个桶，第一个桶放[10,20)的数字，第二个桶放[20,30)的数字......）

重点来啦：因为有n+1个桶，有n个数字，我们就发现了一个问题：必定会有空的桶

为什么我们一定要有空的桶呢？


![image.png](https://pic.leetcode-cn.com/d9ce833c550d14ce8be0c2886696cc3e449425696cfc08de1d3f06c282b75263-image.png)



这样我们就可以做到：桶内的相邻数字的差，一定没有不同桶之间的数字的差大

有了这个结论我们可以做什么呢？

其实找相邻桶和桶之间的差就好啦，桶内的那些情况根本不用关心

![image.png](https://pic.leetcode-cn.com/2222e505241f7134f80ccce554677c969ce97184ca84bff2db44913b03112084-image.png)


想到这里，我们发现桶里根本不用关心到底有几个数，他们的差是多少，只要记录每个桶的最大值最小值即可。



最后一点小问题啦：对于一个数num，他应该放在哪个桶，最好推个公式吧？
它应该被放在(num-min)*len/(max-min)这个桶里。也不难推。

最后就是写代码啦。

```
public class MaxGap {

	public static int maxGap(int[] nums) {
		if (nums == null || nums.length < 2) {
			return 0;
		}
		int len = nums.length;
		int min = Integer.MAX_VALUE;
		int max = Integer.MIN_VALUE;
		for (int i = 0; i < len; i++) {
			min = Math.min(min, nums[i]);
			max = Math.max(max, nums[i]);
		}
		if (min == max) {
			return 0;
		}
		boolean[] hasNum = new boolean[len + 1];//记录是否空
		int[] maxs = new int[len + 1];//桶内最大值
		int[] mins = new int[len + 1];//桶内最小值
		int bid = 0;
		//放入桶中
		for (int i = 0; i < len; i++) {
			bid = bucket(nums[i], len, min, max);
			mins[bid] = hasNum[bid] ? Math.min(mins[bid], nums[i]) : nums[i];
			maxs[bid] = hasNum[bid] ? Math.max(maxs[bid], nums[i]) : nums[i];
			hasNum[bid] = true;
		}
		int res = 0;
		int lastMax = maxs[0];
		int i = 1;
		//相邻桶求最大差值
		for (; i <= len; i++) {
			if (hasNum[i]) {
				res = Math.max(res, mins[i] - lastMax);
				lastMax = maxs[i];
			}
		}
		return res;
	}

	public static int bucket(long num, long len, long min, long max) {
		return (int) ((num - min) * len / (max - min));
	}

	public static void main(String[] args) {
		int[] arr = {};
		System.out.println(maxGap(arr));

	}

}

```




