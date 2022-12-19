### 解题思路
1、倒序遍历，碰到比前一个值小的就停止，当前位置的值记为a；
2、把遍历过的值从小到大排序，排序过程中记录下比a大的最小值的索引位置；
3、排序完毕，把a所在位置和上一步记录的位置值互换。

### 代码

```java
class Solution {
    public void nextPermutation(int[] nums) {
    	if(nums.length<=1)return;
		int max = nums[nums.length - 1];
		for (int i = nums.length - 1; i >= 0; i--) {
			int a = nums[i];
			if (a < max) {
				int index=i;
				for (int x = i+1; x < nums.length; x++) {
					for (int y = x + 1; y < nums.length; y++) {
						if (nums[x] > nums[y]) {
							int temp = nums[x];
							nums[x] = nums[y];
							nums[y] = temp;
						}
					}
					if(nums[x]>a&&index<=i) {
						index=x;
					}
				}
				int ii=nums[index];
				nums[index]=a;
				nums[i]=ii;
				return;
			}
			max = a;
			if (i == 0) {
				for (int j = 0; j <= nums.length / 2 - 1; j++) {
					int x = nums[j];
					int y = nums[nums.length - 1 - j];
					nums[j] = y;
					nums[nums.length - 1 - j] = x;
				}
				return;
			}

		}
    }
}
```