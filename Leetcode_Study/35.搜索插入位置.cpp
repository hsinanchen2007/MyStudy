/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

/*

https://leetcode.cn/problems/search-insert-position/

35. 搜索插入位置
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 O(log n) 的算法。
 

示例 1:

输入: nums = [1,3,5,6], target = 5
输出: 2

示例 2:

输入: nums = [1,3,5,6], target = 2
输出: 1

示例 3:

输入: nums = [1,3,5,6], target = 7
输出: 4
 

提示:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums 为 无重复元素 的 升序 排列数组
-104 <= target <= 104
通过次数834,575提交次数1,843,925

*/

// @lc code=start
class Solution100 {
public:
    // 2022.6.18, by Hsinan, follow LC 704, use soluition 1 template
    // also from https://programmercarl.com/0035.%E6%90%9C%E7%B4%A2%E6%8F%92%E5%85%A5%E4%BD%8D%E7%BD%AE.html#%E6%80%9D%E8%B7%AF
    int searchInsert(vector<int>& nums, int target) {
        // define left and right pointers
        int left = 0;
        int right = nums.size() - 1;

        // use left <= right condition in while
        while (left <= right) {
            // avoid overflow
            int middle = left + (right - left) / 2;

            // use same rtemplate as LC 704
            if (nums[middle] > target) {
                right = middle - 1;
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else {
                return middle;
            }
        }

        // the tricky part is the end of return answer 
        // when it is not found in the while loop,
        // that means left > right, so the return should be
        // either (right + 1) or left
        // {1, 3, 5, 6}, target 2
        return (right + 1);
    }
};


class Solution99 {
public:
    // 2022.7.24, from https://programmercarl.com/0035.%E6%90%9C%E7%B4%A2%E6%8F%92%E5%85%A5%E4%BD%8D%E7%BD%AE.html#%E6%80%9D%E8%B7%AF
    /*
        这道题目不难，但是为什么通过率相对来说并不高呢，我理解是大家对边界处理的判断有所失误导致的。
        这道题目，要在数组中插入目标值，无非是这四种情况。

        35_搜索插入位置3

        目标值在数组所有元素之前
        目标值等于数组中某一个元素
        目标值插入数组中的位置
        目标值在数组所有元素之后
        这四种情况确认清楚了，就可以尝试解题了。

        接下来我将从暴力的解法和二分法来讲解此题，也借此好好讲一讲二分查找法。

        class Solution {
        public:
            int searchInsert(vector<int>& nums, int target) {
                for (int i = 0; i < nums.size(); i++) {
                // 分别处理如下三种情况
                // 目标值在数组所有元素之前
                // 目标值等于数组中某一个元素
                // 目标值插入数组中的位置
                    if (nums[i] >= target) { // 一旦发现大于或者等于target的num[i]，那么i就是我们要的结果
                        return i;
                    }
                }
                // 目标值在数组所有元素之后的情况
                return nums.size(); // 如果target是最大的，或者 nums为空，则返回nums的长度
            }
        };

        既然暴力解法的时间复杂度是，就要尝试一下使用二分查找法。
        35_搜索插入位置4

        大家注意这道题目的前提是数组是有序数组，这也是使用二分查找的基础条件。
        以后大家只要看到面试题里给出的数组是有序数组，都可以想一想是否可以使用二分法。
        同时题目还强调数组中无重复元素，因为一旦有重复元素，使用二分查找法返回的元素下标可能不是唯一的。
        大体讲解一下二分法的思路，这里来举一个例子，例如在这个数组中，使用二分法寻找元素为5的位置，并返回其下标。

        35_搜索插入位置5
        二分查找涉及的很多的边界条件，逻辑比较简单，就是写不好。
        相信很多同学对二分查找法中边界条件处理不好。
        例如到底是 while(left < right) 还是 while(left <= right)，到底是right = middle呢，
        还是要right = middle - 1呢？
        
        这里弄不清楚主要是因为对区间的定义没有想清楚，这就是不变量。
        要在二分查找的过程中，保持不变量，这也就是循环不变量 （感兴趣的同学可以查一查）。

        二分法第一种写法
        以这道题目来举例，以下的代码中定义 target 是在一个在左闭右闭的区间里，也就是[left, right] （这个很重要）。
        这就决定了这个二分法的代码如何去写，大家看如下代码：
        大家要仔细看注释，思考为什么要写while(left <= right)， 为什么要写right = middle - 1。
        时间复杂度：O(log n)
        时间复杂度：O(1)
    */
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1; // 定义target在左闭右闭的区间里，[left, right]
        while (left <= right) { // 当left==right，区间[left, right]依然有效
            int middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2
            if (nums[middle] > target) {
                right = middle - 1; // target 在左区间，所以[left, middle - 1]
            } else if (nums[middle] < target) {
                left = middle + 1; // target 在右区间，所以[middle + 1, right]
            } else { // nums[middle] == target
                return middle;
            }
        }
        // 分别处理如下四种情况
        // 目标值在数组所有元素之前  [0, -1]
        // 目标值等于数组中某一个元素  return middle;
        // 目标值插入数组中的位置 [left, right]，return  right + 1
        // 目标值在数组所有元素之后的情况 [left, right]， 因为是右闭区间，所以 return right + 1
        return right + 1;
    }
};


