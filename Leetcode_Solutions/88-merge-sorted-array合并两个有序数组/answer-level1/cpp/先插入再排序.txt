### 解题思路
因为题目说了nums1的大小是足够的，所以直接把nums1为0的部分变成nums2的数，然后在进行排序就好了。
![1583287855(1).jpg](https://pic.leetcode-cn.com/015c075545fa1a13c8f6f7d64cbc6fc06058f6b648f5c1f2d8b10d549a85f7dc-1583287855\(1\).jpg)
有意思的是，同样的代码提交三次运行时间都不一样，所以大家也不要盲目崇拜这个执行用时


### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0;i<n;i++)
        {
            nums1[m+i]=nums2[i];
        }
        sort(nums1.begin(),nums1.end());
    }
};
