### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        if(n==0)
        {
            if(m&1)
            {
                return nums2[m/2];
            }
            else
                return (nums2[m/2-1]+nums2[m/2])/2.0;
        }
        if(m==0)
        {
            if(n&1)
            {
                return nums1[n/2];
            }
            else
                return (nums1[n/2-1]+nums1[n/2])/2.0;
        }
        if(n<m)
        {
            for(int i=0;i<=n;i++)
            {
                int j=(m+n+1)/2-i;
                if(((i-1>=0&&j<m&&nums1[i-1]<=nums2[j])||i-1<0||j>=m)&&
                   ((j-1>=0&&i<n&&nums1[i]>=nums2[j-1])||i>=n||j-1<0))
                {
                    if((n+m)&1)
                    {
                        int x=(i-1>=0)?nums1[i-1]:-999999;
                        int y=(j-1>=0)?nums2[j-1]:-999999;
                        return max(x,y);
                    }
                    else
                    {
                        int x=(i-1>=0)?nums1[i-1]:-999999;
                        int y=(j-1>=0)?nums2[j-1]:-999999;
                        int l=max(x,y);
                        x=(i<n)?nums1[i]:999999;
                        y=(j<m)?nums2[j]:999999;
                        int r=min(x,y);
                        return (l+r)/2.0;
                    }
                }
            }
        }
        else
        {
            for(int i=0;i<=m;i++)
            {
                int j=(m+n+1)/2-i;
                if(((i-1>=0&&j<n&&nums2[i-1]<=nums1[j])||i-1<0||j>=n)&&
                   ((j-1>=0&&i<m&&nums2[i]>=nums1[j-1])||i>=m||j-1<0))
                {
                    if((n+m)&1)
                    {
                        int x=(i-1>=0)?nums2[i-1]:-999999;
                        int y=(j-1>=0)?nums1[j-1]:-999999;
                        return max(x,y);
                    }
                    else
                    {
                        int x=(i-1>=0)?nums2[i-1]:-999999;
                        int y=(j-1>=0)?nums1[j-1]:-999999;
                        int l=max(x,y);
                        x=(i<m)?nums2[i]:999999;
                        y=(j<n)?nums1[j]:999999;
                        int r=min(x,y);
                        return (l+r)/2.0;
                    }
                }
            }
        }
        return 0;
    }
};
```