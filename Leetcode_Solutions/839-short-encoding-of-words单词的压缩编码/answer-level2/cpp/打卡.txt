### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
    set<string>good(words.begin(),words.end());
   // for(int i=0;i<words.size();i++)
    //	good.push_back(words[i]);
    for(set<string>::iterator p=good.begin();p!=good.end();p++)
    {
    	for(int i=1;i<(*p).length();i++)
    		good.erase((*p).substr(i));
    }
    int ans=0;
    for(set<string>::iterator p=good.begin();p!=good.end();p++)
    	ans+=(*p).length()+1;
		return ans;
    }
};
```