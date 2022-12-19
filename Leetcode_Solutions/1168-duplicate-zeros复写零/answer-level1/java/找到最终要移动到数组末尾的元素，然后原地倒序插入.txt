# 用时1ms，打败99.88%

# 	思路：
	 * 第一步：遍历数组，遇0加2，非0加1，找到计数结果为数组长度的元素位置，该位置即为最终数组的最后一个元素
	 * 第二部：从该位置开始倒序遍历数组，依次将数组元素插入后面的位置
	 * 注意：最后一个元素为0，且只需要插入依次的情况
	

```
public void duplicateZeros(int[] arr) {
		//新数组元素计数
		int count = 0;
		//0元素计数
		int zeroCount = 0;
		//新数组最后一个元素的位置
		int i = 0;
        for (; i < arr.length && count < arr.length; i++) {
			//遇0加2，非0加1
			count += arr[i] == 0 ? 2 : 1;
			//0元素个数统计
			zeroCount += arr[i] == 0 ? 1 : 0;
		}
		--i;
		//如果数组中没有0，不需要改变
		if (zeroCount == 0) {
			return;
		}
		//如果数组前面元素中，0的个数超过数组长度的一半，那么数组最终全部为0
		if (zeroCount >= arr.length / 2) {
			for (int j = 0; j < arr.length; j++) {
				arr[i] = 0;
			}
			return;
		}
		int lastIndex = arr.length - 1;
		//数组最后一个元素为0，且只需要插入一次的case
		//判断条件即：非0元素的个数 + 二倍0元素个数，恰好为数组的长度
		if (zeroCount + i == arr.length ) {
			arr[lastIndex--] = 0;
			i--;
		}
		//倒序插入
		while (i >= 0) {
			if (arr[i] == 0) {
				arr[lastIndex--] = 0;
				arr[lastIndex--] = 0;
			} else {
				arr[lastIndex--] = arr[i];
			}
			i--;
		}
	}
```
