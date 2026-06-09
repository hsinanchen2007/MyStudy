```cpp
vector<int> ans;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        for(int i = 0, k = 0;i < nums1.size() && k < nums2.size();i++)
        {
            while(k < nums2.size() && nums2[k] < nums1[i]) k++;
            if(k < nums2.size())
            {
                if(nums2[k] == nums1[i])
                {
                    ans.push_back(nums2[k]);
                    k++;
                }
            }
        }
  return ans;