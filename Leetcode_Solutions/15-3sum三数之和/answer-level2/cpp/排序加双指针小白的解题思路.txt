计算机小白的抓狂做题之旅...
主要难点还是在排除特殊情况和优化算法复杂度上吧
```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> ans;	
	set<vector<int>> m;  //集合set的第一次使用 哈哈 冲冲冲！！！
	int size = nums.size();
	if (size <= 2) return ans;
	sort(nums.begin(), nums.end());
	if (nums[0] > 0 || nums[size - 1] < 0) return ans;
	if (nums[0] == 0) {
		if (nums[1] == 0 && nums[2] == 0) {
			vector<int> t;
			for (int i = 0; i < 3; i++)
				t.push_back(0);
			ans.push_back(t);
		}
		return ans;
	}
	if (nums[size - 1] == 0) {
		if (nums[size - 2] == 0 && nums[size - 3] == 0) {
			vector<int> t;
			for (int i = 0; i < 3; i++)
				t.push_back(0);
			ans.push_back(t);

		}
		return ans;
	}

	for (int i = 1; i < size-1; i++) {
		int p=0, q=size-1;
		while (p<i&&q>i) {
			int sum = nums[p] + nums[i]+nums[q];
			if (sum == 0) {
				vector<int> t{ nums[p],nums[i],nums[q] };
				m.insert(t);
				do {p++;} while (p < i&&nums[p] == nums[p - 1]); //跳过相同元素
				
			}
			else if (sum > 0) do { q--; } while (q > i&&nums[q] == nums[q + 1]); //跳过相同元素
			else do { p++; } while (p < i&&nums[p] == nums[p - 1]);
			
		}
	}
	ans.assign(m.begin(), m.end());   //用多了应该就熟练了 现在的问题是见的用的太少
	return ans;    
    }
};
```

