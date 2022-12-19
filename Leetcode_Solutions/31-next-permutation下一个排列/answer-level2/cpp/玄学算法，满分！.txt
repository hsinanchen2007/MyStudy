### 解题思路
此处撰写解题思路
判断给定的数组，从后面开始，如果他一直是升序的，比如 3 2 5 4 1, 1->4->5一直是升序的，那么直到发现第一个降序，比如 1->4->5->**2**,发现2比上一个小，那么再开一个循环从后往前判断第一个比降下来的那个数打的数，然后两数交换位置，比如1->**4**,4比2大，交换，序列就变成了[3, 4, 5, 2, 1],然后在换过的'4'那个位置以后的所有数（在这里4以后的是[5, 2, 1]三个数）进行排序（用sort）,然后序列变成了3 2 1 4 5，搞定。
### 代码
```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool ed = false;
		if (nums.size() < 2) return;
		if (nums[nums.size() - 1] > nums[nums.size() - 2])
		{
			int tmp;
			tmp = nums[nums.size() - 1];
			nums[nums.size() - 1] = nums[nums.size() - 2];
			nums[nums.size() - 2] = tmp;
			return;
		}
		for (int i = nums.size() - 1; i >= 1; i--)
		{
			if (nums[i] > nums[i - 1])
			{
				int pos = i - 1;
				for (int j = nums.size() - 1; j > pos; j--)
					if (nums[j] > nums[pos])
					{
						ed = true;
						int tmp;
						tmp = nums[pos];
						nums[pos] = nums[j];
						nums[j] = tmp;
						sort (nums.begin() + i, nums.end());
						break;
					}
			}
			if (ed == true) break;
		}
		if (ed == false) sort (nums.begin(), nums.end());
		return;
    }
};
```