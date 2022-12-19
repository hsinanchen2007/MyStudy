### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        map<string,vector<string>>mymap;  //后面的为数组类型
        string tmp;
        for(auto &a : strs){
            tmp=a;
            sort(tmp.begin(),tmp.end());
            mymap[tmp].push_back(a);  //这里可以使用push_back();
        }
        for(const auto &b : mymap){
            res.push_back(b.second);  //注意：这里是b.second
        }
        return res;   
    }
};
```