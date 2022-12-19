思路：
在只允许买卖一次的情况下，只需要找到目标数组中的最小值，再逐一记录当前最大收益值即可。
从左到右遍历，每次用当前元素减去之前的最小值求差值，最后比较最大利润是否有变大，变大则更新。
因此就只需要两个变量：
+ min(记录最小值)
+ pro(记录截止目前的最大收益值)
```
	static int getMax(int[] nums) {
		if (nums.length < 2 || nums == null) {
			return 0;
		}
		int min = nums[0];
		int pro = 0;
		for (int i = 1; i < nums.length; i++) {
			if (nums[i] < min) {
				// 更新最小值
				min = nums[i];
			} else if (nums[i] > min) {
				int temp = nums[i] - min;
				// 如果大于之前的利润 再更新利润
				if (temp > pro) {
					pro = temp;
				}
			}
		}

		return pro;
	}
```
> 注意：以上代码变量值和方法名和题干不同，执行耗时1ms。
