### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
	public int findRepeatNumber(int[] nums) {
		int N = nums.length;
		int ans = 0;
		int[] bucket =  new int[N];
		for(int i = 0 ; i< N ; i ++) {
			int index = nums[i];
			bucket[index]++;
		}
		
		for(int i = 0 ; i< N ;i++) {
			if(bucket[i] > 1) {
				ans = i; 
				break;
			}
		}
		
		return ans;
    }
}
```