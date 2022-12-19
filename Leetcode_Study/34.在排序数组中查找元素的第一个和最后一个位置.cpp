/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

/*

https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/

34. 在排序数组中查找元素的第一个和最后一个位置
给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。


示例 1：

输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]

示例 2：

输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]

示例 3：

输入：nums = [], target = 0
输出：[-1,-1]
 

提示：

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums 是一个非递减数组
-109 <= target <= 109
通过次数565,321提交次数1,337,369

*/

// @lc code=start
class Solution100 {
public:
    // 2022.6.18, from https://programmercarl.com/0034.%E5%9C%A8%E6%8E%92%E5%BA%8F%E6%95%B0%E7%BB%84%E4%B8%AD%E6%9F%A5%E6%89%BE%E5%85%83%E7%B4%A0%E7%9A%84%E7%AC%AC%E4%B8%80%E4%B8%AA%E5%92%8C%E6%9C%80%E5%90%8E%E4%B8%80%E4%B8%AA%E4%BD%8D%E7%BD%AE.html#%E6%80%9D%E8%B7%AF
    // this one looks like LC 704 or LC 35, but it is actually more complicated. We need to find out the left and right borders 
    // as the given vector may contain same value in different elements, although they are all sorted
    // Below code is a copy/paste with some additional comments!
    /*
        这道题目如果基础不是很好，不建议大家看简短的代码，简短的代码隐藏了太多逻辑，结果就是稀里糊涂把题AC了，但是没有
        想清楚具体细节！

        对二分还不了解的同学先做这两题：

        704.二分查找
        35.搜索插入位置
        下面我来把所有情况都讨论一下。

        寻找target在数组里的左右边界，有如下三种情况：

        情况一：target 在数组范围的右边或者左边，例如数组{3, 4, 5}，target为2或者数组{3, 4, 5},target为6，此时应
        该返回{-1, -1}
        情况二：target 在数组范围中，且数组中不存在target，例如数组{3,6,7},target为5，此时应该返回{-1, -1}
        情况三：target 在数组范围中，且数组中存在target，例如数组{3,6,7},target为6，此时应该返回{1, 1}
        这三种情况都考虑到，说明就想的很清楚了。

        接下来，在去寻找左边界，和右边界了。

        采用二分法来去寻找左右边界，为了让代码清晰，我分别写两个二分来寻找左边界和右边界。

        刚刚接触二分搜索的同学不建议上来就想用一个二分来查找左右边界，很容易把自己绕进去，建议扎扎实实的写两个二分分别找
        左边界和右边界

        寻找右边界
        先来寻找右边界，至于二分查找，如果看过704.二分查找就会知道，二分查找中什么时候用while (left <= right)，有什么
        时候用while (left < right)，其实只要清楚循环不变量，很容易区分两种写法。

        那么这里我采用while (left <= right)的写法，区间定义为[left, right]，即左闭右闭的区间（如果这里有点看不懂了，
        强烈建议把704.二分查找这篇文章先看了，704题目做了之后再做这道题目就好很多了）

        确定好：计算出来的右边界是不包含target的右边界，左边界同理。
        可以写出如下代码

        // 二分查找，寻找target的右边界（不包括target）
        // 如果rightBorder为没有被赋值（即target在数组范围的左边，例如数组[3,3]，target为2），为了处理情况一
        int getRightBorder(vector<int>& nums, int target) {
            int left = 0;
            int right = nums.size() - 1; // 定义target在左闭右闭的区间里，[left, right]
            int rightBorder = -2; // 记录一下rightBorder没有被赋值的情况
            while (left <= right) { // 当left==right，区间[left, right]依然有效
                int middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2
                if (nums[middle] > target) {
                    right = middle - 1; // target 在左区间，所以[left, middle - 1]
                } else { // 当nums[middle] == target的时候，更新left，这样才能得到target的右边界
                    left = middle + 1;
                    rightBorder = left;
                }
            }
            return rightBorder;
        }

        寻找左边界
        // 二分查找，寻找target的左边界leftBorder（不包括target）
        // 如果leftBorder没有被赋值（即target在数组范围的右边，例如数组[3,3],target为4），为了处理情况一
        int getLeftBorder(vector<int>& nums, int target) {
            int left = 0;
            int right = nums.size() - 1; // 定义target在左闭右闭的区间里，[left, right]
            int leftBorder = -2; // 记录一下leftBorder没有被赋值的情况
            while (left <= right) {
                int middle = left + ((right - left) / 2);
                if (nums[middle] >= target) { // 寻找左边界，就要在nums[middle] == target的时候更新right
                    right = middle - 1;
                    leftBorder = right;
                } else {
                    left = middle + 1;
                }
            }
            return leftBorder;
        }

        处理三种情况
        左右边界计算完之后，看一下主体代码，这里把上面讨论的三种情况，都覆盖了
    */
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftBorder = getLeftBorder(nums, target);
        int rightBorder = getRightBorder(nums, target);

