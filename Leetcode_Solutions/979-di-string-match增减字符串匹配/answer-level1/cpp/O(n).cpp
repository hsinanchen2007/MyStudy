### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> diStringMatch(string S) {
        int n=S.length();
        vector<int> ans;
        int s=0;
        for(int i=0;i<=S.length();i++){
            if(S[i]=='I'){
                ans.push_back(s++);
            }
            else{
                ans.push_back(n--);
            }
        }
        return ans;
    }
};
```