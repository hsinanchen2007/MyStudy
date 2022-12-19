```
class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        int n = heights.size();
        
        for(int i = 1;i <= V; ++i){
            int l = K;
            int r = K;
            while(l > 0  && heights[l-1] <= heights[l]){
                l--;
            }
            while(l < K  && heights[l] == heights[l+1]){
                l++;
            }
            while(r < n-1&& heights[r+1] <= heights[r]){
                r++;
            }
            while(r > K  && heights[r] == heights[r-1]){
                r--;
            }
            
            if(heights[l] < heights[K]){
                heights[l]++;
            }else if(heights[r] < heights[K]){
                heights[r]++;
            }else{
                heights[K]++;
            }
        }

        return heights;
    }
};
```