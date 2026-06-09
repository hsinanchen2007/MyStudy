### 解题思路
此处撰写解题思路

### 代码
思路：
方法个人觉得很戳
1.一开始用的是set，后面提交不通过，提示合并的数组的元素都要存在，因此改为用multiset，multiset自带排序，根据迭代器的叠加跟进tmp_num来找到中位数
2.如果是偶数，则数组中间两组的平均值
3.奇数则数组中间的数
```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        multiset<double> set_num;
        for (int i = 0; i < nums1.size(); i++)
        {
            set_num.insert(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            set_num.insert(nums2[i]);
        }
        int set_half_len = set_num.size() % 2;
        int tmp_num = 0;
        set<double>::iterator ite = set_num.begin();
        while (ite != set_num.end())
        {
            if (set_half_len == 0 && tmp_num == (int)set_num.size() / 2)
            {
                return (*ite + *(--ite)) / 2;
            }
            else if (set_half_len != 0 && tmp_num == (int)set_num.size() / 2)
            {
                return *ite;
            }
            ite++;
            tmp_num++;
        }
        return 0;
    }
};
```