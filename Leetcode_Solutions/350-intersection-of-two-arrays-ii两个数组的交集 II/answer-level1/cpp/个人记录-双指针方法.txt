思路：先排序，在一个一个比较，1数组大，2数组向前走一；2数组大，1数组向前走一；一样大同时走1

```
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> Intersect;
        
      
           for(int j=0, i=0;i<nums1.size()&&j<nums2.size();)
           {
            if(nums1[i]>nums2[j])
            {
                j++;
            }
            else if(nums1[i]==nums2[j])
            {
                Intersect.push_back(nums1[i]);
                i++;
                j++;
            }
            else
            {
                i++;
            }
            
        }
        
        return Intersect;
```
