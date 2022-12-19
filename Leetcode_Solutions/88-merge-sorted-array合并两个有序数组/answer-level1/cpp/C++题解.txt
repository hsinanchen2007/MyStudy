# 思路
从nums1尾部开始，依次将nums1、nums2中数字由大到小填入到nums1中。

# 代码
```c++
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0 )swap(nums1,nums2);
        else
        {
            int i = m - 1;  //i指向nums1中还未处理的最大数字
            int k = m + n - 1;  /*k指向nums1、nums2中最大数字在nums1中的插入位置.
                                因题目描述中“nums1空间可能大于m+n”，因此使用了m+n-1，
                                而不是m.size()-1。*/
            for(int j = n - 1;j >=0;j--)    //j指向nums2中还未处理的最大数字
            {
               while(i >= 0 && nums2[j]<=nums1[i])
              {
                  nums1[k--] = nums1[i--];
              }
              nums1[k--] = nums2[j];
            }
        }
    }
};
```
