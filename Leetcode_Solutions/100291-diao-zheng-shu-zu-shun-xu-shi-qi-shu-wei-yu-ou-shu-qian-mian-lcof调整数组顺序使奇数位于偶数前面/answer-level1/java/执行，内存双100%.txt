### 解题思路
双指针
### 代码

```java
class Solution {
    public int[] exchange(int[] nums) {
        int len = nums.length;
		int[] ans = new int[len];
		int index = 0, left = 0, right = len - 1;
		while(left <= right) {
			if(nums[index] % 2 == 0) 
				ans[right--] = nums[index];
			else
				ans[left++] = nums[index];
			index++;
				
		}
		return ans;
    }
}
```