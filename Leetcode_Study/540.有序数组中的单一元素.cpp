/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */

/*

https://leetcode.cn/problems/single-element-in-a-sorted-array/

540. 有序数组中的单一元素
给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次。

请你找出并返回只出现一次的那个数。

你设计的解决方案必须满足 O(log n) 时间复杂度和 O(1) 空间复杂度。
 

示例 1:

输入: nums = [1,1,2,3,3,4,4,8,8]
输出: 2

示例 2:

输入: nums =  [3,3,7,7,10,11,11]
输出: 10
 

提示:

1 <= nums.length <= 105
0 <= nums[i] <= 105
通过次数98,502提交次数161,946

*/

// @lc code=start
class Solution100 {
public:
    // 2022.6.19, by Hsinan. Hint is O(logn) and sorted vector, that means binary search
    // key is how to determine this is the only one number that happened only once in this
    // given vector
    // Since all other numbers happened twice in this sorted vector, this vector size should
    // be odd number, so size/2 will return a even number, 
    // For example, [1,1,2,3,3,4,4,8,8]
    // Also refer CS-Notes/CyC2018
    int singleNonDuplicate(vector<int>& nums) {
        // sanity check
        if (nums.size() == 1) {
            return nums[0];
        }

        // define left and right pointers, note that now right is a even number
        // so its next one should be same number if there is no other number happened
        // once before
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int middle = left + (right - left) / 2;
            if (middle % 2 == 1) {
                // make sure middle is even number
                middle--;
            }
            if (nums[middle] == nums[middle + 1]) {
                // since we already adjust middle to even number, if the next number
                // is same as current one, there is no number happened once before,
                // then we can adjust middle to next 2, so middle + 2
                left = middle + 2;
            } else {
                // one number happened only once before middle, adjust right pointer 
                // as middle and keep searching
                right = middle;
            }
        }
        return nums[left];
    }
};


class Solution99 {
public:
    // 2022.6.19 from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/single-element-in-a-sorted-array.cpp
    // Time:  O(logn)
    // Space: O(1)
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            auto mid = left + (right - left) / 2;
            if (!(mid % 2 == 0 && mid + 1 < nums.size() &&
                  nums[mid] == nums[mid + 1]) &&
                !(mid % 2 == 1 && nums[mid] == nums[mid - 1])) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return nums[left];
    }
};


class Solution98 {
public:
    // 2022.6.19, from AcWing 
    int singleNonDuplicate(vector<int>& nums) {
        // based on the question, we know the size of given vector will be odd number
        // so let's make it to even by adding a number, the last number + 1
        nums.push_back(nums.back() + 1);

        // now define left and right pointers
        // note that "nums.size() / 2 - 1" will make it to the first number of pair
        // and we expect first and second numbers in pair are same if there is no
        // number happened once before this point
        int left = 0, right = nums.size() / 2 - 1;

        while (left < right) {
            // note that at the beginning right is already around middle
            int middle = left + (right - left) / 2;
            if (nums[middle * 2] != nums[middle * 2 + 1]) right = middle;
            else left = middle + 1;
        }

        // very tricky return!
        return nums[right * 2];
    }
};


class Solution97 {
public:
    // 2022.7.26, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/540.%20Single%20Element%20in%20a%20Sorted%20Array
    // OJ: https://leetcode.com/problems/single-element-in-a-sorted-array/
    // Author: github.com/lzl124631x
    // Time: O(logN)
    // Space: O(1)
    int singleNonDuplicate(vector<int>& A) {
        int L = 0, R = A.size() - 1;
        while (L < R) {
            int M = (L + R) / 2;
            if ((M % 2 == 0 && A[M] == A[M + 1])
               || (M % 2 == 1 && A[M] == A[M - 1])) L = M + 1;
                else R = M;
        }
        return A[L];
    }
};


class Solution96 {
public:
    // 2022.7.26, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/540.%20Single%20Element%20in%20a%20Sorted%20Array
    // OJ: https://leetcode.com/problems/single-element-in-a-sorted-array/
    // Author: github.com/lzl124631x
    // Time: O(logN)
    // Space: O(1)
    int singleNonDuplicate(vector<int>& A) {
        int L = 0, R = A.size() - 1;
        while (L < R) {
            int M = (L + R) / 2;
            if (M % 2) M--;
            if (A[M] == A[M + 1]) L = M + 2;
            else R = M;
        }
        return A[L];
    }
};


