![image.png](https://pic.leetcode-cn.com/efad621465c386bba5bf81f57f7119040b43d3f096698f3a5e2fc863aaf449a2-image.png)
```
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty())return 0;
        int n=height.size();
        int lmax=height[0],leftmaxpos=0;
        for(int i=1;i<n;i++){
            if(lmax<height[i]){
                lmax=height[i];
                leftmaxpos=i;
            }
        }
        int rmax=height[n-1],rightmaxpos=n-1;
        for(int i=n-2;i>=0;i--){
            if(rmax<height[i]){
                rmax=height[i];
                rightmaxpos=i;
            }
        }
        int total=n*lmax;
        for(int i=0;i<n;i++)
            total-=height[i];
        int low;
        if(leftmaxpos!=0){
            low=height[0];
            total-=lmax-low; 
            for(int i=1;i<leftmaxpos;i++){
                if(height[i]>low)
                    low=height[i];
                total-=(lmax-low);
            }
        }
        if(rightmaxpos!=n-1){
            low=height[n-1];
            total-=rmax-low;
            for(int i=n-2;i>rightmaxpos;i--){
                if(height[i]>low)
                    low=height[i];
                total-=(rmax-low);
            }
        }
        return total;
    }
};
```
