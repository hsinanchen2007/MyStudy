/*
 * @lc app=leetcode.cn id=995 lang=cpp
 *
 * [995] K 连续位的最小翻转次数
 */

/*

https://leetcode.cn/problems/minimum-number-of-k-consecutive-bit-flips/

995. K 连续位的最小翻转次数

困难
260
company
微软 Microsoft

给定一个二进制数组 nums 和一个整数 k 。

k位翻转 就是从 nums 中选择一个长度为 k 的 子数组 ，同时把子数组中的每一个 0 都改成 1 ，把子数组中的每一个 1 都改成 0 。
返回数组中不存在 0 所需的最小 k位翻转 次数。如果不可能，则返回 -1 。

子数组 是数组的 连续 部分。

示例 1：

输入：nums = [0,1,0], K = 1
输出：2
解释：先翻转 A[0]，然后翻转 A[2]。

示例 2：

输入：nums = [1,1,0], K = 2
输出：-1
解释：无论我们怎样翻转大小为 2 的子数组，我们都不能使数组变为 [1,1,1]。

示例 3：

输入：nums = [0,0,0,1,0,1,1,0], K = 3
输出：3
解释：
翻转 A[0],A[1],A[2]: A变成 [1,1,1,1,0,1,1,0]
翻转 A[4],A[5],A[6]: A变成 [1,1,1,1,1,0,0,0]
翻转 A[5],A[6],A[7]: A变成 [1,1,1,1,1,1,1,1]
 

提示：

1 <= nums.length <= 105
1 <= k <= nums.length

*/

// @lc code=start
class Solution100 {
public:
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/2013629/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> s(n + 1);

        for (int i = 1; i <= n; i ++ ) {
            int t = s[i - 1] - s[max(i - k, 0)] & 1;
            nums[i - 1] ^= t;
            if (!nums[i - 1]) {
                if (i >= n - k + 2) return -1;
                s[i] ++ ;
            }
            s[i] += s[i - 1];
        }

        return s[n];
    }
};


class Solution99 {
public:
    // 2023.2.11, from https://github.com/grandyang/leetcode/issues/995
    /*
        这道题博主最先在某家公司的 OA 上看到过（OA 出 Hard 题，也真是给跪了～），给了一个只有0和1的数组，又给了一个数字K，
        说是每次可以翻转任意连续K个位置的数字，问我们多少步可以把所有的0都翻转为1。这是道挺有意思的题目，背景可以随便换，
        比如什么烙煎饼啊，翻煎鸡蛋啊，都是一样的问题。注意我们翻转的时候，一旦选定了起始点，那么只能翻连着的K个位置，由于
        无法影响到前面的0的，所以需要在遇到0的时候，就进行翻转，这就是明显的贪婪算法的特征，这要一遇到0，就立马翻连续K个位置
        ，比如对于数组 [0,1,0]，K = 2，遇到位置0上的0，翻转，变为 [1,0,0]，此时遇到位置1上的0，翻转，变为 [1,1,1]，操作
        完成。想法有了，于是就吭哧吭哧的写好了代码，交给 OJ 大人审阅，结果被驳回，Time Limit Exceeded，什么鬼？那么仔细想
        一下吧，上面的这种解法到底哪里最费时，当然是翻转K个位置了，若K非常大，而且若需要翻转的位置很多的话，将非常的不高效。
        所以当务之急就是想办法代替真实的翻转，最简单的方法就是记录起始翻转的位置，我们使用一个长度相同的数组 isFlipped，
        其中 isFlipped[i] 表示在原数组i位置上进行了K个连续翻转。现在虽然知道了其实翻转的位置，但是由于是连续翻转K个，之后
        的位置也被翻转，比如 [0,1,0] 在位置0翻转后，变为了 [1,0,0]，那么位置1就从之前的1变为0了，此时位置1也需要翻转了，
        那么我们怎么知道非起始翻转位置的数字当前是0还是1呢，这时就要引入另一个变量 curFlipped 了，表示当前位置的数字跟原数组
        相比是否被翻转了。所以一旦决定对当前位置进行翻转，那么需要将 isFlipped[i] 标记为1，并且翻转 curFlipped，方法是
        '异或'上1，举个例子来说对于数组 [0,1,0,1], K=3 来说，当对位置0进行翻转，数组变为 [1,0,1,0]，那么在位置1的时候，
        curFlipped 是1，表示此时0相对于原来的1是翻转了，若我们在为1时再次进行翻转，数组变为 [1,1,0,1]，此时 curFlipped 
        变为0了，表明位置2上的0对于原数组的位置2上的0来说没有翻转（虽然实际上翻转了两次），那么我们怎么知道某个位置应不应该
        翻转呢？需要根据 curFlipped 的值和原数组 A[i] 的值进行比较来判断，此时有两种情况：

        当 curFlipped 为0，表示没有翻转，且原数组 A[i] 为0，此时就需要翻转i位置。

        当 curFlipped 为1，表示翻转过了，而原数组 A[i] 为1，表示虽然原来是1，但是当前位置受之前翻转的影响变成了0，此时就需要翻转回来。

        仔细观察上面两种情况可以发现 curFlipped 和 A[i] 同奇同偶的时候就需要翻转，那么两种情况可以合成一个表达式，curFlipped%2 
        等于 A[i] 时翻转。还需要弄清楚当什么时候就无法翻转了，当 i+K 大于n的时候，比如 [1,1,0,1], k=3 时，在位置2的时候 
        i+k>n（2+3>4）了，表示无法翻转了，直接返回 -1 即可。最后需要注意的是，curFlipped 受影响的位置只有在大小为K的窗口中，
        一旦超过了，是需要还原 curFlipped 的状态的。比如 [0,0,0,1], K=2 时，在位置0翻转后变为 [1,1,0,1]，那么到位置2的时候，
        由于已经不受位置0翻转的影响了，此时的 curFlipped 应该变回0，所以只要'异或'上 isFlipped[0] 进行翻转，所以我们在循环开始
        前，首先检测 i>=K 是否成立，成立的话就让 curFlipped '异或'上 isFlipped[i-K] 进行状态还原，即便是位置 i-K 未进行过翻转，
        '异或'上0也不会改变 curFLipped 的状态，参见代码如下：

        解法一：    
    */
    int minKBitFlips(vector<int>& A, int K) {
        int res = 0, n = A.size(), curFlipped = 0;
        vector<int> isFlipped(n);
        for (int i = 0; i < n; ++i) {
        	if (i >= K) curFlipped ^= isFlipped[i - K];
        	if (curFlipped % 2 == A[i]) {
        		if (i + K > n) return -1;
        		isFlipped[i] = 1;
        		curFlipped ^= 1;
        		++res;
        	}
        }
        return res;
    }
};


