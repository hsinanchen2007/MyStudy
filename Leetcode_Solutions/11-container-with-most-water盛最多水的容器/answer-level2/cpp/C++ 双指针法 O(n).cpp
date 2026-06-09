```
class Solution {
public:
    int maxArea(vector<int>& height) {
        int nums = height.size();
        int maxWater = 0;
        for(int i=0, j=nums-1; i<nums, j>i;)
        {
            if(height[i] < height[j])
                maxWater = max(maxWater, height[i] * (j-i)), i++;
            else
                maxWater = max(maxWater, height[j] * (j-i)), j--;
        }
        return maxWater;
    }
};
```