        // 情况一, it never enter border condition
        if (leftBorder == -2 || rightBorder == -2) return {-1, -1};

        // 情况三
        if (rightBorder - leftBorder > 1) return {leftBorder + 1, rightBorder - 1};

        // 情况二
        return {-1, -1};
    }

private:
     int getRightBorder(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int rightBorder = -2; // 记录一下rightBorder没有被赋值的情况

        while (left <= right) {
            int middle = left + ((right - left) / 2);
            if (nums[middle] > target) {
                right = middle - 1;
            } else { // 寻找右边界，nums[middle] == target的时候更新left
                left = middle + 1;
                rightBorder = left;
            }
        }
        return rightBorder;
    }
    int getLeftBorder(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int leftBorder = -2; // 记录一下leftBorder没有被赋值的情况

        while (left <= right) {
            int middle = left + ((right - left) / 2);
            if (nums[middle] >= target) { // 寻找左边界，nums[middle] == target的时候更新right
                right = middle - 1;
                leftBorder = right;
            } else {
                left = middle + 1;
            }
        }
        return leftBorder;
    }
};


class Solution99 {
public:
    // 2022.6.18, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/find-first-and-last-position-of-element-in-sorted-array.cpp
    // it uses C++ STL's lower_bound and upper_bound, to get the min/max borders based on given target in given vector
    // Time:  O(logn)
    // Space: O(1)
    vector<int> searchRange(vector<int>& nums, int target) {
        // get lower/upper borders, this is a good example to re-use existing C++ STL
        // that it can help to find out borders from a sorted vector based on target
        const auto start = lower_bound(cbegin(nums), cend(nums), target);
        const auto end = upper_bound(cbegin(nums), cend(nums), target);

        // if target is found in given vector, get its range
        if (start != cend(nums) && *start == target) {
            return {static_cast<int>(start - cbegin(nums)),
                    static_cast<int>(end - cbegin(nums) - 1)};
        }

        // else if target is not in the given vector, return {-1, -1}
        return {-1, -1};
    }
};

