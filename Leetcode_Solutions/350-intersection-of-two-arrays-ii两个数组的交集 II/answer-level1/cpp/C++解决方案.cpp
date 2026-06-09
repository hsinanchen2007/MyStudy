### 解题思路
此题接上一题两个数组的交集1
### 代码

```cpp
class Solution {
public:
//下面这一段可以用来解决两个数组的交集的第一种类型
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1(nums1.begin(), nums1.end());
        set<int> set2(nums2.begin(), nums2.end());
        vector<int> TmpArray;
        vector<int> nums3;
        int count1, count2;
        set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), insert_iterator<vector<int>>(TmpArray, TmpArray.begin()));
//接着下面这一段，可以求解考虑元素出现次数时的解法
        for (int i = 0; i < TmpArray.size(); i++)
        {
            count1 = count(nums1.begin(), nums1.end(), TmpArray[i]);
            count2 = count(nums2.begin(), nums2.end(), TmpArray[i]);
            if (count1 < count2)
            {
                nums3.insert(nums3.begin(), count1, TmpArray[i]);
            }
            else
            {
                nums3.insert(nums3.begin(), count2, TmpArray[i]);
            }
        
        }
        return nums3;
    }
};
```