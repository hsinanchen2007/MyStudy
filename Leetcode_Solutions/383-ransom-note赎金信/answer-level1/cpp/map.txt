
### 代码

```cpp
class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) 
	{
		unordered_map<char, int> mymap;
		for(int i=0;i<magazine.size();++i)
			mymap[magazine[i]]++;
		for (int i = 0; i < ransomNote.size(); ++i)
		{
			if (mymap[ransomNote[i]] > 0)
				mymap[ransomNote[i]]--;
			else
				return false;
		}
		return true;
	}
};
```