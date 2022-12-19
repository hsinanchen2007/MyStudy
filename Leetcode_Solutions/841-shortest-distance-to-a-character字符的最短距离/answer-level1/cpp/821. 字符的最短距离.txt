### 解题思路
从前往后扫描一遍
再从后往前取最小值

### 代码

```cpp
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int>res(S.size());
        int cnt=S.size();
        for(int i=0;i<S.size();i++){
            if(S[i]==C) cnt=0;
            res[i]=cnt++;    
        }
        cnt=S.size();
        for(int i=S.size()-1;i>=0;i--){
            if(S[i]==C) cnt=0;
            res[i]=min(cnt,res[i]);
            cnt++;    
        }
        return res;
    }
};
```