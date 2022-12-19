### 解题思路
才击败8.29%

### 代码

```java
class Solution {
    public void nextPermutation(int[] nums) {
        Integer a = null;//i
		Integer b = null;//j
		for (int i = nums.length - 1; i >= 1 ; i--) {//后一个数字
			for (int j = i - 1; j >= 0; j--) {//前一个数字
				if (nums[i] > nums[j]) {
					if(a == null) {
						a = i;
						b = j;
					}else {
						if(j > b) {
							a = i;
							b = j;
						}
					}
				}
			}
		}
		if(a != null) {
			//交换i,j
			int temp = nums[a];
			nums[a] = nums[b];
			nums[b] = temp;
			for (int k = b + 1; k < nums.length - 1; k++) {
				for (int h = k + 1; h < nums.length; h++) {
					if (nums[h] < nums[k]) {
						int temp2 = nums[k];
						nums[k] = nums[h];
						nums[h] = temp2;
					}
				}
			}
		}else {
			// 能走到这里说明没有更大的排列
			for (int i = 0; i < nums.length - 1; i++) {
				for (int j = i + 1; j < nums.length; j++) {
					if (nums[j] < nums[i]) {
						int temp = nums[i];
						nums[i] = nums[j];
						nums[j] = temp;
					}
				}
			}
		}
    }
}
```