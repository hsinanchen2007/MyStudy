运用动态规划的算法，时间复杂度O(n^2)。首先用sort函数从小到大排序。用vector vv，vv[i]表示最大元素是i的最大整除子集的第二大元素。
vector sz,sz[i]表示最大元素是i的最大整除子集的大小，初始化sz[i]=1,vv[i]=i，表示集合只有一个元素。
要确定最大元素是i的最大整除子集，以1~i-1为最大元素的的最大整除子集大小和内容都已经确定，对于1<=j<i且能够整除i的j，取sz最大的sz[j]，将vv[i]更新为j,类似于链表的结构。
最后从表尾到表头取出
```
class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		//默认nums从小到大排序了
		int n = nums.size();
        if(n<=1)
            return nums;
        sort(nums.begin(),nums.end());
		vector<int> vv(n);//vv[i]记录最大元素是i的集合的次大元素
		vector<int> sz(n);//最大元素是i的集合的大小
		int res_n = 0;//结果集合的大小
		int res_idx = 0;//结果集合的最大元素
		for (int i = 0; i < n; ++i) {
			vv[i] = i;//等于自己表示仅有一个元素
			sz[i] = 1;//初始仅有自己
		}
		for (int i = 1; i < n; ++i) {
			int max_idx = 0;//小于i的能整除i的j的含有元素最多值
			int temp_max = 0;
			int j = 0;
			for (; j <= i; ++j) {
				if ((nums[i] % nums[j] == 0) && (sz[j] > temp_max)) {
					max_idx = j;
					temp_max = sz[j];
				}
			}
			vv[i] = max_idx;
			if (max_idx != i)//找到
				sz[i] = temp_max + 1;
			else
			{
				sz[i] = 1;
			}

			if (sz[i] > res_n) {
				res_n = sz[i];
				res_idx = i;
			}
		}
		vector<int> res(res_n);
		for (int i = 0; i < res_n; ++i) {
			res[res_n - i - 1] = nums[res_idx];
			res_idx = vv[res_idx];
		}
		return res;
	}
};
```
