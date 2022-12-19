### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& n, vector<int>& m) {
        int len = n.size();
        vector<vector<int>> ans;
        if(len == 0){
            ans.push_back(m);
            return ans;
        }
        int idx = 0;
        int inf = 0x7fffffff;
        while(idx < len && n[idx][1] < m[0]){
            ans.push_back(n[idx++]);
        }
        vector<int> ins;
        ins.push_back(min((idx < len ? n[idx][0] : inf), m[0]));
        while(idx < len && n[idx][0] <= m[1]){
            idx++;
        }
        ins.push_back(max((idx > 0 ? n[idx - 1][1] : 0), m[1]));
        ans.push_back(ins);
        while(idx < len){
            ans.push_back(n[idx++]);
        }
        return ans;
    }
};
```