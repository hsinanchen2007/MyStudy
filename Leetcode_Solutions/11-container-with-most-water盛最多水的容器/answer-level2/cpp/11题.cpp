```
class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0, L = 0, R = height.size()-1;
        while(L < R){
            area = max(area, min(height[L], height[R]) * (R-L));
            if(height[L] < height[R])
                L++;
            else
                R--;
        }
        return area;
    }
};
```
