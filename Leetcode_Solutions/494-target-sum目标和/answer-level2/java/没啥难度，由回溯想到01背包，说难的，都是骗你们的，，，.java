### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
   public int findTargetSumWays(int[] nums, int S) {
		int length = 0;
		for (int i = 0; i < nums.length; i++) {
			length = length + nums[i];
		}
        if(length<S)
			return 0;
		int[][] data = new int[2 * (length + 1)][nums.length];
		/**
		 * 这里约定了 -符号，就是这个length-数本身，+符号则是这个数+length
		 * 
		 */
		data[length - nums[0]][0] = 1;
		data[nums[0] + length][0] = data[nums[0] + length][0] + 1;
		for (int i = 1; i < nums.length; i++) {
			for (int j = 0; j < data.length; j++) {
				if (data[j][i - 1] > 0) {
					/**
					 * 符号-
					 */
					data[j - nums[i]][i] = data[j - nums[i]][i] + data[j][i - 1];

					/**
					 * 符号+
					 */
					data[j + nums[i]][i] = data[j + nums[i]][i] + data[j][i - 1];

				}

			}

		}
		return data[S + length][nums.length - 1];
	}
}
```