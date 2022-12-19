/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

/*

https://leetcode.cn/problems/fruit-into-baskets/

904. 水果成篮
你正在探访一家农场，农场从左到右种植了一排果树。这些树用一个整数数组 fruits 表示，其中 fruits[i] 是第 i 
棵树上的水果 种类 。

你想要尽可能多地收集水果。然而，农场的主人设定了一些严格的规矩，你必须按照要求采摘水果：

你只有 两个 篮子，并且每个篮子只能装 单一类型 的水果。每个篮子能够装的水果总量没有限制。
你可以选择任意一棵树开始采摘，你必须从 每棵 树（包括开始采摘的树）上 恰好摘一个水果 。采摘的水果应当符合篮子
中的水果类型。每采摘一次，你将会向右移动到下一棵树，并继续采摘。一旦你走到某棵树前，但水果不符合篮子的水果类型，
那么就必须停止采摘。给你一个整数数组 fruits ，返回你可以收集的水果的 最大 数目。

 
示例 1：

输入：fruits = [1,2,1]
输出：3
解释：可以采摘全部 3 棵树。

示例 2：

输入：fruits = [0,1,2,2]
输出：3
解释：可以采摘 [1,2,2] 这三棵树。
如果从第一棵树开始采摘，则只能采摘 [0,1] 这两棵树。

示例 3：

输入：fruits = [1,2,3,2,2]
输出：4
解释：可以采摘 [2,3,2,2] 这四棵树。
如果从第一棵树开始采摘，则只能采摘 [1,2] 这两棵树。

示例 4：

输入：fruits = [3,3,3,1,2,1,1,2,3,3,4]
输出：5
解释：可以采摘 [1,2,1,1,2] 这五棵树。
 

提示：

1 <= fruits.length <= 105
0 <= fruits[i] < fruits.length
通过次数62,069提交次数142,311

*/

