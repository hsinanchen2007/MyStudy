给你一个已经 排好序 的整数数组 nums 和整数 a、b、c。对于数组中的每一个数 x，计算函数值 f(x) = ax2 + bx + c，请将函数值产生的数组返回。

要注意，返回的这个数组必须按照 升序排列，并且我们所期望的解法时间复杂度为 O(n)。

示例 1：

输入: nums = [-4,-2,2,4], a = 1, b = 3, c = 5
输出: [3,9,15,33]

示例 2：

输入: nums = [-4,-2,2,4], a = -1, b = 3, c = 5
输出: [-23,-5,1,7]



```
        /**
	 * 如果不用排序，那么只能依靠数学有段抛物线的知识来做题，同时利用了双指针
	 * 
	 * @param nums
	 * @param a
	 * @param b
	 * @param c
	 * @return
	 */
	public int[] sortTransformedArray(int[] nums, int a, int b, int c) {
		int[] res = new int[nums.length];
		if (a == 0) {// 如果a=0，那么就是一条直线
			if (b == 0) {
				for (int i = 0; i < nums.length; i++) {
					res[i] = c;
				}

			} else if (b > 0) {
				for (int i = 0; i < nums.length; i++) {
					res[i] = b * nums[i] + c;
				}
			} else {
				for (int i = 0; i < nums.length; i++) {
					res[nums.length - i - 1] = b * nums[i] + c;
				}
			}
		} else {// 如果a!=0，那么就是一条抛物线，计算抛物线的对称轴横坐标x0，根据a的正负以及x到x0的距离来算
			int cnt = 0;
			double mid = -b * 1.0 / a / 2;
			int l = 0, r = nums.length - 1;
			if (a > 0) {
				// a>0时，获取最小的点开始循环
				for (int i = 0; i < nums.length - 1; i++) {
					if (nums[i] < mid && nums[i + 1] > mid || nums[i] == mid) {
						l = i;
						r = i + 1;
						break;
					}
				}
				while (l >= 0 || r < nums.length) {
					if (r == nums.length) {
						res[cnt++] = cal(nums[l--], a, b, c);
					} else if (l < 0) {
						res[cnt++] = cal(nums[r++], a, b, c);
					} else {
						if (mid - nums[l] >= nums[r] - mid) {
							res[cnt++] = cal(nums[r++], a, b, c);
						} else {
							res[cnt++] = cal(nums[l--], a, b, c);
						}
					}
				}
			} else {
				// a<0时，从两边开始
				while (l <= r) {
					if (mid - nums[l] >= nums[r] - mid) {
						res[cnt++] = cal(nums[l++], a, b, c);
					} else {
						res[cnt++] = cal(nums[r--], a, b, c);
					}
				}
			}
		}
		return res;
	}

	public int cal(int x, int a, int b, int c) {
		return a * x * x + b * x + c;
	}
```