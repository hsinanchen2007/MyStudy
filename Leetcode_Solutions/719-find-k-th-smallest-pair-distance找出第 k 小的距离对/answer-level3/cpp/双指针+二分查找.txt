### 解题思路
![image.png](https://pic.leetcode-cn.com/8cf5a6a9b786c89e3e5bba1d7f509f6edc3afb1ebc1f80a9fa7f7380d3125698-image.png)
用二分查找时，首先需要找到单调的函数或序列，本题中，记f(n)为距离小于等于n的点对数，容易看出f(n)随着n递增，所以根据这个关系我们可以二分查找出第k个最小距离。代码中ltm为less than m，即对于一个距离dis，不超过该距离的点对数是否小于m，ltm_c为对于距离dis，不超过距离dis的点对数。计算点对数时采用双指针，时间空间复杂度为O(n).至于如何用双指针，可以对照着代码，选一个用例模拟一下就很好理解了。由于点距离取绝对值，我们不妨设每个点为(a,b)(a<=b).


### 代码

```cpp
class Solution {
public:
bool ltm(int m,int dis, vector<int>&nums)//双指针
{
	int last = nums[0];//没用到
	int lid = 0;//last id
	int ct = 0;//ct为计数变量，对距离小于dis的点对数进行统计
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] - nums[lid] <= dis)ct+=i-lid;//i-lid为以nums[i]为右点的距离小于dis点对数。
		else
		{
            bool st=false;
			while (nums[i] - nums[lid] > dis)
			{
				lid++;
			}
			ct+=i-lid;
		}
	}
	return ct < m;
}
int ltm_c(int m, int dis, vector<int>&nums)//和上面的ltm一样，只是返回类型不同
{
	int last = nums[0];
	int lid = 0;
	int ct = 0;
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] - nums[lid] <= dis)ct+=i-lid;
		else
		{
            bool st=false;
			while (nums[i] - nums[lid] > dis)
			{
				lid++;
                st=true;
			}
			ct+=i-lid;
		}
	}
	return ct;
}
    int smallestDistancePair(vector<int>& nums, int k) {
    if(nums.size()==2)//特判防止runtime error
    return nums[0]-nums[1]>0?nums[0]-nums[1]:-(nums[0]-nums[1]);
    int res;
	int size = nums.size();
	sort(&nums[0], &nums[0] + size);//排序
	int L = 0;
	int R = nums.back();
	int mid;
	while (L < R - 1)//开始二分查找
	{
		mid = (L + R) >> 1;
		if (ltm(k, mid, nums))//这步我也想了很久，首先过程是不难想的，需要模拟过程，才更容易写代码。
			L = mid;
		else R = mid;
	}
	
        if(ltm_c(k, L, nums) >= k)//我个人感觉二分查找很多时候只是把解缩小到一定的范围，即L和R以内，还需要在L，R中明确。
        res=L;
        else{ 
            res=R;
        }
	return res;
    }
};
```