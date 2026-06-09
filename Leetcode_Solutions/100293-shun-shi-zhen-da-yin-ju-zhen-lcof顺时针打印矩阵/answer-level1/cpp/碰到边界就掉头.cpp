```
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.size() == 0) return ans;
        int rM = matrix.size();
        int cM = matrix[0].size();
        int startR = 0, starC = 0, endR = rM - 1, endC = cM - 1;
        int curR = 0, curC = -1;
        int count = cM * rM;
       
        while(count > 0) {
            while(curC < endC && count > 0) {
                curC++; 
                ans.push_back(matrix[curR][curC]); 
                count--;
            }
            startR++;
            while(curR < endR && count > 0) {
                curR++;
                ans.push_back(matrix[curR][curC]);
                count--;
                }
            endC--;
            while(curC > starC && count > 0) {
                curC--; 
                ans.push_back(matrix[curR][curC]);
                count--;
            }
            starC++;
            while(curR > startR && count > 0) {
                curR--; 
                ans.push_back(matrix[curR][curC]); 
                count--;
            }
            endR--;
        }
        return ans;
    }
};
```
