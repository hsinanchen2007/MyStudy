### 解题思路
出度，入度

### 代码

```cpp
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> inDeep(N+1);
        vector<int> outDeep(N+1);
        for(int i=0;i<trust.size();i++){
            vector<int> temp = trust[i];
            outDeep[temp[0]] = outDeep[temp[0]] + 1;
            inDeep[temp[1]] = inDeep[temp[1]] + 1;
        }

        for(int i=1;i<=N;i++){
            if(inDeep[i]==(N-1) && outDeep[i] == 0){
                return i;
            }
        }
        return -1;
    }
};
```