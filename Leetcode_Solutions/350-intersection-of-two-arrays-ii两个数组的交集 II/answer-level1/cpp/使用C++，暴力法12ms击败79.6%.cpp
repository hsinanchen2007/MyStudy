```
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> out,tmp;
        if(nums1.size()>nums2.size())
        {
            tmp = nums2;
            nums2 = nums1;
            nums1 = tmp;
        }
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                if(nums1[i]==nums2[j])
                {
                    out.push_back(nums1[i]);
                    nums2.erase(nums2.begin()+j);
                    break;
                }
            }
        }
        return out;
    }
};
```

