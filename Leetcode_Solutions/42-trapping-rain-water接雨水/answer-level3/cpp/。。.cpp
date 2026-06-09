### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==0) return 0;
        int m=max_element(height.begin(),height.end())-height.begin();
        int res=0,cur=height[0];
        for(int i=1;i<m;i++)
        {
            if(height[i]<cur)
                res+=cur-height[i];
            else
                cur=height[i];
        }
     
        cur=height[n-1];
        for(int i=n-2;i>m;i--)
        {
            if(height[i]<cur)
                res+=cur-height[i];
            else
                cur=height[i];
        }
        return res;
    }
};

```