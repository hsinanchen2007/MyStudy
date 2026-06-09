class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>a;
        for(int i=0;i<nums1.size();i++)
            for(int j=0;j<nums2.size();j++)
            {
                if(nums2[j]==nums1[i])
                {
                   for(;j<nums2.size();j++)
                   {
                       if(nums2[j]>nums1[i])
                       {
                           a.push_back(nums2[j]);
                           break;
                       }
                       if(j==nums2.size()-1) a.push_back(-1);
                   }
                  break;     
              
                }
            }
        return a;
    }
};