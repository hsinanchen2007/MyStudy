大体分两步：
1. 裁剪窗口，使窗口大小最大为k
2. 只要新增数据（在队尾）比前面数据大，前面数据都扔掉。如果新增数据比队尾数据小，就添加到队尾。
根据如下代码可在excel里推演以上思路，如图
![微信图片_20191107222449.png](https://pic.leetcode-cn.com/c6d25424b5ad5b9783f70ed8fead3627246fb01aca2d72c92bd2b68cfbfce9b3-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20191107222449.png)


```
public int[] maxSlidingWindow(int[] a, int k) {
		if (a == null || k <= 0) {
			return new int[0];
		}
		int n = a.length;
		int[] r = new int[n - k + 1];
		int ri = 0;
		// store index
		Deque<Integer> q = new ArrayDeque<>();
		for (int i = 0; i < a.length; i++) {
			// remove numbers out of range k
			//q就是窗口，始终最多只有k个元素，只要小于，就把前面的数全扔掉才能剩下最多k个
			while (!q.isEmpty() && q.peekFirst() < i - k + 1) {
				q.pollFirst();
			}
			// remove smaller numbers in k range as they are useless
			//只要新增数据（在队尾）比前面数据大，前面数据都扔掉，保证队首数据总是最大，再结合上面while循环，保证窗口内的队首数据最大，
			//后面的if语句只要取队首就可以
			//如果新增数据比队尾数据小，就添加到队尾。队列数据是从大到小序列
			while (!q.isEmpty() && a[q.peekLast()] < a[i]) {
				q.pollLast();
			}
			// q contains index... r contains content
			q.offerLast(i);
			if (i >= k - 1) {
				r[ri++] = a[q.peekFirst()];
			}
		}
		return r;
	}
```
