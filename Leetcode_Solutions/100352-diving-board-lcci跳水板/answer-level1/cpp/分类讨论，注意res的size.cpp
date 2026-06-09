### 解题思路
- 当k=0时，直接返回
- 当k!=0且shorter==longer时，返回{shorter*k}
- 当k!=0且shorter!=longer时，res[i]=res[i-1]+longer-shorter，注意res的size为k+1

### 代码

```cpp
class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int> res;
        if(k==0)
            return res;
        res.push_back(shorter*k);
        if(shorter==longer)
            return res;
        for(int i=1;i<=k;i++)
            res.push_back(res[i-1]+longer-shorter);
        return res;
    }
};
```