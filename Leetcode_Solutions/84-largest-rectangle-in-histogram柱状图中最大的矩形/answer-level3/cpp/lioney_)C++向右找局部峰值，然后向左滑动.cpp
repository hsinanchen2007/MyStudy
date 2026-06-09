```
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0, n = heights.size();
        for(int i=0; i<n; i++) {
            if(i+1 < n && heights[i] <= heights[i+1])
                continue;
            int minH = heights[i];
            for(int j=i; j>=0; j--) {
                minH = min(heights[j], minH);
                res = max(res, minH*(i-j+1));
            }
        }
        return res;
    }
};
```
