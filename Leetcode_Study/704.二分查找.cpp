/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

/*

https://leetcode.cn/problems/binary-search/

704. 二分查找
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。


示例 1:

输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4

示例 2:

输入: nums = [-1,0,3,5,9,12], target = 2
输出: -1
解释: 2 不存在 nums 中因此返回 -1
 

提示：

你可以假设 nums 中的所有元素是不重复的。
n 将在 [1, 10000]之间。
nums 的每个元素都将在 [-9999, 9999]之间。
通过次数634,790提交次数1,166,436

*/

// @lc code=start
class Solution100 {
public:
    // 2022.6.18, by Hsinan. The given vector is sorted, 
    // and there is no duplicated elements, typical binary search
    int search(vector<int>& nums, int target) {
        // special cases
        if (nums.size() == 1 && nums[0] == target) return 0;
        if (nums.size() == 2) {
            if (nums[0] == target) return 0;
            if (nums[1] == target) return 1;
        }

        // define left and right pointers
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            // if left or right is target
            if (nums[left] == target) return left;
            if (nums[right] == target) return right;

            // get middle from left and right
            int middle = left + (right -left)/2;
            if (middle != left && middle != right) {
                if (target > nums[middle]) {
                    left = middle;
                } else {
                    right = middle;
                }
            } else {
                return -1;
            }
        }

        return -1;
    }
};


class Solution99 {
public:
    // 2022.6.18, from https://programmercarl.com/0704.%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE.html#_704-%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE
    /*
        为了易于大家理解，我还录制了视频，可以看这里：B站：手把手带你撕出正确的二分法

        这道题目的前提是数组为有序数组，同时题目还强调数组中无重复元素，因为一旦有重复元素，使用二分查找法返回的元素下标可能
        不是唯一的，这些都是使用二分法的前提条件，当大家看到题目描述满足如上条件的时候，可要想一想是不是可以用二分法了。

        二分查找涉及的很多的边界条件，逻辑比较简单，但就是写不好。例如到底是 while(left < right) 还是 while(left <= right)，
        到底是right = middle呢，还是要right = middle - 1呢？

        大家写二分法经常写乱，主要是因为对区间的定义没有想清楚，区间的定义就是不变量。要在二分查找的过程中，保持不变量，就是在while
        寻找中每一次边界的处理都要坚持根据区间的定义来操作，这就是循环不变量规则。

        写二分法，区间的定义一般为两种，左闭右闭即[left, right]，或者左闭右开即[left, right)。

        下面我用这两种区间的定义分别讲解两种不同的二分写法。

        二分法第一种写法
        第一种写法，我们定义 target 是在一个在左闭右闭的区间里，也就是[left, right] （这个很重要非常重要）。

        区间的定义这就决定了二分法的代码应该如何写，因为定义target在[left, right]区间，所以有如下两点：

        while (left <= right) 要使用 <= ，因为left == right是有意义的，所以使用 <=
        if (nums[middle] > target) right 要赋值为 middle - 1，因为当前这个nums[middle]一定不是target，那么接下来要查找的
        左区间结束下标位置就是 middle - 1
        
        例如在数组：1,2,3,4,7,9,10中查找元素2，如图所示：

        704.二分查找

        代码如下：（详细注释）
    */
    // Solution 1 template: Use [left, right]
    //             while condition will be while (left <= right)
    //             if (nums[middle] > target) right = middle -1;
    //             if (nums[middle] < target) left = middle + 1;
    int search(vector<int>& nums, int target) {
        // define left and right pointers
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            // define middle, note that in case of overflow, 
            // use left + (right - left)/2 to get middle value
            int middle = left + (right - left) / 2; 

            // template above
            if (nums[middle] > target) {
                right = middle - 1;
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else {
                return middle;
            }
        }

        return -1;
    }
};


