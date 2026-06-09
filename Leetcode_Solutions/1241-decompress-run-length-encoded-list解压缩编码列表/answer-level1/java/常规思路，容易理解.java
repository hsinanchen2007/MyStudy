
![image.png](https://pic.leetcode-cn.com/d9232dad3e30c57f2677b52696179363b39860123e84a2bc40322dddd19367c7-image.png)

	if (nums.length % 2 != 0) {
			return null;
		}

		int length = 0;
		for (int i = 0; i < nums.length / 2; i++) {
			length += nums[i * 2];
		}

		int[] result = new int[length];
		int count = 0;
		for (int i = 0; i < nums.length / 2; i++) {
			for (int j = 0; j < nums[2 * i]; j++) {
				result[count] = nums[2 * i + 1];
				count++;
			}
		}

		return result;




