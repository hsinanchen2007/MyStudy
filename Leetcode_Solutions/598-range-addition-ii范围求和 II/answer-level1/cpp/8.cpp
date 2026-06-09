### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int min1=INT_MAX;
        int min2=INT_MAX;
        if(ops.size()==0)return m*n;
        for(int i=0;i<ops.size();i++){
            min1=min(min1,ops[i][0]);
            min2=min(min2,ops[i][1]);
        }
        return min1*min2;
    }
};
```