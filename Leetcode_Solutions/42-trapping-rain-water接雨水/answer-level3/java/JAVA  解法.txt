### 解题思路
首先不得不承认，我也是看了官方的解题思路后，思索了自己的思路(只看思路没看代码)，如下
1、首先循环所有的木块(数组中每个数字)从所找出最高的一块；
2、从最高的一块划分为左右两个数组，分别计算左右两个数组的盛水量
如何计算是关键
3、左边数组盛水量是，当前木块的盛水量=当前木块左边最大的-当前木块的大小，每个盛水量累加
4、右边数组盛水量是，当前木块的盛水量=当前木块右边最大的-当前木块的大小，每个盛水量累加
5、左右两边的盛水量累加输出；
### 代码

```java
class Solution {
    public int trap(int[] height) {
       // 0~2个柱子是没有水的
		if (height == null || height.length < 3) {
			return 0;
		}

		// 处理如果是3个柱子的情况
		if (height.length == 3) {
			if (height[1] > height[0] && height[1] > height[2]) {
				return 0;
			} else {
				if (height[0] >= height[2]) {
					return height[2] - height[1] > 0 ? height[2] - height[1]
							: 0;
				} else {
					return height[0] - height[1] > 0 ? height[0] - height[1]
							: 0;
				}
			}
		}

		int max = 0;

		for (int i = 0; i < height.length; i++) {
			if (height[i] > max) {
				max = height[i];
			}
		}

		// 返回的下标
		int index = countIndex(height, max);
		int[] left = Arrays.copyOf(height, index);
		int[] right = Arrays.copyOfRange(height, index, height.length);

		// 储水量
		int water = 0;

		// 从左边开始最高的格子
		int leftMax = 0;

		// 最高柱子左面的储水量
		for (int i = 0; i < left.length; i++) {

			// 判断是不是左边最大的
			if (left[i] > leftMax) {
				leftMax = left[i];
			}

			// 每个格子的储水量
			int temp = leftMax - left[i];
			water = water + temp;
		}

		// 从左边开始最高的格子
		int ritghtMax = 0;

		// 最高柱子右面的储水量，从倒数第二个开始算
		for (int i = right.length - 1; i > 0; i--) {

			// 判断是不是左边最大的
			if (right[i] > ritghtMax) {
				ritghtMax = right[i];
			}

			// 每个格子的储水量
			int temp = ritghtMax - right[i];
			water = water + temp;
		}

		return water;
    }

	public int countIndex(int[] height, int max) {

		for (int i = 0; i < height.length; i++) {

			if (height[i] == max) {

				return i;
			}
		}

		return -1;
	}



}
```