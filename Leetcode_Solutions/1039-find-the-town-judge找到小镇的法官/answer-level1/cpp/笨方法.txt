### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<vector<int>> v(N+1,vector(2,0));
        for(int i=0;i<trust.size();i++){
            v[trust[i][0]][0]++;
            v[trust[i][1]][1]++;
        }
        for(int i=1;i<=N;i++){
            if(v[i][0]==0&&v[i][1]==N-1){
                return i;
            }
        }
        return -1;
    }
};
```