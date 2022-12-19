/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

/*

https://leetcode.cn/problems/koko-eating-bananas/

875. 爱吃香蕉的珂珂
珂珂喜欢吃香蕉。这里有 n 堆香蕉，第 i 堆中有 piles[i] 根香蕉。警卫已经离开了，将在 h 小时后回来。

珂珂可以决定她吃香蕉的速度 k （单位：根/小时）。每个小时，她将会选择一堆香蕉，从中吃掉 k 根。
如果这堆香蕉少于 k 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉。  

珂珂喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。

返回她可以在 h 小时内吃掉所有香蕉的最小速度 k（k 为整数）。


示例 1：

输入：piles = [3,6,7,11], h = 8
输出：4

示例 2：

输入：piles = [30,11,23,4,20], h = 5
输出：30

示例 3：

输入：piles = [30,11,23,4,20], h = 6
输出：23
 

提示：

1 <= piles.length <= 104
piles.length <= h <= 109
1 <= piles[i] <= 109
通过次数105,926提交次数209,154

*/

/*
    From https://www.geekxh.com/1.9.%E4%BA%8C%E5%88%86%E6%B3%95%E7%B3%BB%E5%88%97/901.html#_03%E3%80%81%E9%A2%98%E7%9B%AE%E5%88%86%E6%9E%90

    02、二分查找
    十个二分九个错，该算法被形容 "思路很简单，细节是魔鬼"。第一个二分查找算法于 1946 年出现，然而第一个完全正确
    的二分查找算法实现直到1962 年才出现。下面的二分查找，其实是二分查找里最简单的一个模板，在后面的文章系列里，
    我将逐步为大家讲解二分查找的其他变形形式。

    二分查找是计算机科学中最基本、最有用的算法之一。它描述了在有序集合中搜索特定值的过程。一般二分查找由以下几个
    术语构成：

        目标 Target —— 你要查找的值
        索引 Index —— 你要查找的当前位置
        左、右指示符 Left，Right —— 我们用来维持查找空间的指标
        中间指示符 Mid —— 我们用来应用条件来确定我们应该向左查找还是向右查找的索引

    在最简单的形式中，二分查找对具有指定左索引和右索引的连续序列进行操作。我们也称之为查找空间。二分查找维护查找
    空间的左、右和中间指示符，并比较查找目标；如果条件不满足或值不相等，则清除目标不可能存在的那一半，并在剩下的
    一半上继续查找，直到成功为止。

    PNG
    举例说明：比如你需要找1-100中的一个数字，你的目标是用最少的次数猜到这个数字。你每次猜测后，我会说大了或者小了。
    而你只需要每次猜测中间的数字，就可以将余下的数字排除一半。

    PNG
    不管我心里想的数字如何，你在7次之内都能猜到，这就是一个典型的二分查找。每次筛选掉一半数据，所以我们也称之为 
    折半查找。一般而言，对于包含n个元素的列表，用二分查找最多需要log2n步。

    PNG
    当然，一般题目不太可能给你一个如此现成的题型，让你上手就可以使用二分，所以我们需要思考，如何来构造一个成功的
    二分查找。大部分的二分查找，基本都由以下三步组成：

        预处理过程（大部分场景就是对未排序的集合进行排序）
        二分查找过程（找到合适的循环条件，每一次将查找空间一分为二）
        后处理过程（在剩余的空间中，找到合适的目标值）

    了解了二分查找的过程，我们对二分查找进行一般实现（这里给出一个Java版本，比较正派的代码，没有用一些缩写形式）

    //JAVA 
    public int binarySearch(int[] array, int des) {
        int low = 0, high = array.length - 1;
        while (low <= high) { 
            int mid = low + (high - low) / 2;
            if (des == array[mid]) { 
                return mid;
            } else if (des < array[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
    注意：上面的代码，mid 使用 low + (high - low)/2 的目的，是防止 high low 溢出内存。

    为什么说是一般实现？
        1、根据边界的不同（开闭区间调整），有时需要弹性调整low与high的值，以及循环的终止条件。
        2、根据元素是否有重复值，以及是否需要找到重复值区间，有时需要对原算法进行改进。

    那上面我们说了，一般二分查找的过程分为：预处理 - 二分查找 - 后处理，上面的代码，就没有后处理的过程，因为在
    每一步中你都检查了元素，如果到达末尾，也已经知道没有找到元素。

    总结一下一般实现的几个条件：
        初始条件：left = 0, right = length-1
        终止：left > right
        向左查找：right = mid-1
        向右查找：left = mid +1

    请大家记住这个模板原形，在后面的系列中，我们将介绍二分查找其他的模板类型。

    #03、题目分析
    简单复习了二分查找，我们来看本题。

    注意，绝大部分 「在递增递减区间中搜索目标值」 的问题，都可以转化为二分查找问题。并且，二分查找的题目，
    基本逃不出三种：找特定值，找大于特定值的元素（上界），找小于特定值的元素（下界）。

    而根据这三种，代码又最终会转化为以下这些问题：
        low、high 要初始化为 0、n-1 还是 0、n 又或者 1，n？
        循环的判定条件是 low < high 还是 low <= high？
        if 的判定条件应该怎么写？
        if 条件正确时，应该移动哪边的边界？
        更新 low 和 high 时，mid 如何处理？

    处理好了上面的问题，自然就可以顺利解决问题。将上面的思想代入到本题，我们要找 “阿珂在 H 小时吃掉所有
    香蕉的最小速度 K”。那最笨的就是阿珂吃的特别慢，每小时只吃掉 1 根香蕉，然后我们逐渐递增阿珂吃香蕉的
    速度到 i，刚好满足在 H 小时可以吃掉所有香蕉，此时 i 就是我们要找的最小速度。当然，我们没有这么笨，
    所以可以想到使用二分的思想来进行优化。

    然后就简单了，我们寻找二分查找模板中初始条件和终止条件（注意，这里的 high、low、mid 都代表的是速度）：

    //这里我把最小速度定义成了1，可能大家会觉得奇怪，模板里不是0吗？
    //所以这里我其实是想说，算法千变万化，大家不要生搬硬套。
    //从字面理解，如果定义成0，意味着阿珂会选择一个香蕉都不吃，难道阿珂傻？   
        var low = 1
        //最大的速度，当然等于吃掉最大一堆的香蕉，毕竟一小时只能吃一堆，再大也没有意义
        var high = maxArr(piles)
        //中间速度
        var mid = (low + high) / 2

    //JAVA 
    public class Solution {
            public int minEatingSpeed(int[] piles, int H) {
            int maxVal = 1;
            for (int pile : piles) {
                maxVal = Math.max(maxVal, pile);
            }
            int left = 1;
            int right = maxVal;
            while (left < right) {
                int mid = (left + right) >> 1;
                if (canEat(piles, mid, H)) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            return left;
        }

        private boolean canEat(int[] piles, int speed, int H) {
            int sum = 0;
            for (int pile : piles) {
                //向上取整
                sum += Math.ceil(pile * 1.0 / speed);
            }
            return sum > H;
        }
    }
    执行结果:

    PNG
    额外补充（昨天有人问我的问题）：

        第一：就是不需要再对原数组进行排序了，因为我们是把这样一个问题转化为二分查找的问题，而通过 
        canEat，计算在 mid 速度下吃完 piles 共需要多少小时。已经将 piles 利用进去了，所以此时
        并不需要对 piles 排序。
        
        第二：就是昨天有人私下问我，对 (pile speed - 1)/speed 不能理解。这个其实就是向上取整的
        一个小技巧，相当于Math.ceil(pile * 1.0 / speed)。

    留下一个问题，假如我们的阿珂就是笨笨的，将 low 初始化成了 0，此时的循环条件应该如何写？if 条件
    如果成立，low 和 high 又该如何进行调整？大家可以尝试一下！（一百个人有一百个二分，不要妄图和
    别人写出一模一样的代码，这是没有意义的。只有自己理解了，一步步的分析问题，写出自己的代码，才是真正
    属于你的）

    所以，今天的问题你学会了吗？评论区留下你的想法！
*/

