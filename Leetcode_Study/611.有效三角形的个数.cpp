/*
 * @lc app=leetcode.cn id=611 lang=cpp
 *
 * [611] 有效三角形的个数
 */

/*

https://leetcode.cn/problems/valid-triangle-number/

611. 有效三角形的个数
给定一个包含非负整数的数组 nums ，返回其中可以组成三角形三条边的三元组个数。


示例 1:

输入: nums = [2,2,3,4]
输出: 3
解释:有效的组合是: 
2,3,4 (使用第一个 2)
2,3,4 (使用第二个 2)
2,2,3

示例 2:

输入: nums = [4,2,3,4]
输出: 4
 

提示:

1 <= nums.length <= 1000
0 <= nums[i] <= 1000
通过次数70,962提交次数132,309

*/

// @lc code=start
class Solution100 {
public:
    // 2022.7.30, from 程序员吴师兄
    // 登录 AlgoMooc 官网获取更多算法图解
    // https://www.algomooc.com
    // 作者：程序员吴师兄
    // 代码有看不懂的地方一定要私聊咨询吴师兄呀
    // 有效三角形的个数(611):https://leetcode-cn.com/problems/valid-triangle-number/ 
    int triangleNumber(vector<int>& nums) {

        // 先将数组排序
        sort(nums.begin(), nums.begin() + nums.size());

        // 获取数组的长度
        int n = nums.size();

        // 统计可以组成三角形三条边的三元组个数，一开始为 0 
        int res = 0;

        // 通过两个循环来定位三角形的两边
        // 其中 nums[i] 为能形成三角形的三边中的最短边，因此 i 的范围为 [ 0 , n - 3 ]
        for (int i = 0; i < n - 2; i++) {
            
            // 其中 nums[j] 为能形成三角形的三边中的较短边，因此 j 的范围为 [ i + 1 , n - 2 ]
            for (int j = i + 1; j < n - 1; j++) {
                
                // nums 已经排好序，并且 i < j，因此 nums[i] < nums[j]
                // 判断三条边能组成三角形的条件为：假设三条边长从小到大为 a < b < c ，当且仅当 a + b > c 这三条边能组成三角形。
                // nums[i] 为 a，nums[j] 为 b，先计算出最短边和较短边之和
                int sum = nums[i] + nums[j];

                // 接下来，在 [ j + 1 , n - 1 ] 这个区间去寻找出最长边 c 

                // left 为当前区间最左侧的元素，可以获取到
                int left = j + 1;
                
                // right 为当前区间最右侧的元素，可以获取到
                int right = n - 1;

                // 在 while 循环里面，left 不断的 ++，而 right 不断的 --
                // 当 [ left , right ] 这个区间不存在元素的时候，才跳出 while 循环，也就是当 left > right 时跳出循环
                // 即当 left = right + 1 时，搜索区间没有元素了
                // 由于 left 和 right 相遇的时候指向同一个元素，这个元素是存在于 [ left , right] 区间，这个区间就一个元素
                // 所以此时 while 循环的判断可以使用等号
                while (left <= right) {
                    
                    // left + (right - left) / 2 和 (left + right) / 2 的结果相同
                    // 但是使用 left + (right - left) / 2 可以防止由于 left 、right 同时太大，导致相加的结果溢出的问题
                    // 比如数据 int 的最大值为 2,147,483,647
                    // 此时，left 为 2,147,483,640
                    // 此时，right 为 2,147,483,646
                    // 两者直接相加超过了 2,147,483,647，产生了溢出
                    int mid =  left + (right - left) / 2;

                    // 两边之和大于中间元素的值，说明两边之和肯定大于 [ left , mid ] 这个区间中所有的元素
                    // 因此[ left , mid ] 这个区间中所有的元素都和 nums[i]、nums[j] 构成三角形
                    if (sum > nums[mid]) {

                        // 因此，缩小查找区间为 [ mid + 1 , right]
                        // 查看一下 [ mid + 1 , right] 是否也有元素可以和 nums[i]、nums[j] 构成三角形
                        left = mid + 1;
                    
                    // 两边之和小于中间元素的值，说明两边之和肯定小于 [ mid , right ] 这个区间中所有的元素
                    // 因此 [ mid ，right] 这个区间中所有的元素和 nums[i]、nums[j] 无法构成三角形
                    }else if(sum < nums[mid] ) {

                        // 因此，缩小查找区间为 [ left , mid - 1]
                        // 此时，舍弃掉了 [ mid ，right]
                        right = mid - 1;

                    // 两边之和等于中间元素的值，和两边之和小于中间元素的值情况是一样的
                    // 说明两边之和肯定小于或者等于 [ mid , right ] 这个区间中所有的元素
                    // 因此 [ mid ，right] 这个区间中所有的元素和 nums[i]、nums[j] 无法构成三角形
                    }else if( sum == nums[mid] ){
                        // 因此，缩小查找区间为 [ left , mid - 1]
                        // 此时，舍弃掉了 [ mid ，right]
                        right = mid - 1; 
                    }
                }

                // 来到这一步的时候，left = right + 1
                // 如果此时两边之和大于了 right 指向的值 nums[right]
                // 那么由于数组有序，并且 i < j < right
                // 因此 nums[i] < nums[j] < nums[right]，也就是说 nums[i] 、nums[j] 、 nums[right] 可以构成三角形
                // 并且 [ j + 1 , right ] 这个区间中所有的元素都可以和 nums[i] 、nums[j] 构成三角形
                if (sum > nums[right] ) {

                    // 计算 [ j + 1 , right ] 这个区间中所有的元素
                    int ans = right - (j + 1) + 1;

                    // 这些元素都能和 nums[i] 、nums[j] 构成三角形，把结果累加上去
                    res += ans;
                }
            }
        }

        // 返回结果
        return res;
    }
};


