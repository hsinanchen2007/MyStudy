### 解题思路
1.首先必须确认返回的数组的长度
2.该题目的目标数组长度是由源数组中偶数位（0开始）位元素的值叠加起来
3.只得到偶数位元素，变量i值需要i+2（从0开始）
4.最后遍历源数组，并向目标数组中添加元素
### 代码

```java
class Solution {
	public int[] decompressRLElist(int[] nums) {
		//确认目标数组的长度
		int length = 0;
		for(int i = 0; i < nums.length; i++) {
			length += nums[i++];
		}
		int[] ans = new int[length];
		//向目标数组添加元素
		int location = 0;
		for (int i = 0; i < nums.length; i++) {
			for (int j = 0; j < nums[i]; j++) {
				ans[location++] = nums[i+1];
			}
			i++;
		}
		return ans;
	}
}
```