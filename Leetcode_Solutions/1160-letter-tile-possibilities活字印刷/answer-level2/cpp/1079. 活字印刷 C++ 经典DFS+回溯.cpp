### 解题思路
经典DFS +回溯

### 代码

```cpp
class Solution {
public:
    unordered_set<string> strset;
    void dfs(string str,vector<int> &visit,string &buff){

        for (int i = 0; i < str.size();i++){
            if(visit[i] == 0){
                buff.push_back(str[i]);
                visit[i] = 1;
                strset.insert(buff);
                dfs(str, visit, buff);
                visit[i] = 0;
                buff.pop_back();
            }
        }
        return;
    }
    int numTilePossibilities(string tiles) {
        strset.clear();
        vector<int> visit = vector<int>(tiles.size(), 0);
        string str;
        dfs(tiles,visit,str);

        return strset.size();
    }
};
```