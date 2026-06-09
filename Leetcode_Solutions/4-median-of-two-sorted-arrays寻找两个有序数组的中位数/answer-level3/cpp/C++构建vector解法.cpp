### 解题思路
构建vector

### 代码

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int i=0, j=0;
        for(;i<nums1.size()&&j<nums2.size();)
        {
                if(nums1[i]<=nums2[j])
                {
                    result.push_back(nums1[i]);
                    i++;
                }
                else
                {
                    result.push_back(nums2[j]);
                    j++;
                }
        }
        if(j>=nums2.size()&&i<nums1.size())
        {
            for(int k=i;k<nums1.size();k++)
            {
                result.push_back(nums1[k]);
            }
        }
        if(i>=nums1.size()&&j<nums2.size())
        {
            for(int k=j;k<nums2.size();k++)
            {
                result.push_back(nums2[k]);
            }
        }
        int size1 = result.size();
        if(size1%2==0)
            return (result[size1/2-1]+result[size1/2])/2.0;
        else
            return result[(size1-1)/2];
        
    }
};
```