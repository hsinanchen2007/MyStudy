### 解题思路
变位词利用sort后可相同 哈希表添加词下标即可 之后遍历哈希表根据下标添加变位词

### 代码

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
          vector<vector<string>>vec;
          unordered_map<string,vector<int>>map;
          for(int i=0;i<strs.size();i++){
              string tmp=strs[i];
              sort(tmp.begin(),tmp.end());
              map[tmp].push_back(i);
          }
          for(auto it:map){
              auto index=it.second;
              vector<string>res;
              for(auto num:index){
                  res.push_back(strs[num]);
              }
              vec.push_back(res);
          }
        return vec;
    }
};
```