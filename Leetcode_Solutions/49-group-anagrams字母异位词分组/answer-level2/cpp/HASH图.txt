### 解题思路
字典序排序后使用哈希图判断

### 代码

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groupanagrams;
        unordered_map<string,int> p;
        int sub = 0;
        for(int i = 0; i < strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if(p.count(temp)){
                groupanagrams[p[temp]].push_back(strs[i]);
            }
            else {
                vector<string> vec(1,strs[i]);
                groupanagrams.push_back(vec);
                p[temp] = sub++;
            }
        }
        return groupanagrams;
    }
};
```