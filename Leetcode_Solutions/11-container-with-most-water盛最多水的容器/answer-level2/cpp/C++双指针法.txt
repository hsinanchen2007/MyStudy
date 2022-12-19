 int maxArea(vector<int>& height) {
       int i=0,j=height.size()-1;
       int re=0;
        while(i<=j)
        {
            re=max(re,min(height[i],height[j])*(j-i));
            if(height[i]>height[j])
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return re;
    }
思路：每次移动较小的那个下标，因为面积只由最小的下标决定。