class Solution98 {
public:
    // 2022.7.24, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0035.%E6%90%9C%E7%B4%A2%E6%8F%92%E5%85%A5%E4%BD%8D%E7%BD%AE.md
    /*
        二分法第二种写法
        如果说定义 target 是在一个在左闭右开的区间里，也就是[left, right) 。

        那么二分法的边界处理方式则截然不同。

        不变量是[left, right)的区间，如下代码可以看出是如何在循环中坚持不变量的。

        大家要仔细看注释，思考为什么要写while (left < right)， 为什么要写right = middle。
    */
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n; // 定义target在左闭右开的区间里，[left, right)  target
        while (left < right) { // 因为left == right的时候，在[left, right)是无效的空间
            int middle = left + ((right - left) >> 1);
            if (nums[middle] > target) {
                right = middle; // target 在左区间，在[left, middle)中
            } else if (nums[middle] < target) {
                left = middle + 1; // target 在右区间，在 [middle+1, right)中
            } else { // nums[middle] == target
                return middle; // 数组中找到目标值的情况，直接返回下标
            }
        }
        // 分别处理如下四种情况
        // 目标值在数组所有元素之前 [0,0)
        // 目标值等于数组中某一个元素 return middle
        // 目标值插入数组中的位置 [left, right) ，return right 即可
        // 目标值在数组所有元素之后的情况 [left, right)，因为是右开区间，所以 return right
        return right;
    }
};


class Solution97 {
public:
    // 2022.6.18, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/search-insert-position.cpp
    // Time:  O(logn)
    // Space: O(1)
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            const auto mid = left + (right -left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};


class Solution96 {
public:
    // 2022.6.18, from AcWing https://www.acwing.com/video/1358/
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int middle = left + right >> 1;
            if (nums[middle] >= target) right = middle;
            else left = middle + 1;
        }
        return left;
    }
};


class Solution95 {
public:
    // 2022.6.19, from https://ke.algomooc.com/detail/v_6281aa6de4b01a4851ff623b/3?from=p_6281a4bbe4b01a4851ff5f23&type=6&parent_pro_id=
    // 登录 AlgoMooc 官网获取更多算法图解
    // https://www.algomooc.com
    // 作者：程序员吴师兄
    // 代码有看不懂的地方一定要私聊咨询吴师兄呀
    // 搜索插入位置(35):https://leetcode-cn.com/problems/search-insert-position/
    int searchInsert(vector<int>& nums, int target) {
        // left 为当前区间最左侧的元素，可以获取到
        int left = 0;

        // right 为当前区间最右侧的元素，可以获取到
        int right = nums.size() - 1;

        // 在 while 循环里面，left 不断的 ++，而 right 不断的 --
        // 在区间 nums[left..right] 里查找第 1 个大于等于 target 的元素的下标
        while(left <= right) {

            // left + (right - left) / 2 和 (left + right) / 2 的结果相同
            // 但是使用 left + (right - left) / 2 可以防止由于 left 、right 同时太大，导致相加的结果溢出的问题
            // 比如数据 int 的最大值为 2,147,483,647
            // 此时，left 为 2,147,483,640
            // 此时，right 为 2,147,483,646
            // 两者直接相加超过了 2,147,483,647，产生了溢出
            int mid = left + (right - left) / 2;

            // 中间的元素和目标值 target 相等，直接返回下标即可，不需要插入
            if(nums[mid] == target) {
                // 直接返回下标即可
                return mid;
            
            // 中间的元素大于了目标值 target
            // 1、数组为有序数组，比如为递增数组
            // 2、数组中不存在重复元素
            // 由于该数组存在以上两个特点，所以 [ mid , right ] 这个区间中的所有元素都大于目标值 target
            // 因此，缩小查找区间为 [ left , mid - 1]
            } else if(nums[mid] > target) {
                // 也就是说缩小之后的区间最右侧位置为 mid - 1
                right = mid - 1;
            
            // 中间的元素小于了目标值 target
            // 1、数组为有序数组，比如为递增数组
            // 2、数组中不存在重复元素
            // 由于该数组存在以上两个特点，所以 [ left , mid ] 这个区间中的所有元素都小于目标值 target
            // 因此，缩小查找区间为 [ mid + 1 , right]
            } else if(nums[mid] < target){
                // 也就是说缩小之后的区间最左侧位置为 mid + 1
                left = mid + 1;
            }
        }
        
        // 执行到这里，说明退出了 while 循环，在 nums 里面没有找到和目标值 target 相同的元素，需要将 target 插入到 nums 中
        // 在上面 while 循环每次的操作中，都会使得 [ left , right ] 的这个区间中的元素减少，直到 left = right + 1 
        // 出现区间不存在元素位置
        // 在出现这种情况之前，也就是 while 循环操作的最后一次时，left = right，那么此时计算的 mid = left = right
        // 此时 nums[mid] 左边的数全部小于目标值 target ，nums[mid] 右边的数全部大于目标值 target
        // 1、如果 nums[mid] 大于 target，那么接下来 right 会向左移动，即 right = left - 1，此时搜索区间不存在
        // 那么说明 target 应该插入到 nums[mid] 的前一个位置，也就是顶替了 nums[mid] 的位置，nums[mid] 后面所有元素都向后移动
        // 而此时 left 指向的就是 nums[mid] 这个元素，所以 left 就是插入的位置
        // 2、如果 nums[mid] 小于 target，那么接下来 left 会向右移动，即 left = right + 1，此时搜索区间不存在
        // 那么说明 target 应该插入到 nums[mid] 的后一个位置，而 left 向后移动了一次，这个位置就是插入位置
        return left;
    }
};


