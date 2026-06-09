### 解题思路
**leetcode官方思路：**
方法一 : 合并后排序
最朴素的解法就是将两个数组合并之后再排序。该算法只需要一行(Java是2行)，时间复杂度较差，为O((n+m)log⁡(n+m))O((n + m)\log(n + m))O((n+m)log(n+m))。这是由于这种方法没有利用两个数组本身已经有序这一点。

复杂度分析
时间复杂度 : O((n+m)log⁡(n+m))
空间复杂度 : O(1)

方法三 : 双指针 / 从后往前
复杂度分析
时间复杂度 : O(n+m)
空间复杂度 : O(1)

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //方法三：
        //nums1和nums2的指针
        int p1 = m-1;
        int p2 = n-1;
        //nums1的指针
        int p = m + n - 1;

        //当还有元素进行比较的时候
        while((p1 >= 0) && (p2 >= 0))
            //比较nums1和nums2的元素，把其中最大的最后一个加入nums1
            nums1[p--] = (nums1[p1] < nums2[p2]) ? nums2[p2--] : nums1[p1--];

        //添加nums2中缺少的元素
        while(p2>=0){
            nums1[p--] = nums2[p2--];
        }

        //方法一：
        // int len = m + n;
        // for (int i : nums2) nums1[m++] = i;
        // sort(nums1.begin(), nums1.begin() + len);
    }
};
```