class Solution98 {
public:
    // 2022.6.18, from https://www.guozet.me/leetcode/summary/2019-01-15-Algorithms-Binary-Search.html
    /*
        Binary search is an efficient algorithm for finding an item from a sorted list of items. It works by 
        repeatedly dividing in half the portion of the list that could contain the item, until you've narrowed 
        down the possible locations to just one.

        For example, binary search in the guessing game. Here, try it for a number from 1 to 300. You should 
        need no more than 9 guesses.

        Here's a step-by-step description of using binary search to play the guessing game:

        Let min = 1 min=1 and max = nmax=n.
        Guess the average of maxmax and minmin, rounded down so that it is an integer.
        If you guessed the number, stop. You found it!
        If the guess was too low, set minmin to be one larger than the guess.
        If the guess was too high, set maxmax to be one smaller than the guess.
        Go back to step two.
        The feature for the Binary Search is: Fast, Fast, Fast. O(log(n))

        What is Binary Search?

        The requirment for the Binary Search is the sorted input data.

        Each node needs to make decision go to left or right. For the Binary Search method, the input data will 
        include three partition: Mid, left array, right array.

        If the mid number is less than the target number, then go to right array to find the target number.
        If the mid number is larger than the target number, then go to left array to find the target number.
        When you go to the left or right way, you can choose the recursive function or not recursive function to 
        solve it.

        The answer for this question is that the last mid point is the target number which you want to find 
        if there is a target number in the array. If there is no target number in the array, when you find the 
        last mid number and then you can return false or use this number to do something.

        Why we need Binary Search.


        There are some states for the above picture:

        The O(eval) is the time to compare the mid number with the target number and the search space need to 
        move to left part or right part. It may be: O(1), O(n), or O(logn).
        SO, you can use the input dataset range to choose which mothod you can use to solve this problem. 
        There are two tips which you can use to think which method is good for you to solve this problem.

        Template
        Template 1: Unique and sorted elements


        Include the left data, but not include the right side.

        def binary_search(1,r):
        while l < r:
            m = 1 + (r-1) // 2
            if f(m): return m #optional
            if g(m):
            r = m
            else:
            l + m + 1
        return l #or not find, return the min number

        As the above picture, if the input element is unique and sorted, then we can easily use this template 
        to deal with these similar problems. Like the example 1.

        If the Input data's element is not unique. And it have repetitive numbers.

        Template 2: Repetitive and sorted elements


        The lower_bound function will return the first index of i, such that A[i] >= x, So, when you find it, 
        you need to check out if this A[i] may not = x. If the index > len, then there is no number > this.

        Example

        Leetcode 69

        It is not way to find the real number to fit the requrtment. So, we can find the number the first time 
        bigger than the input.

        Relative Questions
        二分查找算法在实际使用中可能会出现各种变体，我们要抓住有序的特点，一旦发现输入有有序的特点，我们就可以考虑是否可以运用
        二分查找算法来解决该问题。

        Questions:

        Search In Rotated Sorted Array
        Search In Rotated Sorted Array II
        Search Insert Position
        Online Election
        Preimage Size of Factorial Zeroes Function
        K th Smallest Prime Fraction
        Find Smallest Letter Greater Than Target
        Find K th Smallest Pair Distance
        Relative Ranks
        Find K th Smallest Pair Distance
        Search a 2D Matrix
        Sqrt x 3

        Upper Bound

        Find First And Last Position Of Element In Sorted Array(LC.34)
        问题：在一个有序的数组中，找到一个元素的第一个位置以及最后一个位置。
        class Solution {
        public:
            vector<int> searchRange(vector<int>& nums, int target) {
                vector<int> res(2, -1);
                int left = 0, right = nums.size() - 1;
                while (left < right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] < target)
                    left = mid + 1;
                else
                    right = mid;
                }
                if (nums[right] != target) return res;
                res[0] = right;

                // Do the second Binary Search
                right = nums.size();
                while (left < right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] <= target)
                    left = mid + 1;
                else
                    right = mid;
                }
                res[1] = left - 1;
                return res;
            }
        };
        
        Search Insert Position(LC.35)
        在一个有序数组中找到一个位置，插入 target 的数字，插入之后，数组依旧保持有序
        class Solution {
        public:
            int searchInsert(vector<int>& nums, int target) {
                if (nums.back() < target) return nums.size();
                int left = 0, right = nums.size() - 1;
                while (left < right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] == target)
                    return mid;
                else if (nums[mid] < target)
                    left = mid + 1;
                else
                    right = mid;
                }
                return right;
            }
        };

        Binary Search(LC.704)
        Problem: Given a sorted (in ascending order) integer array nums of n elements and a targetvalue, 
        write a function to search target in nums. If target exists, then return its index, otherwise 
        return -1.
        Time complexity: O(log n), Space complexity: O(1)
        class Solution {
        public:
            int search(vector<int>& nums, int target) {
                int left = 0, right = nums.size();
                while (left < right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] == target) return mid;
                else if (nums[mid] < target) left = mid + 1;
                else right = mid;
                }
                return -1;
            }
        };

        Time Based Key Value Store(LC.981)
        Solution: HashTable + Map
        class TimeMap {
            public:
            TimeMap() {}

            void set(string key, string value, int timestamp) {
                s_[key].emplace(timestamp, std::move(value));
            }

            string get(string key, int timestamp) {
                auto m = s_.find(key);
                if (m == s_.end()) return "";
                auto it = m->second.upper_bound(timestamp);
                if (it == begin(m->second)) return "";
                return prev(it)->second;
            }
            private:
            unordered_map<string, map<int, string>> s_; 
        };
        
        Sqrt x 3(LC.69)
        Time Complexity: O(log n), Space Complexity: O(1)
        class Solution {
        public:
            int mySqrt(int x) {
                if (x < 2) return x;
                int left = 0, right = x / 2 + 1;
                while (left < right) {
                int mid = left + (right - left) / 2;
                // Move left == right, then we need to move left back
                x / mid < mid ? right = mid : left = mid + 1;
                }

                return left - 1;
            }
        };

        Rotated & Peak
        Search In Rotated Sorted Array(LC.33)
        Time complexity: O(log n) Space complexity: O(1)
        class Solution {
        public:
            int search(vector<int>& nums, int target) {
                int left = 0, right = nums.size();
                while (left != right) {
                    const int mid = left + (right - left) / 2;
                    // Find the Target at the mid index.
                    if (nums[mid] == target) return mid;

                    // There are sorted elements in the left part.
                    if (nums[left] <= nums[mid]) {
                        nums[mid] > target && nums[left] <= target ? right = mid : left = mid + 1;
                    } else {
                        nums[mid] < target && nums[right - 1] >= target ? left = mid + 1 : right = mid; 
                    }
                }

                return -1;
            }
        };
        
        Search In Rotated Sorted Array II(LC.81)
        Time complexity: O(logn) Space complexity: O(1)
        class Solution {
        public:
            bool search(vector<int>& nums, int target) {
                int left = 0, right = nums.size();
                while (left != right) {
                    const int mid = left + (right - left) / 2;
                    // Find the Target at the mid index.
                    if (nums[mid] == target) return true;

                    // There are sorted elements in the left part.
                    if (nums[left] < nums[mid]) {
                        if (nums[left] <= target && nums[mid] > target) {
                            right = mid;
                        } else {
                            left = mid + 1;
                        }
                    } else if (nums[left] == nums[mid]) {
                        left++;
                    } else {  // There are sorted elements in the right part.
                        if (nums[mid] < target && nums[right - 1] >= target) {
                            left = mid + 1;
                        } else {
                            right = mid;
                        }
                    }
                }
                return false;
            }
        };
        
        Find Minimum in Rotated Sorted Array(LC.153))
        Time Complexity: O(log n), Space Complexity:O(1)
        class Solution {
        public:
            int findMin(vector<int>& nums) {
                int left = 0, right = nums.size() - 1;
                if (nums[left] < nums[right]) return nums[0];

                while (left < right - 1) {
                    int mid = left + (right - left) / 2;

                    // If the mid value > left value, then move the right part search.
                    if (nums[mid] > nums[left]) left = mid;
                    else right = mid;
                }
                return min(nums[left], nums[right]);
            }
        };
        
        Find Minimum in Rotated Sorted Array II(LC.154)
        class Solution {
        public:
            int findMin(vector<int>& nums) {
                int left = 0, right = nums.size() - 1, ans = nums[0];
                if (nums[left] < nums[right]) return nums[0];

                while (left < right - 1) {
                    int mid = left + (right - left) / 2;

                    // If the mid value > left value, then move the right part search.
                    if (nums[left] < nums[mid]) {
                        ans = min(ans, nums[left]);
                        left = mid;
                    }
                    else if (nums[left] > nums[mid]) right = mid;
                    else ++left;
                }
                return min(ans, min(nums[left], nums[right]));
            }
        };
        
        Find Peak Element(LC.162)
        题目要求是 O(log n) 的时间复杂度，考虑使用类似于二分查找法来缩短时间。由于只是需要找到任意一个峰值，那么我们在
        确定二分查找折半后中间那个元素后，和紧跟的那个元素比较下大小，如果大于，则说明峰值在前面，如果小于则在后面。
        这样就可以找到一个峰值了。
        class Solution {
        public:
            int findPeakElement(vector<int>& A) {
                // Binary Search
                int left = 0, right = A.size() - 1;
                while (left < right) {
                    int mid = left + (right - left) / 2;
                    if (A[mid] < A[mid + 1]) left = mid + 1; // For the left part
                    else right = mid;
                }
                return left;
            }
        };
        
        Peak Index in a Mountain Array(LC.852)
        Time complexity: O(log n), Space Complexity: O(1)
        class Solution {
        public:
            int peakIndexInMountainArray(vector<int>& A) {
                // Binary Search
                int left = 0, right = A.size();
                while (left < right) {
                    int mid = left + (right - left) / 2;
                    if (A[mid] > A[mid + 1]) right = mid; // For the left part
                    else left = mid + 1;
                }
                return left;
            }
        };
    */
    // need to add one extra sanity check before binary search
    vector<int> searchRange(vector<int>& nums, int target) {
        // define the answer vector to return
        // it alreays says size 2 and initializs them as -1
        vector<int> res(2, -1);

        // sanity check added by Hsinan
        // when given vector is [] and tagget is 0, without this sanity check,
        // LC will fail when submitting the answer
        if (nums.size() == 0) return {-1, -1};

        // define two pointers
        int left = 0, right = nums.size() - 1;

        // Do the first Binary Search
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        if (nums[right] != target) return res;

        // update answer
        res[0] = right;

        // Do the second Binary Search
        right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }
        // update answer
        res[1] = left - 1;

