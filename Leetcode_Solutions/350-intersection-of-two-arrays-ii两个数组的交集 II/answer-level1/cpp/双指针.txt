```
class Solution {
public:
    // 双指针法
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int left = 0 , right = 0 ;
        vector<int>  ret ;
        sort( nums1.begin(), nums1.end() ); 
        sort( nums2.begin(), nums2.end() ); 
        // 都重小的开始 小的往后移直至相等 相等同时后移一步继续
        while( left < nums1.size() &&  right < nums2.size() )
        {
            if(nums1[left] <  nums2[right])
            {
                left++ ;
            }
            else if( nums1[left] >  nums2[right] )
            {
                right++;
            }
            else
            {
                ret.push_back(nums1[left] );
                left++ ;
                right++ ;
            }
        }
        return ret ;
    }   
};
```