// @lc code=start
class Solution100 {
public:
    // 2022.7.31, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/875.%20Koko%20Eating%20Bananas
    /*
        Search a eating speed K between [1, P_max] where P_max is the max pile size. 
        The K should be the first (smallest) one requiring h (h <= H) hour to consume 
        all the bananas.
    */
    // OJ: https://leetcode.com/problems/koko-eating-bananas/
    // Author: github.com/lzl124631x
    // Time: O(P*log(P_max)) where P is count of piles, P_max is max pile size.
    // Space: O(K)
    int minEatingSpeed(vector<int>& A, int h) {
        long L = 1, R = *max_element(begin(A), end(A)), N = A.size();
        auto valid = [&](long k) {
            int i = 0, tmp = h; 
            for (; i < N && h > 0; ++i) {
                tmp -= (A[i] + k - 1) / k;
            }
            return i == N && tmp >= 0;
        };
        while (L <= R) {
            long M = (L + R) / 2;
            if (valid(M)) R = M - 1;
            else L = M + 1;
        }
        return L;
    }
};


class Solution99 {
public:
    // 2022.7.31, from https://walkccc.me/LeetCode/problems/0875/
    // Time: O(nlog(max(piles)))
    // Space: O(1)
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(begin(piles), end(piles));

        while (l < r) {
            const int m = (l + r) / 2;
            if (eatHours(piles, m) <= h)
                r = m;
            else
                l = m + 1;
        }