class Solution98 {
public:
    // 2022.6.18, from https://programmercarl.com/0704.%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE.html#_704-%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE
    /*
        二分法第二种写法
        如果说定义 target 是在一个在左闭右开的区间里，也就是[left, right) ，那么二分法的边界处理方式则截然不同。

        有如下两点：

        while (left < right)，这里使用 < ,因为left == right在区间[left, right)是没有意义的
        if (nums[middle] > target) right 更新为 middle，因为当前nums[middle]不等于target，去左区间继续寻找，而寻找区间是左闭右开区间，
        所以right更新为middle，即：下一个查询区间不会去比较nums[middle]

        在数组：1,2,3,4,7,9,10中查找元素2，如图所示：（注意和方法一的区别）

        704.二分查找1

        代码如下：（详细注释）

        二分法是非常重要的基础算法，为什么很多同学对于二分法都是一看就会，一写就废？

        其实主要就是对区间的定义没有理解清楚，在循环中没有始终坚持根据查找区间的定义来做边界处理。
        区间的定义就是不变量，那么在循环中坚持根据查找区间的定义来做边界处理，就是循环不变量规则。

        本篇根据两种常见的区间定义，给出了两种二分法的写法，每一个边界为什么这么处理，都根据区间的定义做了详细介绍。
        相信看完本篇应该对二分法有更深刻的理解了。

        相关题目推荐
        35.搜索插入位置
        34.在排序数组中查找元素的第一个和最后一个位置
        69.x 的平方根
        367.有效的完全平方数
    */
    // Solution 2 template: Use [left, right)
    //             while condition will be while (left < right)
    //             if (nums[middle] > target) right = middle;
    //             if (nums[middle] < target) left = middle + 1;
    int search(vector<int>& nums, int target) {
        // define two pointers, note that now right index is one overflow, as no "-1" here
        int left = 0;
        int right = nums.size();

        while (left < right) {
            // same as above, get middle value by proper way
            int middle = left + (right - left) / 2;

            if (nums[middle] > target) {
                // no middle -1 here as right side is already one index over from the beginning
                right = middle;
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else {
                return middle;
            }
        }

        return -1;
    }
};


class Solution97 {
public:
    // 2022.6.18, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/binary-search.cpp
    // Time:  O(logn)
    // Space: O(1)
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            auto mid = left + (right-left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};


class Solution96 {
public:
    // 2022.6.18, from AcWing https://www.acwing.com/video/2563/
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            // tricky1 to use >> 1 
            int middle = left + right >> 1;

            // tricky2 below uses ">=" condition, not only ">" condition
            // baseically, "right" will be the "middle" or "answer"
            // code is less but coding style is not good or good example
            // to learn algorithm, better to follow 代码随想录 code
            if (nums[middle] >= target) right = middle;

            else left = middle + 1;
        }
        if (nums[right] == target) return right;
        return -1;
    }
};


class Solution95 {
public:
    // 2022.7.26, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/704.%20Binary%20Search
    // OJ: https://leetcode.com/problems/binary-search/
    // Author: github.com/lzl124631x
    // Time: O(logN)
    // Space: O(1)
    int search(vector<int>& A, int target) {
        int L = 0, R = A.size() - 1;
        while (L < R) {
            int M = (L + R) / 2;
            if (A[M] < target) L = M + 1;
            else R = M;
        }
        return A[L] == target ? L : -1;
    }
};


class Solution94 {
public:
    // 2022.7.26, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/704.%20Binary%20Search
    // OJ: https://leetcode.com/problems/binary-search/
    // Author: github.com/lzl124631x
    // Time: O(logN)
    // Space: O(1)
    // Update by Hsinan, need to add "A.size() != M + 1" for boundary check
    int search(vector<int>& A, int target) {
        int L = 0, R = A.size();
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] == target) return M;
            if (A[M] < target && A.size() != M + 1) L = M + 1;
            else R = M - 1;
        }
        return -1;
    }
};


