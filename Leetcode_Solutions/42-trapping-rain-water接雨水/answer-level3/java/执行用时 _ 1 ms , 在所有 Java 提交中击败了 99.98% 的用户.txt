### 解题思路
这个解法思路很简单,就是将存储的雨水分为最大值索引的左右两边,然后每次向左/右寻找次最大值索引,
两个索引之间存储的雨水就是：次最大值高度*两个索引之间的间隔数-两个索引之间的所有高度和
然后再以次最大值为最大索引,依次叠加
累加计算两个索引之间的存储雨水量,这里以右边的为例
rsum += array[rmax] * (rmax - max - 1) - getSum(array, max, rmax);

### 代码

```java
class Solution {
    public int trap(int[] array) {
		// 先找到整个数组最大索引
		int max = 0;
		for (int i = 0; i < array.length; i++) {
			if (array[i] > array[max]) {
				max = i;
			}
		}
		int temp = max;// 保存最大值索引
		int rsum = 0;//
		// 向右计算存储的雨水
		while (max >=0) {
			int rmax = rmaxIndex(array, max);
			if (rmax > max + 1) {
				rsum += array[rmax] * (rmax - max - 1) - getSum(array, max, rmax);
			} 
			max = rmax;
		}
		// 向左计算存储的雨水
		int lsum = 0;
		while (temp >=0) {
			int lmax = lmaxIndex(array, temp);
			if (lmax < temp - 1) {
				lsum += array[lmax] * (temp - lmax - 1) - getSum(array, lmax, temp);
			}
			temp = lmax;
		}
		return lsum + rsum;
	}

	// 向右寻找时
	// 找到给定数组的最大值的索引,若有相同的最大值,取后面的最大索引
	private static int rmaxIndex(int[] array, int index) {
		int maxIndex = index + 1;
		if (maxIndex >= array.length) {
			return -1;
		}
		for (int i = index + 1; i < array.length; i++) {
			if (array[i] >= array[maxIndex]) {
				maxIndex = i;
			}
		}
		return maxIndex;
	}

	// 向左寻找时
	// 找到给定数组的最大值的索引,若有相同的最大值,取前面的最大索引
	private static int lmaxIndex(int[] array, int index) {
		if(index==0) {
			return -1;
		}
		int maxIndex = 0;
		for (int i = 0; i < index; i++) {
			if (array[i] > array[maxIndex] ) {
				maxIndex = i;
			}
		}
		return maxIndex;
	}

	// 计算两个索引之间的高度和
	private static int getSum(int[] array, int l, int r) {
		int sum = 0;
		for (int i = l + 1; i < r; i++) {
			sum += array[i];
		}
		return sum;
	}
}
```