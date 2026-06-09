其实就是异或啦  
异或的属性是1^1=0 1^0=1    
让一个数字z=0^1^2^....^n  
然后在和给定的数组中每个数异或  
凡是出现的数字都会和之前已经出现的数字1^1掉，所以最后剩下的那个数因为没有配对所以就是缺失的那个数  
```
int missingNumber(vector<int>& nums) {
		int n = nums.size();
		int z = 0;
		for (int i = 1; i <= n; i++)
			z = z ^ i;
		for (int i = 0; i < nums.size(); i++)
			z = z ^ nums[i];
		return z;
	}
```
