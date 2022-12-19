![image.png](https://pic.leetcode-cn.com/c9d33c82977d71f97d101fc1981ce0da749de4267f839f32be4c4f08f038c93a-image.png)

### 解题思路
这道题用hashmap一次遍历即可解决
#### 具体思路
为了归类每一类字符串，首先对字符串排序，排序相同的字符串归为一类，用hashmap存储，用string为key，index为value。
然后将每一类的字符串储存起来即为结果

### 代码

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> retval;
        vector<string> t;
        vector<string> str = strs;
        unordered_map<string, int> hash1;
        int j = 0;
        for(int i = 0; i < strs.size(); i++)
        {
            sort(strs[i].begin(), strs[i].end());
            if(hash1.find(strs[i]) == hash1.end())
            {
                hash1[strs[i]] = j;
                if(retval.size() < j + 1)
                    retval.push_back(t);
                retval[j].push_back(str[i]);
                j++;
            }
            else
            {
                retval[hash1[strs[i]]].push_back(str[i]);
            }
        }
        return retval;
    }
};
```