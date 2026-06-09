```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max=0;
        for(int i=0; i<height.size(); i++)
            for(int j=i+1; j<height.size(); j++){
                int t=min(height[i], height[j])*(j-i);
                if(t>max)
                    max=t;
            }
        return max;
    }
};

```
