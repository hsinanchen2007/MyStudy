/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

/*/

https://leetcode.cn/problems/squares-of-a-sorted-array/

977. 有序数组的平方
给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

 
示例 1：

输入：nums = [-4,-1,0,3,10]
输出：[0,1,9,16,100]
解释：平方后，数组变为 [16,1,0,9,100]
排序后，数组变为 [0,1,9,16,100]

示例 2：

输入：nums = [-7,-3,2,3,11]
输出：[4,9,9,49,121]
 

提示：

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums 已按 非递减顺序 排序
 

进阶：

请你设计时间复杂度为 O(n) 的算法解决本问题
通过次数350,059提交次数507,592

*/

// @lc code=start
class Solution100 {
public:
    // 2022.6.18, by Hsinan. Do sqrt then sort the answers by order
    vector<int> sortedSquares(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            long answer = nums[i] * nums[i];
            nums[i] = (int)answer;
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};


class Solution99 {
public:
    // 2022.6.18, from https://programmercarl.com/0977.%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E7%9A%84%E5%B9%B3%E6%96%B9.html#%E6%9A%B4%E5%8A%9B%E6%8E%92%E5%BA%8F
    // By using two pointers, as the given vector is already sorted, 
    // that means the max or min number will always be from either nums[0] or nums[size-1]
    // so define left and right pointers, and put the answers back to vector
    /*
        为了易于大家理解，我还特意录制了视频，本题视频讲解

        暴力排序
        最直观的想法，莫过于：每个数平方之后，排个序，美滋滋，代码如下：

        class Solution {
        public:
            vector<int> sortedSquares(vector<int>& A) {
                for (int i = 0; i < A.size(); i++) {
                    A[i] *= A[i];
                }
                sort(A.begin(), A.end()); // 快速排序
                return A;
            }
        };
        class Solution:
            def sortedSquares(self, nums: List[int]) -> List[int]:
                res=[]
                for num in nums: 
                    res.append(num**2)
                return sorted(res)   
        这个时间复杂度是 O(n + nlogn)， 可以说是O(nlogn)的时间复杂度，但为了和下面双指针法算法时间复杂度有鲜明对比，我记为 O(n + nlog n)。

        双指针法
        数组其实是有序的， 只不过负数平方之后可能成为最大数了。

        那么数组平方的最大值就在数组的两端，不是最左边就是最右边，不可能是中间。
        此时可以考虑双指针法了，i指向起始位置，j指向终止位置。

        定义一个新数组result，和A数组一样的大小，让k指向result数组终止位置。

        如果A[i] * A[i] < A[j] * A[j] 那么result[k--] = A[j] * A[j]; 。
        如果A[i] * A[i] >= A[j] * A[j] 那么result[k--] = A[i] * A[i]; 。

        如动画所示：

        不难写出如下代码：
    */
    vector<int> sortedSquares(vector<int>& nums) {
        int k = nums.size() - 1;
        vector<int> answer(nums.size(), 0);

        // iterate all elements, but by using for loop like below
        // note that the stop condition is "i <= j" because i and j may have same value
        for (int i = 0, j = nums.size() - 1; i <= j; /* no i or j's increase/decrease here! */) {
            // so if we know j*j is bigger, put it into answer vector
            if (nums[i] * nums[i] < nums[j] * nums[j]) {
                answer[k--] = nums[j] * nums[j];
                j--;
            } else {
                // if i*i is equal or bigger, put it into answer vector
                answer[k--] = nums[i] * nums[i];
                i++;
            }
        }

        return answer;
    }
};


class Solution98 {
public:
    // 2022.6.18, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/squares-of-a-sorted-array.cpp
    // Time:  O(n)
    // Space: O(1)
    vector<int> sortedSquares(vector<int>& nums) {
        int right = distance(nums.cbegin(), lower_bound(nums.cbegin(), nums.cend(), 0));
        int left = right - 1;
        vector<int> result;
        while (0 <= left || right < nums.size()) {
            if (right == nums.size() ||
                (0 <= left && nums[left] * nums[left] < nums[right] * nums[right])) {
                result.emplace_back(nums[left] * nums[left]);
                --left;
            } else {
                result.emplace_back(nums[right] * nums[right]);
                ++right;
            }
        }
        return result;
    }
};


class Solution97 {
public:
    // 2022.6.18, from AcWing https://www.acwing.com/video/3272/
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();

        // as below operations to answer is like an array operation,
        // remember to define the size to answer vector 
        vector<int> answer(size);

        // iterate elements and put larger number into answer
        for (int i = 0, j = size - 1, k = size - 1; i <= j; ) {
            if (nums[i] * nums[i] > nums[j] * nums[j]) {
                answer[k] = nums[i] * nums[i];
                i++, k--;
            } else {
                answer[k] = nums[j] * nums[j];
                j--, k--;
            }
        }
        return answer;
    }
};