class Solution95 {
public:
    // 2022.7.26, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/540.%20Single%20Element%20in%20a%20Sorted%20Array
    // OJ: https://leetcode.com/problems/single-element-in-a-sorted-array/
    // Author: github.com/lzl124631x
    // Time: O(logN)
    // Space: O(1)
    int singleNonDuplicate(vector<int>& A) {
        int N = A.size(), L = 0, R = N - 1;
        auto valid = [&](int M) { // returns `true` is the index of the single element < M
            return M % 2 ? (M + 1 < N && A[M] == A[M + 1]) : (M - 1 >= 0 && A[M] == A[M - 1]);
        };
        while (L <= R) {
            int M = (L + R) / 2;
            if (valid(M)) R = M - 1;
            else L = M + 1;
        }
        return A[R];
    }
};


class Solution94 {
public:
    // 2022.7.26, from https://walkccc.me/LeetCode/problems/0540/
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int m = (l + r) / 2;
            if (m & 1)
                --m;
            if (nums[m] == nums[m + 1])
                l = m + 2;
            else
                r = m;
        }

        return nums[l];
    }
};


class Solution93 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/540
    /*
        这道题给我们了一个有序数组，说是所有的元素都出现了两次，除了一个元素，让我们找到这个元素。如果没有
        时间复杂度的限制，我们可以用多种方法来做，最straightforward的解法就是用个双指针，每次检验两个，
        就能找出落单的。也可以像Single Number里的方法那样，将所有数字亦或起来，相同的数字都会亦或成0，剩下
        就是那个落单的数字。那么由于有了时间复杂度的限制，需要为O(logn)，而数组又是有序的，不难想到要用
        二分搜索法来做。二分搜索法的难点在于折半了以后，如何判断将要去哪个分支继续搜索，而这道题确实判断条件
        不明显，比如下面两个例子：

        1  1  2  2  3

        1  2  2  3  3

        这两个例子初始化的时候left=0, right=4一样，mid算出来也一样为2，但是他们要去的方向不同，如何区分
        出来呢？仔细观察我们可以发现，如果当前数字出现两次的话，我们可以通过数组的长度跟当前位置的关系，计算
        出右边和当前数字不同的数字的总个数，如果是偶数个，说明落单数左半边，反之则在右半边。有了这个规律就
        可以写代码了，为啥我们直接就能跟mid+1比呢，不怕越界吗？当然不会，因为left如何跟right相等，就不会
        进入循环，所以mid一定会比right小，一定会有mid+1存在。当然mid是有可能为0的，所以此时当mid和mid+1
        的数字不等时，我们直接返回mid的数字就可以了，参见代码如下：

        解法一：
    */
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, n = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == nums[mid + 1]) {
                if ((n - 1 - mid) % 2 == 1) right = mid;
                else left = mid + 1;
            } else {
                if (mid == 0 || nums[mid] != nums[mid - 1]) return nums[mid];
                if ((n - 1 - mid) % 2 == 0) right = mid;
                else left = mid + 1;
            }
        }
        return nums[left];
    }
};


class Solution92 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/540
    /*
        下面这种解法是对上面的分支进行合并，使得代码非常的简洁。使用到了亦或1这个小技巧，为什么要亦或1呢，原来我们可以
        将坐标两两归为一对，比如0和1，2和3，4和5等等。而亦或1可以直接找到你的小伙伴，比如对于2，亦或1就是3，对于3，
        亦或1就是2。如果你和你的小伙伴相等了，说明落单数在右边，如果不等，说明在左边，这方法，太叼了有木有，参见代码如下：

        解法二：
    */
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == nums[mid ^ 1]) left = mid + 1;
            else right = mid;
        }
        return nums[left];
    }
};


class Solution91 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/540
    /*
        下面这种解法其实跟上面的方法其实有些类似，虽然没有亦或1，但是将right缩小了一倍，但是在比较的时候，是比较mid2和
        mid2+1的关系的，这样还是能正确的比较原本应该相等的两个小伙伴的值的，其实核心思路和上面一样，参见代码如下：

        解法三：
    */
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() / 2;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid * 2] == nums[mid * 2 + 1]) left = mid + 1;
            else right = mid;
        }
        return nums[left * 2];
    }
};
 

class Solution {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/540
    /*
        下面这种方法其实跟解法二很像，没有用亦或1，但是对mid进行了处理，强制使其成为小伙伴对儿中的第一个位置，然后跟
        另一个小伙伴比较大小，参见代码如下：

        解法四：
    */
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid % 2 == 1) --mid;
            if (nums[mid] == nums[mid + 1]) left = mid + 2;
            else right = mid;
        }
        return nums[left];
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// 2022.8.15, not in top list

  