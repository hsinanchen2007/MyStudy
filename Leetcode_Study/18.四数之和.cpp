/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

/* 

https://leetcode.cn/problems/4sum/

18. 四数之和
给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 
[nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：

0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按 任意顺序 返回答案 。

 
示例 1：

输入：nums = [1,0,-1,0,-2,2], target = 0
输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

示例 2：

输入：nums = [2,2,2,2,2], target = 8
输出：[[2,2,2,2]]
 

提示：

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
通过次数328,889提交次数836,378

*/

// @lc code=start
class Solution100 {
public:
    // 2022.6.12, from AcWing https://www.acwing.com/activity/content/problem/content/2351/
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // define answer vector to return
        vector<vector<int>> answer;

        // sort the given vector
        sort(nums.begin(), nums.end());

        // iterate all elements
        for (int i = 0; i < nums.size(); i++) {
            // remove duplicated one
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < nums.size(); j++) {
                // remove duplicated one
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                for (int k = j + 1, u = nums.size() - 1; k < u; k++) {
                    // remove duplicated one
                    if (k > j + 1 && nums[k] == nums[k - 1]) continue;

                    // do u-- loop unti it either equal or smaller than target
                    // tricky part is that the second pointer u should be nums[u -1] here,
                    // not nums[u], because we want to see "next" one and decide u-- or not
                    // note that the sum condition is >=, the = is needed

                    // CORRECTION: Latest LC will give overflow numbers, so we need to avoid such situation
                    // Instead of using nums[i] + nums[j] + nums[k] + nums[u] >= target
                    // we use nums[i] + nums[j] >= target - nums[k] - nums[u -1]
                    // reference from another solution at 代码随想录:
                    // https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0018.%E5%9B%9B%E6%95%B0%E4%B9%8B%E5%92%8C.md
                    while ((u - 1 > k) &&
                           (nums[i] + nums[j] >= target - nums[k] - nums[u -1])) {
                        u--;
                    }
                    // if the sum is same as target, add this set into answer
                    if (nums[i] + nums[j] == target - nums[k] - nums[u] ) {
                        answer.push_back({nums[i], nums[j], nums[k], nums[u]});
                    }
                }
            }
        }

        return answer;
    }
};


class Solution99 {
public:
    // 2022.6.12, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/4sum.cpp
    // Time:  O(n^3)
    // Space: O(1)
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        sort(begin(nums), end(nums));
        vector<vector<int>> result;
        for (int i = 0; i + 3 < size(nums); ++i) {
            if (i && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j + 2 < size(nums); ++j) {
                if (j != i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                const auto& total = target - nums[i] - nums[j];
                int left = j + 1, right = size(nums) - 1;
                while (left < right) {
                    if (nums[left] + nums[right] == total) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        ++left, --right;
                        while (left < right && nums[left] == nums[left - 1]) {
                            ++left;
                        }
                        while (left < right && nums[right] == nums[right + 1]) {
                            --right;
                        }
                    } else {
                        if (nums[left] + nums[right] > total) {
                            --right;
                        } else {
                            ++left;
                        }
                    }
                }
            }
        }
        return result;
    }
};


class Solution98 {
public:
    // 2022.6.12, from https://github.com/grandyang/leetcode/issues/18
    /*
        LeetCode 中关于数字之和还有其他几道，分别是 Two Sum ，3Sum ，3Sum Closest，虽然难度在递增，但是整体的套路都是一样的，
        在这里为了避免重复项，我们使用了 STL 中的 TreeSet，其特点是不能有重复，如果新加入的数在 TreeSet 中原本就存在的话，插入
        操作就会失败，这样能很好的避免的重复项的存在。此题的 O(n^3) 解法的思路跟 3Sum 基本没啥区别，就是多加了一层 for 循环，
        其他的都一样，代码如下：
    */
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = j + 1, right = n - 1;
                while (left < right) {
                    long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        vector<int> out{nums[i], nums[j], nums[left], nums[right]};
                        res.push_back(out);
                        while (left < right && nums[left] == nums[left + 1]) ++left;
                        while (left < right && nums[right] == nums[right - 1]) --right;
                        ++left; --right;
                    } else if (sum < target) ++left;
                    else --right;
                }
            }
        }
        return res;
    }
};


