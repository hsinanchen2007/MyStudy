### 解题思路
寻找数组交点

### 代码

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       sort(nums1.begin(),nums1.end());
       sort(nums2.begin(),nums2.end());
       int p1=0,p2=0;
       vector<int> ans;
       while(p1<nums1.size()&&p2<nums2.size()){
           if(nums1[p1]==nums2[p2]){
               ans.push_back(nums1[p1]);

               while(p1+1<nums1.size()&&nums1[p1]==nums1[p1+1]) p1=p1+1;
               ++p1;
               //if(p1==nums1.size()-1&&nums1[p1]==nums1[p1-1]) break;
                if(p1>=nums1.size()) break;
               while(p2+1<nums2.size()&&nums2[p2]==nums2[p2+1]) p2=p2+1;
               ++p2;
               if(p2>=nums2.size()) break;
               //if(p2==nums2.size()-1&&nums2[p2]==nums2[p2-1]) break;
               

           }else if(nums1[p1]<nums2[p2]){
               ++p1;
           }else{
               ++p2;
           }
       }
       return ans;
        
    }
};
```