class Solution99 {
public:
    // 2022.7.30, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/611.%20Valid%20Triangle%20Number
    /*
        The naive solution is of O(N^3) time complexity, that is, for each triplet, detect if it can 
        form a triangle. This solution will get TLE.

        To optimize it, we first sort nums in ascending order. And for each pair a and b, use binary 
        search to find the count of numbers greater than a + b and less than b - a (b >= a).
    */
    // OJ: https://leetcode.com/problems/valid-triangle-number
    // Author: github.com/lzl124631x
    // Time: O(N^2logN)
    // Space: O(1)
    int triangleNumber(vector<int>& A) {
        int N = A.size(), ans = 0;
        sort(begin(A), end(A));
        for (int i = 0; i < N; ++i) {
            int a = A[i];
            for (int j = i + 1; j < N; ++j) {
                int b = A[j];
                auto begin = upper_bound(A.begin() + j + 1, A.end(), b - a); 
                auto end = lower_bound(A.begin() + j + 1, A.end(), a + b);
                ans += max(0, (int)(end - begin));
            }
        }
        return ans;
    }
};


class Solution98 {
public:
    // 2022.7.30, from https://walkccc.me/LeetCode/problems/0611/
    // Time: O(n^2)
    // Space: O(1)
    int triangleNumber(vector<int>& nums) {
        if (nums.size() < 3)
        return 0;

        int ans = 0;

        sort(begin(nums), end(nums));

        for (int k = nums.size() - 1; k > 1; --k) {
            int i = 0;
            int j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    // (nums[i], nums[j], nums[k])
                    // (nums[i + 1], nums[j], nums[k])
                    // ...
                    // (nums[j - 1], nums[j], nums[k])
                    ans += j - i;
                    --j;
                } else {
                    ++i;
                }
            }
        }

        return ans;
    }
};


class Solution97 {
public:
    // 2022.7.30, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/valid-triangle-number.cpp
    // Time:  O(n^2)
    // Space: O(1)
    int triangleNumber(vector<int>& nums) {
        int result = 0;
        sort(begin(nums), end(nums));
        for (int i = size(nums) - 1; i >= 2; --i) {
            int left = 0, right = i - 1;
            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    result += right - left;
                    --right;
                } else {
                    ++left;
                }
            }
        }
        return result;
    }
};