class Solution97 {
public:
    // 2022.7.24, from https://github.com/grandyang/leetcode/issues/18
    /*
        但是毕竟用 TreeSet 来进行去重复的处理还是有些取巧，可能在 Java 中就不能这么做，那么还是来看一种比较正统的做法吧，
        手动进行去重复处理。主要可以进行的有三个地方，首先在两个 for 循环下可以各放一个，因为一旦当前的数字跟上面处理过的
        数字相同了，那么找下来肯定还是重复的。之后就是当 sum 等于 target 的时候了，在将四个数字加入结果 res 之后，left 
        和 right 都需要去重复处理，分别像各自的方面遍历即可，参见代码如下：
    */
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = j + 1, right = n - 1;
                while (left < right) {
                    long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        vector<int> out{nums[i], nums[j], nums[left], nums[right]};
                        res.push_back(out);
                        while (left < right && nums[left] == nums[left + 1]) ++left;
                        while (left < right && nums[right] == nums[right - 1]) --right;
                        ++left; --right;
                    } else if (sum < target) ++left;
                    else --right;
                }
            }
        }
        return res;
    }
};


class Solution96 {
public:
    // 2022.7.24, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0018.%E5%9B%9B%E6%95%B0%E4%B9%8B%E5%92%8C.md
    /*
       四数之和，和15.三数之和是一个思路，都是使用双指针法, 基本解法就是在15.三数之和 的基础上再套一层for循环。
      
       但是有一些细节需要注意，例如： 不要判断nums[k] > target 就返回了，三数之和 可以通过 nums[i] > 0 就返回了，
       因为 0 已经是确定的数了，四数之和这道题目 target是任意值。比如：数组是[-4, -3, -2, -1]，target是-10，不能
       因为-4 > -10而跳过。但是我们依旧可以去做剪枝，逻辑变成nums[i] > target && (nums[i] >=0 || target >= 0)
       就可以了。
      
       15.三数之和的双指针解法是一层for循环num[i]为确定值，然后循环内有left和right下标作为双指针，找到nums[i] + 
       nums[left] + nums[right] == 0。
      
       四数之和的双指针解法是两层for循环nums[k] + nums[i]为确定值，依然是循环内有left和right下标作为双指针，找出nums[k] 
       + nums[i] + nums[left] + nums[right] == target的情况，三数之和的时间复杂度是O(n^2)，四数之和的时间复杂度是O(n^3) 。
      
       那么一样的道理，五数之和、六数之和等等都采用这种解法。
      
       对于15.三数之和双指针法就是将原本暴力O(n^3)的解法，降为O(n^2)的解法，四数之和的双指针解法就是将原本暴力O(n^4)的解法，
       降为O(n^3)的解法。
      
       之前我们讲过哈希表的经典题目：454.四数相加II，相对于本题简单很多，因为本题是要求在一个集合中找出四个数相加等于target，
       同时四元组不能重复。
      
       而454.四数相加II是四个独立的数组，只要找到A[i] + B[j] + C[k] + D[l] = 0就可以，不用考虑有重复的四个元素相加等于0的情况，
       所以相对于本题还是简单了不少！
      
       我们来回顾一下，几道题目使用了双指针法。
      
       双指针法将时间复杂度：O(n^2)的解法优化为 O(n)的解法。也就是降一个数量级，题目如下：
      
       27.移除元素
       15.三数之和
       18.四数之和
       链表相关双指针题目：
       
       206.反转链表
       19.删除链表的倒数第N个节点
       面试题 02.07. 链表相交
       142题.环形链表II
       双指针法在字符串题目中还有很多应用，后面还会介绍到。
      
       C++代码
    */
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); k++) {
            // 剪枝处理
            if (nums[k] > target && nums[k] >= 0 && target >= 0) {
            	break; // 这里使用break，统一通过最后的return返回
            }
            // 对nums[k]去重
            if (k > 0 && nums[k] == nums[k - 1]) {
                continue;
            }
            for (int i = k + 1; i < nums.size(); i++) {
                // 2级剪枝处理
                if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0 && target >= 0) {
                    break;
                }

                // 对nums[i]去重
                if (i > k + 1 && nums[i] == nums[i - 1]) {
                    continue;
                }
                int left = i + 1;
                int right = nums.size() - 1;
                while (right > left) {
                    // nums[k] + nums[i] + nums[left] + nums[right] > target 会溢出
                    if ((long) nums[k] + nums[i] + nums[left] + nums[right] > target) {
                        right--;
                    // nums[k] + nums[i] + nums[left] + nums[right] < target 会溢出
                    } else if ((long) nums[k] + nums[i] + nums[left] + nums[right]  < target) {
                        left++;
                    } else {
                        result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        // 对nums[left]和nums[right]去重
                        while (right > left && nums[right] == nums[right - 1]) right--;
                        while (right > left && nums[left] == nums[left + 1]) left++;

                        // 找到答案时，双指针同时收缩
                        right--;
                        left++;
                    }
                }

            }
        }
        return result;
    }
};


