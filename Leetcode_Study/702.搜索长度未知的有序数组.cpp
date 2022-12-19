/*

https://leetcode.cn/problems/search-in-a-sorted-array-of-unknown-size/

702. 搜索长度未知的有序数组
这是一个交互问题。

您有一个升序整数数组，其长度未知。您没有访问数组的权限，但是可以使用 ArrayReader 接口访问它。你可以调用 
ArrayReader.get(i):

返回数组第ith个索引(0-indexed)处的值(即secret[i])，或者

如果 i  超出了数组的边界，则返回 231 - 1

你也会得到一个整数 target。

如果存在secret[k] == target，请返回索引 k 的值；否则返回 -1

你必须写一个时间复杂度为 O(log n) 的算法。
 

示例 1：

输入: secret = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 存在在 nums 中，下标为 4

示例 2：

输入: secret = [-1,0,3,5,9,12], target = 2
输出: -1
解释: 2 不在数组中所以返回 -1
 

提示：

1 <= secret.length <= 104
-104 <= secret[i], target <= 104
secret 严格递增
通过次数6,844提交次数9,202

*/

/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution100 {
public:
    // 2022.9.6, from https://github.com/grandyang/leetcode/issues/702
    /*
        这道题给了我们一个未知大小的数组，让我们在其中搜索数字。给了我们一个ArrayReader的类，我们可以通过get函数来获得数组中的数字，
        如果越界了的话，会返回整型数最大值。既然是有序数组，又要搜索，那么二分搜索法肯定是不二之选，问题是需要知道数组的首尾两端的位置，
        才能进行二分搜索，而这道题刚好就是大小未知的数组。所以博主的第一个想法就是先用二分搜索法来求出数组的大小，然后再用一个二分搜索
        来查找数字，这种方法是可以通过OJ的。但其实我们是不用先来确定数组的大小的，而是可以直接进行搜索数字，我们实际上是假设数组就有整
        型最大值个数字，在多余的位置上相当于都填上了整型最大值，那么这也是一个有序的数组，我们可以直接用一个二分搜索法进行查找即可，参
        见代码如下：
    */
    int search(const ArrayReader& reader, int target) {
        int left = 0, right = INT_MAX;
        while (left < right) {
            int mid = left + (right - left) / 2, x = reader.get(mid);
            if (x == target) return mid;
            else if (x < target) left = mid + 1;
            else right = mid;
        }
        return -1;
    }
};


class Solution99 {
public:
    // 2022.9.6, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/search-in-a-sorted-array-of-unknown-size.cpp
    // Time:  O(logn)
    // Space: O(1)
    int search(const ArrayReader& reader, int target) {
        int left = 0, right = 19999;
        while (left <= right) {
            auto mid = left + (right-left) / 2;
            auto response = reader.get(mid);
            if (response > target) {
                right = mid - 1;
            } else if (response < target) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};


class Solution98 {
public:
    // 2022.9.6, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/702.%20Search%20in%20a%20Sorted%20Array%20of%20Unknown%20Size
    // OJ: https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/
    // Author: github.com/lzl124631x
    // Time: O(1)
    // Space: O(1)
    int search(const ArrayReader& reader, int target) {
        int minVal = reader.get(0);
        int L = 0, R = 9999 - minVal;
        while (L <= R) {
            int M = (L + R) / 2;
            int val = reader.get(M);
            if (val == target) return M;
            if (val > target) R = M - 1;
            else L = M + 1;
        }
        return -1;
    }
};


class Solution97 {
public:
    // 2022.9.6, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/702.%20Search%20in%20a%20Sorted%20Array%20of%20Unknown%20Size
    // OJ: https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/
    // Author: github.com/lzl124631x
    // Time: O(1)
    // Space: O(1)
    // Ref: https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/discuss/151685/Shortest-and-cleanest-Java-solution-so-far
    int search(const ArrayReader& reader, int target) {
        int L, R = 1;
        while (reader.get(R) < target) R *= 2;
        L = R / 2;
        while (L <= R) {
            int M = (L + R) / 2;
            int val = reader.get(M);
            if (val == target) return M;
            if (val > target) R = M - 1;
            else L = M + 1;
        }
        return -1;
    }
};


class Solution {
 public:
  int search(const ArrayReader& reader, int target) {
    int l = 0;
    int r = 1e4;

    while (l < r) {
      const int m = (l + r) / 2;
      if (reader.get(m) < target)
        l = m + 1;
      else
        r = m;
    }

    return reader.get(l) == target ? l : -1;
  }
};


/************************************************************************************************************/
/************************************************************************************************************/


