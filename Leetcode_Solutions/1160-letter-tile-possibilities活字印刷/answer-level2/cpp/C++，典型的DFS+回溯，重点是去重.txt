### 解题思路
DFS+回溯。重点是去重，去重有三种方式，一种是用SET自带的去重功能，每次递归只管往SET里面增加字符串，最后统计SET的大小；一种是通过一个大小为26的数组，先算好每个字母的个数，然后再应用DFS；第三种是当判断if ((i > 0) && (str[i] == str[i - 1] && (visit[i - 1] == 0)))时跳过。

### 代码

```cpp
class Solution {
public:
    int ans = 0;
    void dfs(string &str, vector<int> &visit){
        for (int i = 0; i < str.size();i++){
            if ((i > 0) && (str[i] == str[i - 1] && (visit[i - 1] == 0)))
                continue;
            if(visit[i] == 0){
                visit[i] = 1;
                ans++;
                dfs(str, visit);
                visit[i] = 0;
            }
        }
        return;
    }
    int numTilePossibilities(string tiles) {
        vector<int> visit = vector<int>(tiles.size(), 0);
        sort(tiles.begin(), tiles.end());
        dfs(tiles,visit);

        return ans;
    }
};

```