// Note that below solutions will NOT work now due to new tricky testcases!!
// Will revisit them later with my owned fix
// https://github.com/MaskRay/LeetCode/blob/master/4sum.cc
// https://walkccc.me/LeetCode/problems/0018/
// https://github.com/lzl124631x/LeetCode/tree/master/leetcode/18.%204Sum


/************************************************************************************************************/
/************************************************************************************************************/


class Solution95 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> path;

        sort(begin(nums), end(nums));
        nSum(nums, 4, target, 0, nums.size() - 1, path, ans);
        return ans;
    }

private:
    // In [l, r], find n numbers add up to the target
    void nSum(const vector<int>& nums, long n, long target, int l, int r,
                vector<int>& path, vector<vector<int>>& ans) {
        if (r - l + 1 < n || target < nums[l] * n || target > nums[r] * n)
            return;
        if (n == 2) {
            // Very simliar to the sub procedure in 15. 3Sum
            while (l < r) {
                const int sum = nums[l] + nums[r];
                if (sum == target) {
                    path.push_back(nums[l]);
                    path.push_back(nums[r]);
                    ans.push_back(path);
                    path.pop_back();
                    path.pop_back();
                    ++l;
                    --r;
                    while (l < r && nums[l] == nums[l - 1])
                        ++l;
                    while (l < r && nums[r] == nums[r + 1])
                        --r;
                } else if (sum < target) {
                    ++l;
                } else {
                    --r;
                }
            }
            return;
        }

        for (int i = l; i <= r; ++i) {
            if (i > l && nums[i] == nums[i - 1])
                continue;
            path.push_back(nums[i]);
            nSum(nums, n - 1, target - nums[i], i + 1, r, path, ans);
            path.pop_back();
        }
    }
};


