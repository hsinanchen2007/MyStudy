bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> mp;
	set<int> st;
	for (int i = 0; i < arr.size(); i++)
	{
		mp[arr[i]]++;
	}
	for (auto it = mp.begin();it != mp.end();it++)
	{
		st.insert((*it).second);
	}
	if (mp.size() == st.size())
		return true;
	return false;
    }