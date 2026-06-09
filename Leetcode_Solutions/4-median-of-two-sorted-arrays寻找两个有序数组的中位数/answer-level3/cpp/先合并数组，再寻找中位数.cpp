解题思路：借用了88题合并两个排序数组的双指针解法，使用双指针将两个数组合并为一个排序好的数组sorted，再寻找出中位数

```
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>sorted;
        int pa=0,pb=0,res=0;
        while(pa<nums1.size() || pb<nums2.size())
        {
            if(pa==nums1.size())
            {
                res=nums2[pb++];
            }
            else if(pb==nums2.size())
            {
                res=nums1[pa++];
            }
            else if(nums1[pa]<nums2[pb])
            {
                res=nums1[pa++];
            }
            else
            {
                res=nums2[pb++];
            }
            sorted.push_back(res);
        }
        int mid=(sorted.size()-1)/2;
        if(sorted.size()%2==1)
        {
            return sorted[mid];
        }
        else
        {
            return (sorted[mid]+sorted[mid+1])/2.0;
        }
    }
};
```
