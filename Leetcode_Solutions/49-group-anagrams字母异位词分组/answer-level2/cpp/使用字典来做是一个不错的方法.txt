### 解题思路
通过字典管理排序后的key所对应的的value，value对应结果列表的index。字典的思路来自于题解。
执行用时 :44 ms, 在所有 cpp 提交中击败了93.30%的用户
内存消耗 :18.5 MB, 在所有 cpp 提交中击败了83.45%的用户

### 代码

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> dict;
        vector<vector<string>> res;
        for(int i=0;i<strs.size();i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if(dict.find(temp)!=dict.end()){
                res[dict[temp]].push_back(strs[i]);
            }
            else{
                dict[temp] = res.size();
                vector<string> tempvector = {strs[i]};
                res.push_back(tempvector);
            }
        }
        return res;
    }
};
```