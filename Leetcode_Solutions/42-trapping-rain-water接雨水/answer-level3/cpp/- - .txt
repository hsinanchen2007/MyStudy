### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<2)
            return 0;
        int left=0,right=height.size()-1;
        int lastheight=0;
        int total=0;


        while(left<right)
        {
            lastheight=height[left]>height[right]?height[right]:height[left];
            for(int i=left+1;i<right;i++)
            {
                
                if(height[i]<=lastheight)
                    {
                        total+=lastheight-height[i];
                        height[i]=lastheight;
                    }
            }
            if(lastheight==height[left])
                while(height[left]<=lastheight  && left<right)
                {
                    left++;
                }
            else if(lastheight==height[right])
                while(height[right]<=lastheight && left<right)
                {
                    right--;
                }
            

        }

        

        return total;

    }

    

};
```