class Solution96 {
public:
    // 2022.7.30, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/valid-triangle-number.cpp
    // Time:  O(n^2)
    // Space: O(1)
    int triangleNumber(vector<int>& nums) {
        int result = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i + 2 < nums.size(); ++i) {
            if (nums[i] == 0) {
                continue;
            }
            auto k = i + 2;
            for (int j = i + 1; j + 1 < nums.size(); ++j) {
                while (k < nums.size() && nums[i] + nums[j] > nums[k]) {
                    ++k;
                }
                result += k - j - 1;
            }
        }
        return result;
    }
};


class Solution95 {
public:
    // 2022.7.30, from https://www.acwing.com/activity/content/code/content/628055/
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/628055/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size(); i ++ )
            for (int j = i - 1, k = 0; j > 0 && k < j; j -- ) {
                while (k < j && nums[k] <= nums[i] - nums[j]) k ++ ;
                res += j - k;
            }
        return res;
    }
};


class Solution94 {
public:
    // 2022.7.30, from https://github.com/grandyang/leetcode/issues/611
    /*
        这道题给了我们一堆数字，问我们能组成多少个正确的三角形，我们初中就知道三角形的性质，任意两条边之和
        要大于第三边。那么问题其实就变成了找出所有这样的三个数字，使得任意两个数字之和都大于第三个数字。
        那么可以转变一下，三个数字中如果较小的两个数字之和大于第三个数字，那么任意两个数字之和都大于第三个
        数字，这很好证明，因为第三个数字是最大的，所以它加上任意一个数肯定大于另一个数。这样，我们就先要给
        数组排序，博主最先尝试了暴力破解法，结果TLE了(不要吐槽博主哈，博主就是喜欢霸王硬上弓～)，后来优化
        的方法是先确定前两个数，将这两个数之和sum作为目标值，然后用二分查找法来快速确定第一个小于目标值的
        数，这种情况属于博主之前的博客LeetCode Binary Search Summary 二分搜索法小结中总结的第二类的
        变形，我们找到这个临界值，那么这之前一直到j的位置之间的数都满足题意，直接加起来即可，参见代码如下：

        解法一：
    */
    int triangleNumber(vector<int>& nums) {
        int res = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int sum = nums[i] + nums[j], left = j + 1, right = n;
                while (left < right) {
                    int mid = left + (right - left) / 2;
                    if (nums[mid] < sum) left = mid + 1;
                    else right = mid;
                }
                res += right - 1 - j;
            }
        }
        return res;
    }
};


class Solution {
public:
    // 2022.7.30, from https://github.com/grandyang/leetcode/issues/611
    /*
        其实还有更进一步优化的方法，用的是博主之前那篇3Sum Smaller里面的解法二，明明博主以前都总结过，
        换个题目情景就又没想到，看来博主的举一反三能力还是有所欠缺啊。没办法，只能继续刻意练习了。这种
        方法能将时间复杂度优化到O(n2), 感觉很叼了。思路是排序之后，从数字末尾开始往前遍历，将left指向
        首数字，将right之前遍历到的数字的前面一个数字，然后如果left小于right就进行循环，循环里面判断
        如果left指向的数加上right指向的数大于当前的数字的话，那么right到left之间的数字都可以组成三角
        形，这是为啥呢，相当于此时确定了i和right的位置，可以将left向右移到right的位置，中间经过的数
        都大于left指向的数，所以都能组成三角形，就说这思路叼不叼！加完之后，right自减一，即向左移动一位。
        如果left和right指向的数字之和不大于nums[i]，那么left自增1，即向右移动一位，参见代码如下：

        解法二：
    */
    int triangleNumber(vector<int>& nums) {
        int res = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = n - 1; i >= 2; --i) {
            int left = 0, right = i - 1;
            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    res += right - left;
                    --right;
                } else {
                    ++left;
                }
            }
        }
        return res;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// 2022.8.15, not in top list

// @lc code=end

