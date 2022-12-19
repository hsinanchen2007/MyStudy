### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
	{
		vector<bool> dp(s.size() + 1, false);
        set<int> next{0};
		while (!next.empty())
		{
            auto it = next.begin();
            auto i=*it;
            next.erase (it);
			for (auto& word : wordDict)
			{
				size_t newEnd = i + word.size();
				if (newEnd > s.size()) continue;
				if (memcmp(&s[i], &word[0], word.size()) == 0)
				{
					dp[newEnd] = true;
                    next.insert(newEnd);
				}
			}
		}
		return dp.back();
    }
};

```