class Solution94 {
public:
    // 2022.7.24, from https://walkccc.me/LeetCode/problems/0035/
    // Time: O(log n)
    // Space: O(1)
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();

        while (l < r) {
            const int m = (l + r) / 2;
            if (nums[m] == target)
                return m;
            if (nums[m] < target)
                l = m + 1;
            else
                r = m;
        }

        return l;
    }
};


class Solution93 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/35
    /*
        这道题基本没有什么难度，实在不理解为啥还是 Medium 难度的，完完全全的应该是 Easy 啊（貌似现在已经改为 Easy 类了），
        三行代码搞定的题，只需要遍历一遍原数组，若当前数字大于或等于目标值，则返回当前坐标，如果遍历结束了，说明目标值比数组
        中任何一个数都要大，则返回数组长度n即可，代码如下：

        解法一：
    */
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= target) return i;
        }
        return nums.size();
    }
};


class Solution92 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/35
    /*
        当然，我们还可以用二分搜索法来优化时间复杂度，而且个人认为这种方法应该是面试官们想要考察的算法吧，属于博主之前的总结帖 
        LeetCode Binary Search Summary 二分搜索法小结 中第二类 - 查找不小于目标值的数，参见代码如下：

        解法二：
    */
    int searchInsert(vector<int>& nums, int target) {
        if (nums.back() < target) return nums.size();
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        return right;
    }
};



class Solution91 {
public:
    // 2022.7.27, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/35.%20Search%20Insert%20Position
    // OJ: https://leetcode.com/problems/search-insert-position/
    // Author: github.com/lzl124631x
    // Time: O(logN)
    // Space: O(1)
    // Solution 1. Binary Search (L <= R)
    int searchInsert(vector<int>& A, int target) {
        int L = 0, R = A.size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] == target) return M;
            if (A[M] < target) L = M + 1;
            else R = M - 1;
        }
        return L;
    }
};



class Solution90 {
public:
    // 2022.7.27, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/35.%20Search%20Insert%20Position
    // OJ: https://leetcode.com/problems/search-insert-position/
    // Author: github.com/lzl124631x
    // Time: O(logN)
    // Space: O(1)
    // Solution 2. Binary Search (L < R)
    int searchInsert(vector<int>& A, int target) {
        int L = 0, R = A.size();
        while (L < R) {
            int M = (L + R) / 2;
            if (A[M] < target) L = M + 1;
            else R = M;
        }
        return L;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


class Solution {
public:
    // 2022.8.6 by Hsinan, use lower_bound() to get >= target index
    int searchInsert(vector<int>& A, int target) {
        auto ret = lower_bound(A.begin(), A.end(), target);
        if (ret == A.end()) {
            // either bigger than max or lesser than A[0]
            if (target > A[0]) {
                return A.size(); 
            } else {
                return 0;
            }
        } else {
            // somewhere found
            if (*ret == target) { 
                return distance(A.begin(), ret); 
            } else {
                return distance(A.begin(), ret); 
            }
        }
    }
};

// @lc code=end

