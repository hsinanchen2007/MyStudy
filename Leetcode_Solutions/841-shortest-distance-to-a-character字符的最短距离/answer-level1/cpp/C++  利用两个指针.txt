### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int left = -10000;
        int right = S.find_first_of(C);
        if(right == -1)
            return {};
        vector<int> res;
        for(int i = 0;i<S.size();i++){
            if(S[i]==C){
                res.push_back(0);
                left = right;
                right = S.find_first_of(C,left+1);
                if(right == -1)
                    right = INT_MAX;
            }else{
                res.push_back(min(i-left,right-i));
            }
        }
        return res;
    }
};
```