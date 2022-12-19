由于雨水满足水桶定律，选取左右两端为起始值，从较小端开始逐步向中间靠拢即可
```
class Solution {
public:
    int trap(vector<int>& height) {
        int l=height.size();
        if(l<3)return 0;
        int left=height[0],right=height[l-1],i=1,j=l-2,ans=0;
        while(i<=j)
        {
            if(left<=right)
            {
                if(height[i]<=left)
                {
                    ans+=left-height[i];
                }
                else
                {
                    left=height[i];
                }
                i++;
            }
            else
            {
                if(height[j]<=right)
                {
                    ans+=right-height[j];
                }
                else
                {
                    right=height[j];
                }
                j--;
            }
        }
        return ans;
    }
};
```