class Solution94 {
public:
    // 作者：xzp
    // 链接：https://leetcode.cn/leetbook/read/sliding-window-and-two-pointers/od3esm/?discussion=RuXxYw
    // 来源：力扣（LeetCode）
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> num;
        if(n < 4) return num;
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i < n - 3 ; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            if((long)nums[i] + (long)nums[i + 1] + (long)nums[i + 2] + (long)nums[i + 3] > target) break;
            if((long)nums[i] + (long)nums[n - 1] + (long)nums[n - 2] + (long)nums[n - 3] < target) continue;
            for(int j = i + 1 ; j < n - 2 ; j++){
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                if((long)nums[i] + (long)nums[j] + (long)nums[j + 1] + (long)nums[j + 2] > target) break;
                if((long)nums[i] + (long)nums[n - 1] + (long)nums[n - 2] + (long)nums[j] < target) continue;
                int left = j + 1 , right = n - 1;
                while(left < right){
                    long sum = (long)nums[i] + (long)nums[j] + (long)nums[left] + (long)nums[right];
                    if(sum == target) {
                        num.push_back({nums[i] , nums[j] , nums[left] , nums[right]});
                        while(left < right && nums[left] == nums[++left]) {}
                        while(left < right && nums[right] == nums[--right]) {}
                    }
                    else if(sum < target) left++;
                    else right--;
                }
            }
        }
        return num;
    }
};


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // 题目存在多组解，每一组解都是一个数组，所以使用二维数组存储所有的解
        vector<vector<int>> ans;

        // 边界情况判断
        if ( nums.size() < 4) {
            return ans;
        }


        // 获取数组的长度
        int len = nums.size();

        // 先将数组进行排序操作，从小到大
        sort(nums.begin(), nums.begin() + len);

        // 开始遍历整个数组
        // 在遍历的过程中，观察设置的四个位置的元素之后的大小
        // 1、第一层循环
        // nums[i] 作为四个元素当中最小的那个元素
        // 需要留下 nums[len - 3] 、nums[len - 2] 、nums[len - 1] 这三个元素
        // 所以 i 的范围是 [ 0  , len - 4 ]
        for (int i = 0; i <= len - 4; i++) {

            // 答案中不可以包含重复的四元组，所以需要执行一个去重的操作
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // 如果发现当前区间中，最小的四个元素之和都大于了 target
            // 此时，剩下的三个数无论取什么值，四数之和一定大于 target，可以直接退出第一层循环
            if ((long) nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
                break;
            }
            
            // 如果发现当前区间中，选择最大的三个数和 nums[i] 相加都小于了 target
            // 说明此时剩下的三个数无论取什么值，四数之和一定小于 target
            // 因此第一层循环直接进入下一轮，即执行 i++
            if ((long) nums[i] + nums[len - 3] + nums[len - 2] + nums[len - 1] < target) {
                continue;
            }

            // 来到这里时，通过第一层循环，已经确定 nums[i] 这个数
            // 在 [ i + 1 , len - 1 ] 这个区间中寻找剩下的两个数
            // 2、第二层循环
            // nums[j] 作为四个元素当中第二小的那个元素
            // 需要留下 nums[len - 2] 、nums[len - 1] 这三个元素
            // 所以 j 的范围是 [ i + 1  , len - 3 ]
            for (int j = i + 1; j <= len - 3; j++) {

                // 答案中不可以包含重复的四元组，所以需要执行一个去重的操作
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                // 如果发现当前区间中，最小的四个元素之和都大于了 target
                // 此时，剩下的三个数无论取什么值，四数之和一定大于 target，可以直接退出第二层循环 
                if ((long) nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                    break;
                }

                // 如果发现当前区间中，选择最大的三个数和 nums[i] 相加都小于了 target
                // 说明此时剩下的三个数无论取什么值，四数之和一定小于 target
                // 因此第二层循环直接进入下一轮，即执行 j++
                if ((long) nums[i] + nums[j] + nums[len - 2] + nums[len - 1] < target) {
                    continue;
                }

                // 否则的话，开始去寻找剩下的两个数
                //  在 [ i + 1 , len - 2 ] 这个区间
                int left = j + 1 ;

                int right = len - 1;

                // left 和 right 不断的向内移动
                // 逻辑和三数之和的逻辑一样
                while (left < right) {

                    // 计算这四个元素之和
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];

                    // 发现四者之和为 0
                    if (sum == target) {
                        // 把这个结果记录一下
                        vector<int>v = {nums[i], nums[j],nums[left], nums[right]};

         ans.push_back(v);

                        // 答案中不可以包含重复的三元组，所以需要执行一个去重的操作
                        // 比如这个输入 [-2,0,0,2,2]
                        // i 指向的元素值为 -2 ，left 指向的元素值为第一个 0 ，right 指向的元素值为倒数第一个 2 时
                        // 它们的 sum 为 0 ，如果让 ，left 向右移动一下，，right 向左移动一下，它们的 sum 也为 0
                        // 但是这两组解都是 [ -2 , 0 , 2]，所以需要去重
                        while (left < right && nums[left] == nums[left + 1]) {
                            // left 向右移动
                            left++;

                        }

                        while (left < right && nums[right] == nums[right - 1]) {
                            // right 向左移动
                            right--;
                        }

                        // left 向右移动
                        left++;

                        // right 向左移动
                        right--;

                    // 如果四者之和小于 0 ，那么说明需要找更大的数
                    } else if (sum < target) {
                        // left 向右移动
                        left++;

                    // 如果四者之和大于 0 ，那么说明需要找更小的数
                    } else {
                        // right 向左移动
                        right--;
                    }
                }
            }
        }

        // 返回结果
        return ans;

    }
};


// @lc code=end