        return l;
    }

private:
    // hours to eat all piles with speed m
    int eatHours(const vector<int>& piles, int m) {
        return accumulate(begin(piles), end(piles), 0, [&](int subtotal, int pile) {
            return subtotal + (pile - 1) / m + 1;  // ceil(pile / m)
        });
    }
};


class Solution98 {
public:
    // 2022.7.31, from https://www.guozet.me/leetcode/Leetcode-875-Koko-Eating-Bananas.html?h=ko
    /*
        Koko　吃香蕉的速度是 K , 吃香蕉的最大速度去所有香蕉堆里面的最大值就好，所以有left = 1, 
        right = *max_element(piles.begin(), piles.end()) + 1; 其中最右边的值是可以不选取的，
        为此我们计算按照这个取得的中间速度计算 kolo能不能在这个中间速度mid内吃完香蕉。如果吃完的时间
        花费小于限制的时间，那我们就减下吃香蕉的速度，反之就增加吃香蕉的速度。
    */
    // Time complexity: O(log max_speed), Space complexity: O(1)
    int minEatingSpeed(vector<int>& piles, int H) {
        // 1) [l, r) -- This is the range for the number of piles
        int left = 1, right = *max_element(piles.begin(), piles.end()) + 1;
        while (left < right) {
            int mid = left + (right - left) / 2, h = 0;
            for (int& pile : piles) h += (pile + mid - 1) / mid;
            h <= H ? right = mid : left = mid + 1;  // Can finished
        }
        return left;
    }
};


