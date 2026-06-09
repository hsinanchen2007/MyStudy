```java
public class Solution{
	/*
	 * 双指针
	 * i指向满足条件的连续子数组的左端,j指向右端.
	 * 	如果当前的和大于等于指定的值,则得出当前最短长度,将i后移一位,再判断当前的sum是否满足条件;
	 * 	如果当前的和小于指定的值,则j后移一位,再判断.
	 */
	public static int minSubArrayLen(int s, int[] nums) {
		if(nums == null || nums.length == 0) return 0;
		int i = 0; //指向数组开头
		int j = 0; //指向
		int minLen = Integer.MAX_VALUE;
		int sum = nums[j];
		while(j < nums.length) {
			//如果当前的和大于指定的值s
			if(sum >= s) {
				minLen = Math.min(minLen, j-i+1); //求得最小的长度
				sum -= nums[i]; //现在的sum为之前的sum减去之前nums[i]的值
				i++;
			}else if(sum < s){ //如果当前的sum小于指定的s,则j后移一位
				j++;
				if(j != nums.length) { //判断是否是最后一位数
					sum += nums[j];
				}
			}
		}
		//如果minLen还是初始值,则说明一直没找到满足条件的连续子数组,返回0;
		if(minLen == Integer.MAX_VALUE) { 
			return 0;
		}
		return minLen;
	}

	/*
	 * 暴力求解
	 */
	public static int minSubArrayLenVio(int s, int[] nums) {
		int minLen = Integer.MAX_VALUE;
		int sum = 0;
		//从第一个元素开始遍历
		for(int i = 0; i < nums.length; i++) {
			sum = 0;
			for(int j = i; j < nums.length; j++) {
				sum += nums[j]; 
				if(sum >= s) {  //如果当前的和大于指定的s,则获得最小长度,并且退出本次循环
					minLen = Math.min(minLen, j-i+1);
					break;
				}
			}
		}
		if(minLen == Integer.MAX_VALUE) {
			return 0;
		}
		return minLen;
	}
}
```