```
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        
        vector<int> vctOld(heights);
        sort(heights.begin(), heights.end());

        int nCount = 0;
        for(int i = 0; i < heights.size(); i++)
        {
            if(vctOld[i] != heights[i])
            {
                nCount++;
            }
        }

        return nCount;
    }
};
```
