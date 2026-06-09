![image.png](https://pic.leetcode-cn.com/fc3e8d5f2a38d0f145cf780199704ee635f44629218d6b2e93d0c1ee43f04cc8-image.png)

```
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;
        // edge case
        if(S.size()<=2) return res;

        int ptr = -1;
        for(int i=0; i<S.size(); i++){
            if(i==S.size()-1 || S[i]!=S[i+1]){
                if(i-ptr>=3){
                    res.push_back({ptr+1, i});
                    ptr = i;
                }
                else
                    ptr = i;
            }
        }
        return res;
    }
};
```