class Solution93 {
public:
    // 2022.7.26, from https://www.guozet.me/leetcode/summary/2019-01-15-Algorithms-Binary-Search.html?h=704
    // Time complexity: O(log n), Space complexity: O(1)
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


class Solution92 {
public:
    // 2022.7.26, from https://github.com/grandyang/leetcode/issues/704
    /*
        这道题就是最基本的二分搜索法了，这是博主之前总结的LeetCode Binary Search Summary 二分搜索法小结的四种之中的第一类，
        也是最简单的一类，写法什么很模版啊，注意right的初始化值，还有while的循环条件，以及right的更新值，这三点不同的人可能会有
        不同的写法，选一种自己最习惯的就好啦，参见代码如下：
    */
    /*
        from https://www.cnblogs.com/grandyang/p/6854825.html

        LeetCode Binary Search Summary 二分搜索法小结
        

        二分查找法作为一种常见的查找方法，将原本是线性时间提升到了对数时间范围，大大缩短了搜索时间，具有很大的应用场景，而在 
        LeetCode 中，要运用二分搜索法来解的题目也有很多，但是实际上二分查找法的查找目标有很多种，而且在细节写法也有一些变化。
        之前有网友留言希望博主能针对二分查找法的具体写法做个总结，博主由于之前一直很忙，一直拖着没写，为了树立博主言出必行的正面形象，
        不能再无限制的拖下去了，那么今天就来做个了断吧，总结写起来~ (以下内容均为博主自己的总结，并不权威，权当参考，欢迎各位大神
        们留言讨论指正)

        根据查找的目标不同，博主将二分查找法主要分为以下五类：

        第一类： 需查找和目标值完全相等的数

        这是最简单的一类，也是我们最开始学二分查找法需要解决的问题，比如我们有数组 [2, 4, 5, 6, 9]，target = 6，那么我们可以
        写出二分查找法的代码如下：        

        int find(vector<int>& nums, int target) {
            int left = 0, right = nums.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] == target) return mid;
                else if (nums[mid] < target) left = mid + 1;
                else right = mid;
            }
            return -1;
        }
        

        会返回3，也就是 target 的在数组中的位置。注意二分查找法的写法并不唯一，主要可以变动地方有四处：

        第一处是 right 的初始化，可以写成 nums.size() 或者 nums.size() - 1。
        第二处是 left 和 right 的关系，可以写成 left < right 或者 left <= right。
        第三处是更新 right 的赋值，可以写成 right = mid 或者 right = mid - 1。
        第四处是最后返回值，可以返回 left，right，或 right - 1。

        但是这些不同的写法并不能随机的组合，像博主的那种写法，若 right 初始化为了 nums.size()，那么就必须用 left < right，
        而最后的 right 的赋值必须用 right = mid。但是如果我们 right 初始化为 nums.size() - 1，那么就必须用 left <= right，
        并且right的赋值要写成 right = mid - 1，不然就会出错。所以博主的建议是选择一套自己喜欢的写法，并且记住，实在不行就带简单
        的例子来一步一步执行，确定正确的写法也行。

        第一类应用实例：
        Intersection of Two Arrays    


        第二类： 查找第一个不小于目标值的数，可变形为查找最后一个小于目标值的数

        这是比较常见的一类，因为我们要查找的目标值不一定会在数组中出现，也有可能是跟目标值相等的数在数组中并不唯一，而是有多个，
        那么这种情况下 nums[mid] == target 这条判断语句就没有必要存在。比如在数组 [2, 4, 5, 6, 9] 中查找数字3，就会返回
        数字4的位置；在数组 [0, 1, 1, 1, 1] 中查找数字1，就会返回第一个数字1的位置。我们可以使用如下代码：

        int find(vector<int>& nums, int target) {
            int left = 0, right = nums.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] < target) left = mid + 1;
                else right = mid;
            }
            return right;
        }        

        最后我们需要返回的位置就是 right 指针指向的地方。在 C++ 的 STL 中有专门的查找第一个不小于目标值的数的函数 lower_bound，
        在博主的解法中也会时不时的用到这个函数。但是如果面试的时候人家不让使用内置函数，那么我们只能老老实实写上面这段二分查找的函数。
        
        这一类可以轻松的变形为查找最后一个小于目标值的数，怎么变呢。我们已经找到了第一个不小于目标值的数，那么再往前退一位，返回 
        right - 1，就是最后一个小于目标值的数。

        第二类应用实例：
        Heaters， Arranging Coins， Valid Perfect Square，Max Sum of Rectangle No Larger Than K，Russian Doll Envelopes
        第二类变形应用：Valid Triangle Number
        

        第三类： 查找第一个大于目标值的数，可变形为查找最后一个不大于目标值的数

        这一类也比较常见，尤其是查找第一个大于目标值的数，在 C++ 的 STL 也有专门的函数 upper_bound，这里跟上面的那种情况的写法上
        很相似，只需要添加一个等号，将之前的 nums[mid] < target 变成 nums[mid] <= target，就这一个小小的变化，其实直接就改变了
        搜索的方向，使得在数组中有很多跟目标值相同的数字存在的情况下，返回最后一个相同的数字的下一个位置。比如在数组 [2, 4, 5, 6, 9] 
        中查找数字3，还是返回数字4的位置，这跟上面那查找方式返回的结果相同，因为数字4在此数组中既是第一个不小于目标值3的数，也是第一个
        大于目标值3的数，所以 make sense；在数组 [0, 1, 1, 1, 1] 中查找数字1，就会返回坐标5，通过对比返回的坐标和数组的长度，我们
        就知道是否存在这样一个大于目标值的数。参见下面的代码：
    
        int find(vector<int>& nums, int target) {
            int left = 0, right = nums.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] <= target) left = mid + 1;
                else right = mid;
            }
            return right;
        }
        
        这一类可以轻松的变形为查找最后一个不大于目标值的数，怎么变呢。我们已经找到了第一个大于目标值的数，那么再往前退一位，返回 
        right - 1，就是最后一个不大于目标值的数。比如在数组 [0, 1, 1, 1, 1] 中查找数字1，就会返回最后一个数字1的位置4，这在有些情况
        下是需要这么做的。

        第三类应用实例：
        Kth Smallest Element in a Sorted Matrix

        第三类变形应用示例：
        Sqrt(x)


        第四类： 用子函数当作判断关系（通常由 mid 计算得出）

        这是最令博主头疼的一类，而且通常情况下都很难。因为这里在二分查找法重要的比较大小的地方使用到了子函数，并不是之前三类中简单的数字
        大小的比较，比如 Split Array Largest Sum 那道题中的解法一，就是根据是否能分割数组来确定下一步搜索的范围。类似的还有 Guess 
        Number Higher or Lower 这道题，是根据给定函数 guess 的返回值情况来确定搜索的范围。对于这类题目，博主也很无奈，遇到了只能自求
        多福了。

        第四类应用实例：
        Split Array Largest Sum， Guess Number Higher or Lower，Find K Closest Elements，Find K-th Smallest Pair Distance，
        Kth Smallest Number in Multiplication Table，Maximum Average Subarray II，Minimize Max Distance to Gas Station，
        Swim in Rising Water，Koko Eating Bananas，Nth Magical Number


        第五类： 其他（通常 target 值不固定）

        有些题目不属于上述的四类，但是还是需要用到二分搜索法，比如这道 Find Peak Element，求的是数组的局部峰值。由于是求的峰值，需要跟相邻
        的数字比较，那么 target 就不是一个固定的值，而且这道题的一定要注意的是 right 的初始化，一定要是 nums.size() - 1，这是由于算出了 
        mid 后，nums[mid] 要和 nums[mid+1] 比较，如果 right 初始化为 nums.size() 的话，mid+1 可能会越界，从而不能找到正确的值，同时 
        while 循环的终止条件必须是 left < right，不能有等号。

        类似的还有一道 H-Index II，这道题的 target 也不是一个固定值，而是 len-mid，这就很意思了，跟上面的 nums[mid+1] 有异曲同工之妙，
        target 值都随着 mid 值的变化而变化，这里的right的初始化，一定要是 nums.size() - 1，而 while 循环的终止条件必须是 left <= right，
        这里又必须要有等号，是不是很头大 -.-!!!

        其实仔细分析的话，可以发现其实这跟第四类还是比较相似，相似点是都很难 -.-!!!，第四类中虽然是用子函数来判断关系，但大部分时候 mid 也会
        作为一个参数带入子函数进行计算，这样实际上最终算出的值还是受 mid 的影响，但是 right 却可以初始化为数组长度，循环条件也可以不带等号，
        大家可以对比区别一下～

        第五类应用实例：
        Find Peak Element
        H-Index II

        
        综上所述，博主大致将二分搜索法的应用场景分成了主要这五类，其中第二类和第三类还有各自的扩展。根据目前博主的经验来看，第二类和第三类的应用
        场景最多，也是最重要的两类。第一类，第四类，和第五类较少，其中第一类最简单，第四类和第五类最难，遇到这类，博主也没啥好建议，多多练习吧～

        如果有写的有遗漏或者错误的地方，请大家踊跃留言啊，共同进步哈～
        
        LeetCode All in One 题目讲解汇总(持续更新中...)
    */
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


/************************************************************************************************************/
/************************************************************************************************************/


class Solution91 {
public:
    // 2022.8.2, by Hsinan, can't use binary_search() as this function return boolean, but this LC
    // ask for index value. Also, why don't use upper_bound()? because it will for sure return the 
    // next one instead of target, so even if we check return and -1 to get "maybe" target value,
    // it just makes code ugly
    int search(vector<int>& nums, int target) {
        auto ret = lower_bound(nums.begin(), nums.end(), target);
        if (ret != nums.end() && *ret == target) {
            return (distance(nums.begin(), ret));
        } else { 
            return -1;
        }
    }
};


class Solution90 {
public:
    // 2022.9.3, from https://leetcode-solution.cn/book
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, h = n - 1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return -1;
    }
};


class Solution89 {
public:
    // 2022.9.3, from https://leetcode-solution.cn/book
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, h = n;
        while (l < h) {
            int mid = l + (h - l) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                // when we use "while (l < h)", h is one over its size
                h = mid;
            }
        }
        return -1;
    }
};


class Solution {
public:
    // 2022.9.3, from https://leetcode-solution.cn/book
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, h = n - 1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (nums[mid] == target) {
                h = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }

        // check bound or target value
        if (l >= nums.size() || nums[l] != target) return -1;

        // always return left if valid
        return l;
    }
};


// 2022.8.15, not in top list

// @lc code=end

