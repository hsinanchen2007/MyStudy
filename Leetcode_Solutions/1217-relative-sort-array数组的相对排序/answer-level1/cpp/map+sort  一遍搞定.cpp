```
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    map<int, int> mp;
	vector<int> res;
	for(auto i:arr1)
	{
		mp[i]++;
	}

	for (int i = 0; i < arr2.size(); i++)
	{
		while (mp[arr2[i]])
		{
			res.push_back(arr2[i]);
			mp[arr2[i]]--;
		}
		mp.erase(arr2[i]);
	}
	int s = res.size();

	for (auto it = mp.begin(); it != mp.end(); it++)
	{
		while (it->second)
		{
			res.push_back(it->first);
			it->second--;
		}
	}
	sort(res.begin() + s, res.end());
	return res;
    }
};
```
