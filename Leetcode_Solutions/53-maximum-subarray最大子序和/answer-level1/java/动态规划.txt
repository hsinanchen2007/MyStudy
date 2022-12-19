动态规划的题目：使用一个res数组来存储每次某一位置的数是否相加的结果，如果相加的结果比该数本身都小，则不进行添加，res[i]的值不是加上该数的和而是该数自己(第一次写题解，写的不好，大家还是看代码吧)
```
public static int maxSubArray(int[] nums) {
		
		//动态规划
		int len = nums.length;
		int[] res = new int[len];
		int max = nums[0];
		res[0] = nums[0];
		for (int i = 1; i < len; i++) {
			int temp = res[i-1]+nums[i];
			if(temp>nums[i]){
				res[i] = temp;
			}else {
				res[i] = nums[i];
			}
			if(res[i]>max){
				max = res[i];
			}
		}
		return max;
	}
```