class Solution97 {
public:
    // 2022.7.31, from https://www.acwing.com/activity/content/code/content/1247031/
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/1247031/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    int get(vector<int>& piles, int mid) {
        int res = 0;
        for (auto x: piles)
            res += (x + mid - 1) / mid;
        return res;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1e9;
        while (l < r) {
            int mid = l + r >> 1;
            if (get(piles, mid) <= h) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};


class Solution96 {
public:
    // 2022.7.31, from https://github.com/grandyang/leetcode/issues/875
    /*
        这道题说有一只叫科科的猩猩，非常的喜欢吃香蕉，现在有N堆香蕉，每堆的个数可能不同，科科有H小时的时间来吃。
        要求是，每个小时内，科科只能选某一堆香蕉开始吃，若科科的吃速固定为K，即便在一小时内科科已经吃完了该堆的
        香蕉，也不能换堆，直到下一个小时才可以去另一堆吃。为了健康，科科想尽可能的吃慢一些，但同时也想在H小时内
        吃完所有的N堆香蕉，让我们找出一个最小的吃速K值。那么首先来想，既然每个小时只能吃一堆，总共要在H小时内吃
        完N堆，那么H一定要大于等于N，不然一定没法吃完N堆，这个条件题目中给了，所以就不用再 check 了。我们想一
        下K的可能的取值范围，当H无穷大的时候，科科有充足的时间去吃，那么就可以每小时只吃一根，也可以吃完，所以K
        的最小取值是1。那么当H最小，等于N时，那么一个小时内必须吃完任意一堆，那么K值就应该是香蕉最多的那一堆的
        个数，题目中限定了不超过 1e9，这就是最大值。所以要求的K值的范围就是 [1, 1e9]，固定的范围内查找数字，
        当然，最暴力的方法就是一个一个的试，凭博主多年与 OJ 抗衡的经验来说，基本可以不用考虑的。那么二分查找法
        就是不二之选了，我们知道经典的二分查找法，是要求数组有序的，而这里香蕉个数数组又不一定是有序的。这是一个
        很好的观察，但是要弄清楚到底是什么应该是有序的，要查找的K是吃速，跟香蕉堆的个数并没有直接的关系，而K所在
        的数组其实应该是 [1, 1e9] 这个数组，其本身就是有序的，所以二分查找没有问题。实际上这是博主之前那篇总结帖 
        LeetCode Binary Search Summary 二分搜索法小结 中的第四类 - 用子函数当作判断关系。当求出了 mid 
        之后，需要统计用该速度吃完所有的香蕉堆所需要的时间，统计的方法就是遍历每堆的香蕉个数，然后算吃完该堆要的
        时间。比如 K=4，那么假如有3个香蕉，需要1个小时，有4香蕉，还是1个小时，有5个香蕉，就需要两个小时，如果将
        三种情况融合为一个式子呢，就是用吃速加上香蕉个数减去1，再除以吃速即可，即 (pile+mid-1)/mid，大家可以
        自行带数字检验，是没有问题的。算出需要的总时间后去跟H比较，若小于H，说明吃的速度慢了，需要加快速度，所以 
        left 更新为 mid+1，否则 right 更新为 mid，最后返回 right 即可，参见代码如下：
    */
    int minEatingSpeed(vector<int>& piles, int H) {
        int left = 1, right = 1e9;
        while (left < right) {
            int mid = left + (right - left) / 2, cnt = 0;
            for (int pile : piles) cnt += (pile + mid - 1) / mid;
            if (cnt > H) left = mid + 1;
            else right = mid;
        }
        return right;
    }
};


class Solution95 {
public:
    // 2022.7.31, from https://github.com/grandyang/leetcode/issues/875
    // modified by Hsinan
    int minEatingSpeed(vector<int>& piles, int H) {
        int left = 1, right = 1e9;
        while (left <= right) {
            long long mid = left + (right - left) / 2, cnt = 0;
            for (int pile : piles) cnt += (pile + mid - 1) / mid;
            if (cnt > H) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
};


class Solution94 {
public:
    // 2022.7.31, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/koko-eating-bananas.cpp
    // With a fix by Hsinan to pass latest LC
    // Time:  O(nlogr)
    // Space: O(1)
    int minEatingSpeed(vector<int>& piles, int H) {
        int left = 1, right = *max_element(piles.cbegin(), piles.cend());
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (possible(piles, H, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    bool possible(const vector<int>& piles, int H, int K) {
        // modified by Hsinan, need to change below to long long otherwise it will cause overflow
        long long time = 0;
        for (const auto& pile : piles) {
            time += (pile - 1) / K + 1;
        }
        return time <= H;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


class Solution {
public:
    // 2022.9.3, from https://leetcode-solution.cn/book
    int minEatingSpeed(vector<int>& piles, int H) {
        int maxPile = piles[0];
        for (int pile : piles) {
            if (pile > maxPile) {
                maxPile = pile;
            }
        }
        int l = 1, h = maxPile;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (l == h) {
                return l;
            } else if (help(piles, mid, H)) {
                h = mid;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
    // 判断速度 k 是否满足条件
    bool help(vector<int>& piles, int k, int H) {
        int cnt = 0;
        for (int pile : piles) {
            cnt += (pile - 1) / k + 1;
        }
        return cnt <= H;
    }
};


// 2022.8.15, not in top list

// @lc code=end

