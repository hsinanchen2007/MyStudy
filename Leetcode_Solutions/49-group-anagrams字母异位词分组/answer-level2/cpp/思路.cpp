### 解题思路
本来用暴力法 sort 对比会超时
改成hash的话，有一些细节需要理清下标的标识，和如何对比

### 代码

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      if(strs.size() == 0) return {{}};
      vector<vector<string>> res;
      map<string, int> maps;
      int idx = 0;

      for(int i = 0; i < strs.size(); i++){
        string tmp = strs[i];
        sort(tmp.begin(), tmp.end());
        if(maps.find(tmp) != maps.end()){
          res[maps[tmp]].push_back(strs[i]);
        }else{
          vector<string> v;
          v.push_back(strs[i]);
          res.push_back(v);
          maps[tmp] = idx;
          idx++;
        }
      }

      return res;
    }
};
```