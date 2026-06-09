### 解题思路
本题最重要的是要识别出两个字符串是否相等，我使用的是排序+哈希表标记位置

### 代码

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> recorder;
        vector<vector<string>> res;
        string temp;
        for (int i=0;i<strs.size();i++) {
            temp=strs[i];
            sort(temp.begin(),temp.end());
            if (recorder.find(temp)==recorder.end()) {
                res.push_back({strs[i]});
                recorder[temp]=res.size()-1;
            }
            else {
                res[recorder[temp]].push_back(strs[i]);
            }
        }
        return res;
    }
};
```