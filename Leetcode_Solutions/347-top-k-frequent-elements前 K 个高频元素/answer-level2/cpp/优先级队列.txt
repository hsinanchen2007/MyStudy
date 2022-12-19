### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
struct ele
{
	int num;
	int fre;
	friend bool operator>(const ele&a, const ele&b)
	{
		return a.fre > b.fre;
	}
	friend bool operator<(const ele&a, const ele&b)
	{
		return a.fre < b.fre;
	}
	bool operator>( const ele&b)
	{
		return fre > b.fre;
	}
};
    vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int>mp;
	int size = nums.size();
	vector<ele>eles;
	ele temp;
	for (int i = 0; i < size; i++)
	{
		if (mp.count(nums[i]) == 0)
		{
			mp[nums[i]] = eles.size();
			temp.fre = 1;
			temp.num = nums[i];
			eles.push_back(temp);
		}
		else
		{
			eles[mp[nums[i]]].fre++;
		}
	}
	priority_queue<ele>q;
	for (int i = 0; i < eles.size(); i++)
		q.push(eles[i]);
	vector<int>re;
	for (int i = 0; i < k; i++)
	{
		re.push_back(q.top().num);
		q.pop();
	}
	return re;
    }
};
```