// @lc code=start
class Solution100 {
public:
    // 2022.8.21, from https://www.acwing.com/activity/content/code/content/1313498/
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/1313498/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    int totalFruit(vector<int>& tree) {
        int res = 0;
        unordered_map<int, int> cnt;
        for (int i = 0, j = 0, s = 0; i < tree.size(); i ++ ) {
            if ( ++ cnt[tree[i]] == 1) s ++ ;
            while (s > 2) {
                if ( -- cnt[tree[j]] == 0) s -- ;
                j ++ ;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};


class Solution99 {
public:
    // 2022.8.21, by Hsinan
    int totalFruit(vector<int>& fruits) {
        int start = 0, max = 0;
        unordered_map<int, int> hashTbl;
        for (int end = 0; end < fruits.size(); end++) {
            hashTbl[fruits[end]]++;
            while (hashTbl.size() > 2) {
                // has typo below line when doing LC
                hashTbl[fruits[start]]--;
                if (hashTbl[fruits[start]] == 0) {
                    hashTbl.erase(fruits[start]);
                }
                start++;
            }
            max = std::max(max, end - start + 1);
        }
        return max;
    }
};


class Solution98 {
public:
    // 2022.8.21, from https://github.com/grandyang/leetcode/issues/904
    /*
        这道题说是给了我们一排树，每棵树产的水果种类是 tree[i]，说是现在有两种操作，第一种是将当前树的水果加入果篮中，
        若不能加则停止；第二种是移动到下一个树，若没有下一棵树，则停止。现在我们有两个果篮，可以从任意一个树的位置开始，
        但是必须按顺序执行操作一和二，问我们最多能收集多少个水果。说实话这道题的题目描述确实不太清晰，博主看了很多遍才
        明白意思，论坛上也有很多吐槽的帖子，但实际上这道题的本质就是从任意位置开始，若最多只能收集两种水果，问最多能收
        集多少个水果。那么再进一步提取，其实就是最多有两个不同字符的最长子串的长度，跟之前那道 Longest Substring 
        with At Most Two Distinct Characters 一模一样，只不过换了一个背景，代码基本都可以直接使用的，博主感觉这
        样出题有点不太好吧，完全重复了。之前那题的四种解法这里完全都可以使用，先来看第一种，使用一个 HashMap 来记录每
        个水果出现次数，当 HashMap 中当映射数量超过两个的时候，我们需要删掉一个映射，做法是滑动窗口的左边界 start 
        的水果映射值减1，若此时减到0了，则删除这个映射，否则左边界右移一位。当映射数量回到两个的时候，用当前窗口的大小
        来更新结果 res 即可，参见代码如下：
        解法一：
    */
    int totalFruit(vector<int>& tree) {
        int res = 0, start = 0, n = tree.size();
        unordered_map<int, int> fruitCnt;
        for (int i = 0; i < n; ++i) {
            ++fruitCnt[tree[i]];
            while (fruitCnt.size() > 2) {
                if (--fruitCnt[tree[start]] == 0) {
                    fruitCnt.erase(tree[start]);
                }
                ++start;
            }
            res = max(res, i - start + 1);
        }
        return res;
    }
};


class Solution97 {
public:
    // 2022.8.21, from https://github.com/grandyang/leetcode/issues/904
    /*
        我们除了用 HashMap 来映射字符出现的个数，我们还可以映射每个数字最新的坐标，比如题目中的例子 [0,1,2,2]，遇到第一个0，
        映射其坐标0，遇到1，映射其坐标1，当遇到2时，映射其坐标2，每次我们都判断当前 HashMap 中的映射数，如果大于2的时候，那么
        需要删掉一个映射，我们还是从 start=0 时开始向右找，看每个字符在 HashMap 中的映射值是否等于当前坐标 start，比如0，
        HashMap 此时映射值为0，等于 left 的0，那么我们把0删掉，start 自增1，再更新结果，以此类推直至遍历完整个数组，参见代
        码如下：
        解法二：
    */
    int totalFruit(vector<int>& tree) {
        int res = 0, start = 0, n = tree.size();
        unordered_map<int, int> fruitPos;
        for (int i = 0; i < n; ++i) {
            fruitPos[tree[i]] = i;
            while (fruitPos.size() > 2) {
                if (fruitPos[tree[start]] == start) {
                    fruitPos.erase(tree[start]);
                }
                ++start;
            }
            res = max(res, i - start + 1);
        }
        return res;
    }
};


class Solution96 {
public:
    // 2022.8.21, from https://github.com/grandyang/leetcode/issues/904
    /*
        后来又在网上看到了一种解法，这种解法是维护一个滑动窗口 sliding window，指针 left 指向起始位置，right 指向 
        window 的最后一个位置，用于定位 left 的下一个跳转位置，思路如下：

        若当前字符和前一个字符相同，继续循环。

        若不同，看当前字符和 right 指的字符是否相同：

        若相同，left 不变，右边跳到 i - 1。

        若不同，更新结果，left 变为 right+1，right 变为 i - 1。

        最后需要注意在循环结束后，我们还要比较结果 res 和 n - left 的大小，返回大的，这是由于如果数组是 [5,3,5,2,1,1,1]，
        那么当 left=3 时，i=5,6 的时候，都是继续循环，当i加到7时，跳出了循环，而此时正确答案应为 [2,1,1,1] 这4个数字，
        而我们的结果 res 只更新到了 [5,3,5] 这3个数字，所以我们最后要判断 n - left 和结果 res 的大小。

        另外需要说明的是这种解法仅适用于于不同字符数为2个的情况，如果为k个的话，还是需要用上面两种解法。

        解法三：    
    */
    int totalFruit(vector<int>& tree) {
        int res = 0, left = 0, right = -1, n = tree.size();
        for (int i = 1; i < n; ++i) {
            if (tree[i] == tree[i - 1]) continue;
            if (right >= 0 && tree[right] != tree[i]) {
                res = max(res, i - left);
                left = right + 1;
            }
            right = i - 1;
        }
        return max(n - left, res);
    }
};


class Solution95 {
public:
    // 2022.8.21, from https://github.com/grandyang/leetcode/issues/904
    /*
        还有一种不使用 HashMap 的解法，这里我们使用若干个变量，其中 cur 为当前最长子数组的长度，a和b为当前候选的两个不同的水果种类，
        cntB 为水果b的连续个数。我们遍历所有数字，假如遇到的水果种类是a和b中的任意一个，那么 cur 可以自增1，否则 cntB 自增1，因为若
        是新水果种类的话，默认已经将a种类淘汰了，此时候选水果由类型b和这个新类型水果构成，所以当前长度是 cntB+1。然后再来更新 cntB，
        假如当前水果种类是b的话，cntB 自增1，否则重置为1，因为 cntB 统计的就是水果种类b的连续个数。然后再来判断，若当前种类不是b，
        则此时a赋值为b， b赋值为新种类。最后不要忘了用 cur 来更新结果 res，参见代码如下：
        解法四：
    */
    int totalFruit(vector<int>& tree) {
        int res = 0, cur = 0, cntB = 0, a = 0, b = 0;
        for (int fruit : tree) {
            cur = (fruit == a || fruit == b) ? cur + 1 : cntB + 1;
            cntB = (fruit == b) ? cntB + 1 : 1;
            if (b != fruit) {
                a = b; b = fruit;
            }
            res = max(res, cur);
        }
        return res;
    }
};


class Solution94 {
public:
    // 2022.8.21, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/fruit-into-baskets.cpp
    // Time:  O(n)
    // Space: O(1)
    int totalFruit(vector<int>& tree) {
        unordered_map<int, int> count;
        int result = 0;
        for (int i = 0, j = 0; j < tree.size(); ++j) {
            ++count[tree[j]];
            while (count.size() > 2) {
                --count[tree[i]];
                if (count[tree[i]] == 0) {
                    count.erase(tree[i]);
                }
                ++i;
            }
            result = max(result, j - i + 1);
        }
        return result;
    }
};


class Solution93 {
public:
    // 2022.8.21, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/904.%20Fruit%20Into%20Baskets
    // OJ: https://leetcode.com/problems/fruit-into-baskets/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    // Solution 1. Sliding Window
    int totalFruit(vector<int>& A) {
        int i = 0, j = 0, N = A.size(), ans = 0;
        unordered_map<int, int> m;
        for (; j < N; ++j) {
            m[A[j]]++;
            while (m.size() > 2) {
                if (--m[A[i]] == 0) m.erase(A[i]);
                ++i;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};


class Solution92 {
public:
    // 2022.8.21, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/904.%20Fruit%20Into%20Baskets
    // OJ: https://leetcode.com/problems/fruit-into-baskets/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    // Solution 2. Non-shrinkable Sliding Window
    int totalFruit(vector<int>& A) {
        int i = 0, j = 0, N = A.size();
        unordered_map<int, int> m;
        for (; j < N; ++j) {
            m[A[j]]++;
            if (m.size() > 2) {
                if (--m[A[i]] == 0) m.erase(A[i]);
                ++i;
            }
        }
        return j - i;
    }
};


class Solution {
public:
    // 2022.8.21, from https://walkccc.me/LeetCode/problems/0904/
    int totalFruit(vector<int>& tree) {
        int ans = 0;
        unordered_map<int, int> count;

        for (int l = 0, r = 0; r < tree.size(); ++r) {
        ++count[tree[r]];
        while (count.size() > 2) {
            if (--count[tree[l]] == 0)
            count.erase(tree[l]);
            ++l;
        }
        ans = max(ans, r - l + 1);
        }

        return ans;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

