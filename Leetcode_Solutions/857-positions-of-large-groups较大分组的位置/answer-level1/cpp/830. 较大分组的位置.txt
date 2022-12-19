## 用left跟踪当前字符的起始索引
```cpp
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int> > ans;
        int len = S.size(), left=0, cnt=1;
        for(int i=1; i<len; i++){
            if(S[i]!=S[i-1]){
                if(cnt>=3){
                    ans.push_back({left, i-1});
                } 
                cnt = 1;
                left = i;
            }
            else
                cnt++;
        }
        if(cnt>=3){
            ans.push_back({left, len-1});
        } 
        return ans;
    }
};
```