        return res;
    }
};


class Solution97 {
public:
    // 2022.6.18, from AcWing https://www.acwing.com/video/1357/
    vector<int> searchRange(vector<int>& nums, int target) {
        // sanity check
        if (nums.empty()) return {-1, -1};

        // define left and right pointers
        int left = 0, right = nums.size() -1;
        while (left < right) {
            int middle = left + right >> 1;
            if (nums[middle] >= target) right = middle;
            else left = middle + 1;
        }
        // if not found, that means there is no such target
        if (nums[right] != target) return {-1, -1};

        // similar to LC 35, right index here is the condition when left >= right
        // so right now here is the left border
        int L = right;

        // for second binary search to find the right border
        left = 0, right = nums.size() - 1;
        while (left < right) {
            int middle = left + right + 1 >> 1;
            if (nums[middle] <= target) left = middle;
            else right = middle - 1;
        }

        return {L, right};
    }
};


class Solution96 {
public:
    // 2022.7.24, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/34.%20Find%20First%20and%20Last%20Position%20of%20Element%20in%20Sorted%20Array
    // OJ: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
    /*
        Solution 1. Binary Search (L <= R)
        Pro:
        M is always (L + R) / 2
        Symmetrical and no-brainer: L = M + 1 and R = M - 1.

        Con:
        L and R might go out of boundary.
        Solution: Simply do a out-of-boundary check.
        Need to think about using L or R in the end.
        Solution: Take the first binary search for example, if A[M] < target, we move L. 
        If A[M] >= target, we move R. In the end, L and R will swap order, so R will point 
        to the last A[i] < target, and L will point to the first A[i] >= target. Thus, 
        we should use L as the left boundary.
    */
    // Author: github.com/lzl124631x
    // Time: O(logN)
    // Space: O(1)
    vector<int> searchRange(vector<int>& A, int target) {
        if (A.empty()) return {-1,-1};
        int N = A.size(), L = 0, R = N - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] < target) L = M + 1;
            else R = M - 1;
        }
        if (L >= N || A[L] != target) return {-1,-1};
        int left = L;
        L = 0, R = N - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] > target) R = M - 1;
            else L = M + 1;
        }
        return {left, R};
    }
};


