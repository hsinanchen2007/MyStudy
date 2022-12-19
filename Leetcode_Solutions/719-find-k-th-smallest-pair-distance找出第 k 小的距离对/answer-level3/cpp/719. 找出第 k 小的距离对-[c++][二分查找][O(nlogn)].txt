前置题目，一定要先做这个：
- [378. 有序矩阵中第K小的元素](https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/)，
- [378.题解](https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/solution/378-you-xu-ju-zhen-zhong-di-kxiao-de-yuan-su-cer-f)

这个题目本质上是在 sorted matrix 中求解第 k 大的数。重点是如何把它转换成 sorted matrix。看下面的注释你就明白了。

但是这个题目和 sorted matrix 有两点不一样：

- 这个题目没有显式的给出 sorted matrix，但是你可以通过计算 nums[j]-nums[i] 来获得矩阵中的值。
- sorted matrix 中所有元素都是有效的，在这题里只有一半的元素有效。


尽管如此，求解的方法还是一样的。你可以借助堆，来做 n-ways merge，也可以使用双二分进行搜索。

下面是使用双二分搜索的方法：

```cpp
class Solution {
public:
    /*
              |  9  5  4  2
            --+------------
            2 | -7 -3 -2  0
            4 | -5 -1  0  2
            5 | -4  0  1  3
            9 |  0  4  5  7
     */
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int lo = 0, hi = nums.back() - nums.front();
        // O(nlogn)
        while (lo < hi) { // O(1)
            int mid = lo + (hi - lo >> 1);
            int count = 0;
            // O(nlogn)
            for (int i = 1; i < nums.size(); ++i) { // O(n)
                count += search(nums, i, mid) - (nums.size() - i); // O(logn)
            }
            if (k <= count) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
    
    // 标准 upperbound 模板。查找第一个 > target 的元素的位置。
    // 也就是 <= target 的元素的个数。
    int search(vector<int>& nums, int row, int target) {
        int lo = nums.size() - row, hi = nums.size();
        while (lo < hi) {
            int mid = lo + (hi - lo >> 1);
            if (nums[row] - nums[nums.size()-1-mid] > target) { // matrix[row][mid]
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};
```
