### 解题思路
Trapping Rain Water

### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int l=0;
        int r=height.size()-1;
        int max_l=0;
        int max_r=0;
        while(l<=r)
        {
            if(max_l<max_r)
            {
                if(height[l]<max_l) ans+=max_l-height[l];
                else max_l=height[l];
                l++;
            }
            else 
            {
                if(height[r]<max_r) ans+=max_r-height[r];
                else max_r=height[r];
                r--;
            }
        }
        return ans;

    }
};
```