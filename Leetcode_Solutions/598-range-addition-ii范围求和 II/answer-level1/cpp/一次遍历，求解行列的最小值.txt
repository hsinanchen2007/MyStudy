根据题目要求可知，实际要求解重叠的最小值
``` C++
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if(ops.empty()) return m*n;
        int minA=ops[0][0],minB=ops[0][1];
        for(int i=0;i<ops.size();i++)
        {
            if(ops[i][0]<minA) minA=ops[i][0];
            if(ops[i][1]<minB) minB=ops[i][1]; 
        }
        return minA*minB;
    }
};
```