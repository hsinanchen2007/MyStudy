### 解题思路
顺序暴力遍历，时间不符合要求，用二分法遍历。
其实也没有很明白，最大值为什么要取值为Max(nums)
### 代码

```java
class Solution {
   /**
	 * 1283 使结果不超过阈值的最小除数
	 * @param nums
	 * @param threshold
	 * @return
	 */
	public static int smallestDivisor(int[] nums, int threshold) {
		int l = 1;
//		Arrays.sort(nums);
		int r = nums[nums.length-1];//为啥上限要定 最大值？
		int ans  = -1;
		while(l <= r){
			int sum = 0,mid = (l+r)/2;
			for(int a:nums){
				sum += (a - 1)/mid + 1;
			}
			if(sum <= threshold){
				r = mid - 1;
				ans = mid;
			}else{
				l = mid + 1;
			}
		}
		return ans;
    }
}
```