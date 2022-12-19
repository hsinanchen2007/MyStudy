### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;
        int start = 0;
        int N = S.size();
        for(int i = 1;i<N;i++){
            if(S[i] != S[i-1]){
                if(i-start>=3){
                    res.push_back({start,i-1});
                }
                start = i;
            }
        }
        if(N - start >= 3)
            res.push_back({start,N-1});
        return res;
    }
};
```