```
class Solution {
public:
    int maxArea(vector<int>& height) {
        int lo = 0;
        int hi = height.size() - 1;
        int result = 0;
        while (lo < hi){
          int len = hi - lo;
          int temp;
          if(height[lo] <= height[hi]){
            temp = len*height[lo];
            ++lo;
          }//if
          else{
            temp = len*height[hi];
            --hi;
          }//else
          if(temp > result) result = temp;
        }//while
        return result;
    }//int
};
```
