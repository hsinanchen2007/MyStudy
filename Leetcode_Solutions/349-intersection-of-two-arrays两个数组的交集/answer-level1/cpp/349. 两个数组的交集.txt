### 解题思路
此处撰写解题思路
确定左右边界，然后一个数一个数的去确认





### 代码

```cpp
//排序后求交集
//输出结果的唯一性
#include <algorithm>

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> resVec;
        vector<int>::iterator ite1 = nums1.begin();
        vector<int>::iterator ite2 = nums2.begin();
        if(nums1.empty() || nums2.empty())
        {
            return resVec;
        }
        int leftBar = (*ite1 < *ite2) ? (*ite1) : (*ite2);
        int rightBar = (*(nums1.rbegin())> *(nums2.rbegin())) ? (*(nums1.rbegin())) : (*(nums2.rbegin()));
        for(int i = leftBar; i <= rightBar; ++i)
        {
            while( ite1 != nums1.end() && *ite1 < i )
            {
                ++ite1;
            }
            while(ite2 != nums2.end() &&*ite2 < i )
            {
                ++ite2;
            }
            if(ite1 == nums1.end()|| ite2 == nums2.end())
            {
                break;
            }
            else if(*ite1 == *ite2 && *ite2 == i)
            {
                resVec.push_back(i);
            }
        }
        return resVec;
    }

};
```