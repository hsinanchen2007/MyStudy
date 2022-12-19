### 解题思路
1、俩集合A、B从小到大排序
2、两个指针分别指向A、B首元素，若所指元素相等，加入公共集合，俩指针加加；否则，较小的指针加加；循环直至一个指针遍历结束。

### 代码

```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> both;
        vector<int>::iterator it1 = nums1.begin();
        vector<int>::iterator it2 = nums2.begin();
        while(it1 != nums1.end() && it2 != nums2.end())
        {
            if(*it1==*it2)
            {
                both.push_back(*it1);
                it1++; it2++;
            }
            else if(*it1 > * it2)
                it2++;
            else
                it1++;
        }
        return both;
    }
       
};

```