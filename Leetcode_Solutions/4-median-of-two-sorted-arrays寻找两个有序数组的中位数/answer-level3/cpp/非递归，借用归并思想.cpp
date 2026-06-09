为什么都说不能用归并？
击败95%
```
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int size = size1 + size2;
        if(nums2.empty())
        {
            int i = size1 / 2;
            if(size1 % 2 == 0) return (float)(nums1[i] + nums1[i - 1]) / 2;
            else return nums1[i];
        }
        if(nums1.empty())
        {
            int i = size2 / 2;
            if(size2 % 2 == 0) return (float)(nums2[i] + nums2[i - 1]) / 2;
            else return nums2[i];
        }
        int i1 = 0;
        int i2 = 0;
        int i = size/2;
        vector<int> nums;
        while(i1 < size1 || i2 < size2)
        {
            if(i1 < size1 && i2 < size2)
            {
                if(nums1[i1] < nums2[i2])
                {
                    nums.push_back(nums1[i1]);
                    i1++;
                }
                else
                {
                    nums.push_back(nums2[i2]);
                    i2++;
                }
            }
            else if(i1 < size1)
            {
                nums.insert(nums.end(), nums1.begin() + i1, nums1.end());
                break;
            }
            else if(i2 < size2)
            {
                nums.insert(nums.end(), nums2.begin() + i2, nums2.end());
                break;
            }
        }
        if(size % 2 == 0)
        {
            return (float)(nums[i] + nums[i - 1]) / 2;
        }
        else 
        {
            return nums[i];
        }
    }
```