class Solution96 {
public:
    // 2022.6.19, from https://ke.algomooc.com/detail/v_626e7fcae4b01c509aaaf552/3?from=p_626e7eeee4b01c509aaaf51e&type=6&parent_pro_id=
    // 登录 AlgoMooc 官网获取更多算法图解
    // https://www.algomooc.com/582.html 
    // 作者：程序员吴师兄
    // 代码有看不懂的地方一定要私聊咨询吴师兄呀
    // 有序数组的平方( LeetCode 977 ):https://leetcode-cn.com/problems/squares-of-a-sorted-array/
    vector<int> sortedSquares(vector<int>& nums) {
        // 我们设置两个索引，分别指向数组的两端

        // right 指向终止位置
        int right = nums.size() - 1;

        // left 指向起始位置
        int left = 0;

        // 设置一个新数组 result 用来存放最终的输出结果
        vector<int> result = vector<int>(nums.size(), 0);

        // 让 index 指向 result 数组的终止位置，观察这个位置应该存放什么数字
        int index = result.size() - 1;

        // left 向右移动，right 向左移动，当 left 大于 right 时，说明已经观察遍历了 nums 数组中的所有元素，跳出循环
        while (left <= right) {

            // 说明左边的平方数大于右边
            if (nums[left] * nums[left] > nums[right] * nums[right]) {

                // result 数组中 index 位置要存放更大的那个数，即 nums[left] * nums[left]
                result[index] = nums[left] * nums[left];

                // 由于相对较大的数是在 left 位置，上一行代码已经将它赋值到 index 位置
                // 所以此时 left 位置的数已经失去作用，将它向后移动
                left++;

                // 此时，index 位置已经存放好数，将它向前移动，观察下一个位置应该存放哪个数
                index--;

              // 说明右边的平方数大于左边
            } else {

                // result 数组中 index 位置要存放更大的那个数，即 nums[right] * nums[right]
                result[index] = nums[right] * nums[right];

                // 由于相对较大的数是在 right 位置，上一行代码已经将它赋值到 index 位置
                // 所以此时 right 位置的数已经失去作用，将它向前移动
                right--;

                // 此时，index 位置已经存放好数，将它向前移动，观察下一个位置应该存放哪个数
                index--;
            }
        }

        // 最后返回我们设置的结果数组即可
        return result;
    }
};


class Solution95 {
public:
    // 2022.7.26, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/977.%20Squares%20of%20a%20Sorted%20Array
    // OJ: https://leetcode.com/problems/squares-of-a-sorted-array/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    vector<int> sortedSquares(vector<int>& A) {
        int N = A.size();
        for (int &n : A) n *= n;
        vector<int> ans(N);
        for (int i = 0, j = N - 1, k = N - 1; i <= j; ) {
            if (A[i] > A[j] ) {
                ans[k--] = A[i];
                ++i;
            } else {
                ans[k--] = A[j];
                --j;
            }
        }
        return ans;
    }
};


class Solution94 {
public:
    // 2022.7.26, from https://walkccc.me/LeetCode/problems/0977/
    // Time: O(n)
    // Space: O(n)
    vector<int> sortedSquares(vector<int>& A) {
        const int n = A.size();
        vector<int> ans(n);
        int i = n - 1;

        for (int l = 0, r = n - 1; l <= r;)
        if (abs(A[l]) > abs(A[r]))
            ans[i--] = A[l] * A[l++];
        else
            ans[i--] = A[r] * A[r--];

        return ans;
    }
};


class Solution93 {
public:
    // 2022.7.26, from https://www.guozet.me/leetcode/Leetcode-977-Squares-of-a-Sorted-Array.html?h=sortedSqu
    vector<int> sortedSquares(vector<int>& A) {
        for (int i = 0; i < A.size(); ++i) {
            A[i] = A[i] * A[i];
        }
        sort(A.begin(), A.end());
        return A;
    }
};


class Solution92 {
public:
    // 2022.7.26, from https://github.com/grandyang/leetcode/issues/977
    /*
        这道题给了一个非降序排列的数组，可以有负数存在，现在让求出每个数字的平方数，并且也是非降序排列。若数组中只有正数存在的话，
        则平方后的数组跟原数组的顺序还是相同的。但是负数的平方是正数，则顺序就会被打乱。最简单暴力的方法就是把平方数存入一个 TreeSet，
        利用其自动排序的功能可以得到所求的顺序了，注意这里需要用 multiset，因为可能存在重复值，参见代码如下：
        解法一：
    */
    vector<int> sortedSquares(vector<int>& A) {
		multiset<int> st;
		for (int num : A) st.insert(num * num);
		return vector<int>(st.begin(), st.end());
    }
};


class Solution {
public:
    // 2022.7.26, from https://github.com/grandyang/leetcode/issues/977
    /*
        当然若想进一步优化时间复杂度的话，可以使用双指针来做，用两个变量分别指向开头和结尾，然后比较，每次将绝对值较大的那个数的平方值
        先加入数组的末尾，然后依次往前更新，最后得到的就是所求的顺序，参见代码如下：
        解法二：
    */
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size(), i = 0, j = n - 1;
        vector<int> res(n);
        for (int k = n - 1; k >= 0; --k) {
            if (abs(A[i]) > abs(A[j])) {
                res[k] = A[i] * A[i];
                ++i;
            } else {
                res[k] = A[j] * A[j];
                --j;
            }
        }
        return res;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// 2022.8.15, not in top list

// @lc code=end

