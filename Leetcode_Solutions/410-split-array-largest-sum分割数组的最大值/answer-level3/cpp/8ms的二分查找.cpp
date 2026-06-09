### 解题思路
在check函数中，需要一些双指针的思想。

### 代码

```cpp
class Solution {
public:
typedef long long LL;
int check(int n,vector<int>&nums)
{
	int ct = 1;
	int last = 0;
	LL sum = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		sum += nums[i];
		if (sum  > n)
			ct++, sum = nums[i], last =i;
	}
	return ct;
}
    int splitArray(vector<int>& nums, int m) {
        LL sum = 0;
	int maxnn = 0;
	for (int i = 0; i < nums.size(); i++)
		sum += nums[i],maxnn=max(maxnn,nums[i]);
	LL L = maxnn;
	LL R = sum;
	LL mid;
	while (L < R - 1)
	{
		mid = (L + R) >> 1;
		if (check(mid, nums)>m)
			L = mid;
		else R = mid;
	}
	if(check(L,nums)<=m)
    {return L;}
    else{ return R;};
    }
};
```