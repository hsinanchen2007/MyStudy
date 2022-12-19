```
const int blen = sizeof(unsigned long long)*8;
const int len = 5000 / blen + 1;
class Solution {
public:
	bool circularArrayLoop(vector<int>& nums) {
		unsigned long long mark1[len] = { 0 };
		unsigned long long mark2[len] = { 0 };
		bool found = false;
		int idx = 0;
		for (int i = 0; i < nums.size(); i++)
			if (!((mark1[i / blen] >> (i % blen)) & 1))
			{
				memset(mark2, 0, sizeof(unsigned long long) * len);
				if (findCircular(nums, i, nums[i] / abs(nums[i]), mark1, mark2, 0, idx))
				{
					int index = (idx + nums[idx]) % int(nums.size());
					while (index < 0)
						index += int(nums.size());
					if (idx != index)
					{
						found = true;
						break;
					}
				}
			}
		return found;
	}
	bool findCircular(vector<int>& nums, int i, int direction, unsigned long long *mark1, unsigned long long *mark2, int count, int &idx)
	{
		if ((mark2[i / blen] >> (i % blen)) & 1)
			return count > 1;
		else if ((mark1[i / blen] >> (i % blen)) & 1)
			return false;
		else if (nums[i] * direction < 0)
			return false;
		else
		{
			mark1[i / blen] = mark1[i / blen] ^ (1ULL << (i % blen));
			mark2[i / blen] = mark2[i / blen] ^ (1ULL << (i % blen));
		}
		
		idx = (i + nums[i]) % int(nums.size());	
		while (idx < 0)
			idx += int(nums.size());
		return findCircular(nums, idx, direction, mark1, mark2, count + 1, idx);
	}
};
```
