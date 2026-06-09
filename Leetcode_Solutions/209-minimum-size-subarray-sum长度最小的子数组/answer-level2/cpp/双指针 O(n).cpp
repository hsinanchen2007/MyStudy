以样例[2,3,1,2,4,3] s= 7为例，因为是连续序列，所以就直观上从0位置开始找  
以i记录这段连续子序列的开始，j记录结束  
想找可能的组合，从0开始，j=3时【2,3,1,2】满足条件。  
接下来循环处理，只要当前sum>=s，就i指针前移（因为已经满足条件，且找长度最小，所以j后移无意义）；否则j后移  
一旦满足sum>=s就判断当前是否长度更小  
```
int minSubArrayLen(int s, vector<int>& nums) {
		int n = nums.size();
		int i = 0, j;
		int len = n + 3;
		int sum = 0;
		for (j = 0; j < n; j++) {
			sum += nums[j];
			if (sum >= s) {
				len = (j + 1);
				break;
			}
		}
		while (i < n && j<n) {
			if (sum >= s) {
				if (j - i + 1 < len)
					len = j - i + 1;
				if (i >= n)break;
				sum -= nums[i];
				i++;
			}
			else
			{
				j++;
				if (j >= n)break;
				sum += nums[j];
			}
		}
		if (len > n)
			return 0;
		return len;
	}
```