class Solution98 {
public:
    // 2023.2.11, from https://github.com/grandyang/leetcode/issues/995
    /*
        根据上面的分析，对于每个位置i，我们其实只关心 i-K 位置是否是起始翻转的位置，之前什么情况并不 care，那么就没必要用整个数组
        来保存所有的起始翻转位置，只需要维护一个大小为K的窗口，将在此窗口内的起始翻转位置保存即可，超出范围的就扔掉。可以使用一个 
        queue 来保存窗口内的起始位置，在遍历的过程中，首先检测队首元素是否超出了范围，是的话就扔掉，否则就接着判断当前位置是否需要
        翻转，判断的方法是看此窗口中起始翻转的个数是否跟 A[i] 同奇同偶，推导方式跟上面解法中类似，这里就不过多讲解了，之后就判断所
        剩位置是否还有K个，没有就返回 -1。然后将当前位置加入队列，结果 res 自增1即可，参见代码如下：    
    */
    int minKBitFlips(vector<int>& A, int K) {
        int res = 0, n = A.size();
        queue<int> q;
        for (int i = 0; i < n; ++i) {
        	if (!q.empty() && i >= (q.front() + K)) q.pop();
        	if (q.size() % 2 == A[i]) {
        		if (i + K > n) return -1;
        		q.push(i);
        		++res;
        	}
        }
        return res;
    }
};


class Solution97 {
public:
    // 2023.2.11, from https://github.com/grandyang/leetcode/issues/995
    /*
        我们还可以进一步的优化空间，连队列 queue 都不需要，直接在原数组上修改，从而达到标记的目的，在解法一中，我们是新建了一个数组
        ，对于起始翻转位置标记为1，其余为0。这里由于原数组已经使用了0和1，可以对于起始位置，将 A[i] 加上2，这样起始翻转位置的值就成
        了2或者3，跟原来的0和1就区分开了，那么只要将 A[i] 除以2，根据商是1还是0，就可以知道该位置是否是起始翻转位置，其余的地方基本
        相同，不过这里的 flipped 更新并没有用异或，而是直接用的加减，为了 diversity 也是拼了，参见代码如下：    
    */
    int minKBitFlips(vector<int>& A, int K) {
        int res = 0, n = A.size(), flipped = 0;
        for (int i = 0; i < n; ++i) {
        	if (i >= K) flipped -= A[i - K] / 2;
        	if (flipped % 2 == A[i]) {
        		if (i + K > n) return -1;
        		A[i] += 2;
        		++flipped;
        		++res;
        	}
        }
        return res;
    }
};