class Solution95 {
public:
    // 2022.7.24, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/34.%20Find%20First%20and%20Last%20Position%20of%20Element%20in%20Sorted%20Array
    // OJ: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
    /*
        Solution 2. Binary Search (L < R)
        Pro:
        In the end, L and R points to the same position.

        Con:
        Need to think about setting L = M or R = M. Solution: Take the first binary search 
        for example. If A[M] < target, we want to move L to M + 1 because A[M] != target. 
        If A[M] >= target, we want to move R to M. Since we are using R = M, we need to make 
        sure M != R, thus we should round down M as (L + R) / 2.
        Now consider the second binary search. If A[M] > target, we want to move R to M - 1. 
        If A[M] <= target, we want to move L to M. Since we are using L = M, we need to make 
        sure M != R, thus we should round up M as (L + R + 1) / 2.

        Overall, if we do L = M, we round up. If we do R = M, we round down.

        Round up: (L + R) / 2 or L + (R - L) / 2.

        Round down: (L + R + 1) / 2 or R - (R - L) / 2.
    */
    // Author: github.com/lzl124631x
    // Time: O(logN)
    // Space: O(1)
    vector<int> searchRange(vector<int>& A, int target) {
        if (A.empty()) return {-1,-1};
        int N = A.size(), L = 0, R = N - 1;
        while (L < R) {
            int M = (L + R) / 2;
            if (A[M] < target) L = M + 1;
            else R = M;
        }
        if (A[L] != target) return {-1,-1};
        int left = L;
        L = 0, R = N - 1;
        while (L < R) {
            int M = (L + R + 1) / 2;
            if (A[M] > target) R = M - 1;
            else L = M;
        }
        return {left, L};
    }
};


