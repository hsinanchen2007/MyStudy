```java
public boolean checkPossibility(int[] nums) {
		
		int changeNums = 0;
		
		for (int i = 0; i < nums.length - 1; i++) {
			// 第一个元素大于第二个元素
			if (i == 0 && nums[i] > nums[i + 1]) {
				changeNums++;
			} else {
				if (nums[i] > nums[i + 1]) {
					// 改变i的情况
					if (i - 1 >= 0 && nums[i - 1] < nums[i + 1]) {
						changeNums++;
					} else if ((i - 1 >= 0 && i + 2 < nums.length && nums[i - 1] < nums[i + 2] && nums[i] < nums[i + 2])
							|| (i + 2 == nums.length)) {
						// 改变i+1的情况
						changeNums++;
					} else {
						// 不论改变i还是i+1都不行，随便给个失败的数字
						changeNums = 2;
					}
				}
			}
		}

		return changeNums == 0 || changeNums == 1;
	}