class Solution96 {
public:
    // 2023.2.11, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/minimum-number-of-k-consecutive-bit-flips.cpp
    // Time:  O(n)
    // Space: O(1)
    int minKBitFlips(vector<int>& A, int K) {
        int result = 0, curr = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (i >= K) {
                curr -= A[i - K] / 2;
            }
            if (curr & 1 ^ A[i] == 0) {
                if (i + K > A.size()) {
                    return -1;
                }
                A[i] += 2;
                ++curr;
                ++result;
            }
        }
        return result;
    }
};


class Solution95 {
public:
    // OJ: https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(K)
    int minKBitFlips(vector<int>& A, int k) {
        queue<int> q;
        int ans = 0;
        for (int i = 0, N = A.size(); i < N; ++i) {
            if (q.size() && q.front() <= i) q.pop();
            int flip = q.size() % 2;
            if ((A[i] ^ flip) == 0) {
                if (i + k > N) return -1;
                ++ans;
                q.push(i + k);
            }
        }
        return ans;
    }
};


class Solution94 {
public:
    // 2023.2.11, from https://walkccc.me/LeetCode/problems/0995/
    int minKBitFlips(vector<int>& A, int K) {
        int ans = 0;
        int flippedTime = 0;

        for (int r = 0; r < A.size(); ++r) {
            if (r >= K && A[r - K] == 2)
                --flippedTime;
            if (flippedTime % 2 == A[r]) {
                if (r + K > A.size())
                    return -1;
                ++ans;
                ++flippedTime;
                A[r] = 2;
            }
        }

        return ans;
    }
};


class Solution93 {
public:
    // 2023.2.11, from https://github.com/wisdompeak/LeetCode/blob/master/Others/995.Minimum-Number-of-K-Consecutive-Bit-Flips/995.Minimum-Number-of-K-Consecutive-Bit-Flips.cpp
    /*
        995.Minimum-Number-of-K-Consecutive-Bit-Flips

        本题的最优策略其实很容易想到。我们从前往后依次查看A[i]：如果A[i]是1，那么我们就跳过；如果A[i]是0，那么我们就翻转A[i]，
        同时需要带着一起翻转A[i+1]~A[i+K-1]。这样一直查下去，看最后K个数是否都是1. 显然我们就有了O(NK)的解法。C++耗时5000多
        毫秒，竟然也给过了。

        很明显，上述解法的最大弊端是：当A[i]需要翻转时，我们还需要用for循环逐个翻转A[i+1]~A[i+K-1]，效率很差。很容易想到一个
        简单的改进的方法，用差分数组diff.差分数组diff[j]记录的是：A[j]经历的翻转次数要比A[j-1]经历的翻转次数多多少？比如说，
        我们将当前的A[i]翻转了，将会使得A[i+1]~A[i+K-1]整体的翻转次数提升一个，但是之后就又回落下去了。所以就记录下diff[i+1]+=1, 
        diff[i+K]-=1，这样的话，对任意A[j]经历过的翻转总数是flipNum，那么A[j+1]需要经历的翻转总数就是flipNum+diff[j+1]。

        类似用到差分数组的题目还有：370.Range-Addition
    */
    int minKBitFlips(vector<int>& A, int K) 
    {
        int n = A.size();
        vector<int>diff(n+1);

        int flips = 0;
        int count = 0;
        for (int i=0; i<n; i++)
        {
            flips+=diff[i];
            if ((A[i]+flips)%2==1) continue;

            if (i+K-1>=n) return -1;
            flips++;
            count++;
            diff[i+K]-=1;
        }

        return count;
    }
};


class Solution92 {
public:
    // 2023.2.11, from https://zxi.mytechroad.com/blog/?s=LeetCode+995.
    // Author: Huahua, running time: 5172 ms, 16.4 MB
    // Note: Time Limit Exceeded
    int minKBitFlips(vector<int>& A, int K) {
        int ans = 0;    
        for (int i = 0; i <= A.size() - K; ++i) {
            if (A[i] == 1) continue;
            ++ans;
            for (int j = 0; j < K; ++j)
                A[i + j] ^= 1;      
        }
        for (int i = A.size() - K + 1; i < A.size(); ++i)
            if (A[i] == 0) return -1;
        return ans;
    }
};


class Solution {
public:
    // 2023.2.11, from https://zxi.mytechroad.com/blog/?s=LeetCode+995.
    // Author: Huahua, running time: 100 ms, 19.6 MB
    int minKBitFlips(vector<int>& A, int K) {
        vector<int> flipped(A.size());
        int ans = 0;    
        int flip = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (i >= K) flip ^= flipped[i - K];
            if ((A[i] ^ flip) == 0) {
                if (i + K > A.size()) return -1;
                ++ans;
                flip ^= 1;
                flipped[i] = 1;
            }
        }    
        return ans;
    }
};


// @lc code=end