class Solution94 {
public:
    // 2022.7.24, from https://walkccc.me/LeetCode/problems/0034/
    // Time: O(log n)
    // Space: O(1)
    vector<int> searchRange(vector<int>& nums, int target) {
        const int l = lower_bound(begin(nums), end(nums), target) - begin(nums);
        if (l == nums.size() || nums[l] != target)
        return {-1, -1};
        const int r = upper_bound(begin(nums), end(nums), target) - begin(nums) - 1;
        return {l, r};
    }
};


class Solution93 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/34
    /*
        这道题让我们在一个有序整数数组中寻找相同目标值的起始和结束位置，而且限定了时间复杂度为 O(logn)，
        这是典型的二分查找法的时间复杂度，所以这里也需要用此方法，思路是首先对原数组使用二分查找法，
        找出其中一个目标值的位置，然后向两边搜索找出起始和结束的位置，代码如下：

        解法一:
    */
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx = search(nums, 0, nums.size() - 1, target);
        if (idx == -1) return {-1, -1};
        int left = idx, right = idx;
        while (left > 0 && nums[left - 1] == nums[idx]) --left;
        while (right < nums.size() - 1 && nums[right + 1] == nums[idx]) ++right;
        return {left, right};
    }
    int search(vector<int>& nums, int left, int right, int target) {
        if (left > right) return -1;
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) return search(nums, mid + 1, right, target);
        else return search(nums, left, mid - 1, target);
    }
};


class Solution92 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/34
    /*
        可能有些人会觉得上面的算法不是严格意义上的 O(logn) 的算法，因为在最坏的情况下会变成 O(n)，
        比如当数组里的数全是目标值的话，从中间向两边找边界就会一直遍历完整个数组，那么下面来看一种
        真正意义上的 O(logn) 的算法，使用两次二分查找法，第一次找到左边界，第二次调用找到右边界即可，
        具体代码如下：

        解法二：
    */
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        if (right == nums.size() || nums[right] != target) return res;
        res[0] = right;
        right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) left = mid + 1;
            else right = mid;
        }
        res[1] = right - 1;
        return res;
    }
};


class Solution {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/34
    /*
        其实我们也可以只使用一个二分查找的子函数，来同时查找出第一个和最后一个位置。如何只用查找
        第一个大于等于目标值的二分函数来查找整个范围呢，这里用到了一个小 trick，首先来查找起始
        位置的 target，就是在数组中查找第一个大于等于 target 的位置，当返回的位置越界，或者该
        位置上的值不等于 target 时，表示数组中没有 target，直接返回 {-1, -1} 即可。若查找到了 
        target 值，则再查找第一个大于等于 target+1 的位置，然后把返回的位置减1，就是 target 
        的最后一个位置，即便是返回的值越界了，减1后也不会越界，这样就实现了使用一个二分查找函数
        来解题啦，参见代码如下：

        解法三：
    */
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = firstGreaterEqual(nums, target);
        if (start == nums.size() || nums[start] != target) return {-1, -1};
        return {start, firstGreaterEqual(nums, target + 1) - 1};
    }
    int firstGreaterEqual(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        return right;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

