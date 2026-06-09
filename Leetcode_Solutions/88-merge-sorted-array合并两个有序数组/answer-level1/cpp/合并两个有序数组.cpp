### 解题思路
此处撰写解题思路
一种思路是后移数组1
我的思路从尾部迭代比较,需要处理nums1,和nums2的特殊值
### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1 ,j = n-1,index =n+m-1;
        if(m=0)
        {    while(j>=0)
                nums1[index--] = nums2[j--];
            return;
        }
        if(nums2.empty())
            return;
        while(i>=0 &&j>=0)
        {
            nums1[index--] = nums1[i] > nums2[j] ? nums1[i--]:nums2[j--];
        }
        while(j>=0)
        {
            nums1[index--] = nums2[j--];
        }
    }
};
```