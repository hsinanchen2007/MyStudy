/*
 * @lc app=leetcode.cn id=881 lang=cpp
 *
 * [881] 救生艇
 */

/*

https://leetcode.cn/problems/boats-to-save-people/

881. 救生艇
中等
263
company
谷歌 Google
company
亚马逊
company
苹果 Apple

给定数组 people 。people[i]表示第 i 个人的体重 ，船的数量不限，每艘船可以承载的最大重量为 limit。
每艘船最多可同时载两人，但条件是这些人的重量之和最多为 limit。

返回 承载所有人所需的最小船数 。

示例 1：

输入：people = [1,2], limit = 3
输出：1
解释：1 艘船载 (1, 2)

示例 2：

输入：people = [3,2,2,1], limit = 3
输出：3
解释：3 艘船分别载 (1, 2), (2) 和 (3)

示例 3：

输入：people = [3,5,3,4], limit = 5
输出：4
解释：4 艘船分别载 (3), (3), (4), (5) 

提示：

1 <= people.length <= 5 * 104
1 <= people[i] <= limit <= 3 * 104

*/

// @lc code=start
class Solution100 {
public:
    // 2023.2.24, from https://www.acwing.com/activity/content/code/content/1248049/
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int res = 0;
        for (int i = 0, j = people.size() - 1; i <= j; j -- ) {
            if (people[j] + people[i] <= limit) i ++ ;
            res ++ ;
        }
        return res;
    }
};


class Solution99 {
public:
    // 2023.2.24, from https://walkccc.me/LeetCode/problems/0881/
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0;

        sort(begin(people), end(people));

        for (int i = 0, j = people.size() - 1; i <= j; ++ans) {
        int remain = limit - people[j--];
        if (people[i] <= remain)
            ++i;
        }

        return ans;
    }
};


class Solution98 {
public:
    // 2023.2.24, from https://github.com/grandyang/leetcode/issues/881
    /*
        这道题让我们载人过河，说是每个人的体重不同，每条船承重有个限度 limit（限定了这个载重大于等于最重人的体重），同时要求每条船
        不能超过两人，这尼玛是独木舟吧，也就比 kayak 大一点点吧（不过也有可能是公园湖中的双人脚蹬船，怀念小时候在公园划船的日子～），
        问我们将所有人载到对岸最少需要多少条船。从题目中的例子2可以看出，最肥的人有可能一人占一条船，当然如果船的载量够大的话，可能
        还能挤上一个瘦子，那么最瘦的人是最可能挤上去的，所以策略就是胖子加瘦子的上船组合。那么这就是典型的贪婪算法的适用场景啊，首先
        要给所有人按体重排个序，从瘦子到胖子，这样我们才能快速的知道当前最重和最轻的人。然后使用双指针，left 指向最瘦的人，right 
        指向最胖的人，当 left 小于等于 right 的时候，进行 while 循环。在循环中，胖子是一定要上船的，所以 right 自减1是肯定有的，
        但是还是要看能否再带上一个瘦子，能的话 left 自增1。然后结果 res 一定要自增1，因为每次都要用一条船，参见代码如下：    
    */
    int numRescueBoats(vector<int>& people, int limit) {
        int res = 0, n = people.size(), left = 0, right = n - 1;
        sort(people.begin(), people.end());
        while (left <= right) {
        	if (people[left] + people[right] <= limit) ++left;
        	--right;
        	++res;
        }
        return res;
    }
};


class Solution97 {
public:
    // 2023.2.24, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/boats-to-save-people.cpp
    // Time:  O(nlogn)
    // Space: O(n)
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int result = 0;
        int left = 0, right = people.size() - 1;
        while (left <= right) {
            ++result;
            if (people[left] + people[right] <= limit) {
                ++left;
            }
            --right;
        }
        return result;
    }
};


class Solution96 {
public:
    // 2023.2.24, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/881.%20Boats%20to%20Save%20People
    // OJ: https://leetcode.com/problems/boats-to-save-people/
    // Author: github.com/lzl124631x
    // Time: O(NlogD) where N is to total number of people
    //                and D is the distinct count of weights.
    // Space: O(D)
    /*
        Solution 1. Greedy
        The first intuition is that we can greedily fill from heavy people or from light people. From heavy is more 
        promising because we can use the light people to fill in the boats.    
    */
    int numRescueBoats(vector<int>& people, int limit) {
        map<int, int, greater<int>> m;
        for (int w : people) m[w]++;
        int ans = 0;
        while (m.size()) {
            int w = limit, cnt = 0;
            while (w > 0 && cnt < 2) {
                auto it = m.lower_bound(w);
                if (it == m.end()) break;
                w -= it->first;
                if (--it->second == 0) m.erase(it->first);
                ++cnt;
            }
            ++ans;
        }
        return ans;
    }
};


class Solution95 {
public:
    // 2023.2.24, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/881.%20Boats%20to%20Save%20People
    // OJ: https://leetcode.com/problems/boats-to-save-people/
    // Author: github.com/lzl124631x
    // Time: O(NlogN)
    // Space: O(1)
    /*
        Solution 2. Greedy + Two Pointers
        For the lightest person a, if a can pair with the heaviest person b, let a do so.

        If not, then the heaviest person b can't pair with any one, let b go alone.    
    */
    int numRescueBoats(vector<int>& A, int limit) {
        sort(begin(A), end(A));
        int i = 0, j = A.size() - 1, ans = 0;
        while (i <= j) {
            ++ans;
            if (A[i] + A[j] <= limit) ++i;
            --j;
        }
        return ans;
    }
};


class Solution94 {
public:
    // 2023.2.24, from https://github.com/wisdompeak/LeetCode/blob/master/Greedy/881.Boats-to-Save-People/881.Boats-to-Save-People_v1.cpp
    /*
        解法1：
        容易想到比较严谨的贪心解，就是找到当前最重的小胖x，然后找到当前最大的小瘦y使得x+y<=limit，这样x和y的配对是对资源的
        最优利用。

        事实上这个贪心法可以进行松弛：对于当前最重的小胖x，只需要找到当前最小的小瘦y进行配对，就可以实现对资源的最优利用。
        分析如下。假设我们将所有人从轻到重排序y1,y2,y3,y4,...,x4,x3,x2,x1。对于当前最重的小胖对应的是x1，假设如果根据严谨的
        贪心算法找到的配对是y4（也就是恰好满足y4+x1<=limit），那么容易证明{x1,y1},{x2,y2},{x3,y3},{x4,y4}这四对其实都满足
        条件（即两个人加起来不超过limit）。所以我们可以将这四对剥离（因为已经充分利用了资源），对于剩下的人同理进行递归处理就
        可以了。

        于是这道题就转化为了双指针。左右指针朝中间移动，计算有多少对满足people[i]+people[j]<=limit.

        这种解法最大的隐患是时间复杂度需要O(NlogN)，勉强可以通过。    
    */
    int numRescueBoats(vector<int>& people, int limit) 
    {
        sort(people.begin(), people.end());
        int i=0, j=people.size()-1;
        int count = 0;
        while (i<=j)
        {
            if (people[i]+people[j]<=limit)
                i++;
            j--;
            count++;
        }
        return count;
    }
};


class Solution93 {
public:
    // 2023.2.24, from https://github.com/wisdompeak/LeetCode/blob/master/Greedy/881.Boats-to-Save-People/881.Boats-to-Save-People_v2.cpp
    /*
        解法2：
        如何避免排序就能确定最重的人是谁呢？我们可以借鉴桶排序的思想：用一个计数器数组p来记录每个重量的人数。

        假设当前最重的小胖的体重是x，那么对于x的值我们可以从limit开始往下猜，一旦发现p[x]>0，说明我们找到了这个最重的人。那么如何
        寻找x的最合理队友呢？我们可以从体重y=limit-x开始往下猜，一旦发现p[y]>0，就说明我们找到了最适合与x配对的小瘦（其体重为y）。
        记得每次配对之后，我们都需要及时更新计数器p[x]-- and/or p[y]--.

        这种解法最大的雷区在于：如果遇到了x==y的情况，说明小胖和小瘦的体重相同，那么对于小胖的处理次数就不是原先的p[x]了，而是需要
        及时减去一才对。    
    */
    int numRescueBoats(vector<int>& people, int limit) 
    {
        vector<int>p(limit+1,0);
        for (int w: people)
            p[w]++;
        
        int count = 0;
        for (int x = limit; x>0; x--)   // weight of the heaviest guy up to now
        {
            for (int i = p[x]; i>0; i--)
            {
                count++;
                p[x]--;
                
                int y = limit-x;
                while (y>0 && p[y]==0) y--;
                if (y>0) p[y]--;
                if (x==y) i--;
            }
        }
        return count;
    }
};


class Solution92 {
public:
    // 2023.2.24, from https://github.com/wisdompeak/LeetCode/blob/master/Greedy/881.Boats-to-Save-People/881.Boats-to-Save-People_v3.cpp
    /*
        解法3：
        可以将解法1的松弛贪心思想，以及解法2桶排序的思想结合起来。基本思想依然是双指针，但指针指的不是数组首尾的index，
        而是区间范围[1,limit]左右边界的value.

        假设当前最重的小胖的体重是x，那么对于x的值我们可以从limit开始往下猜，一旦发现p[x]>0，说明我们找到了这个最重的人。
        同时我们寻找当前最轻的小瘦，假设其体重为y，对于y的值我们可以从1开始往上猜，一旦发现p[y]>0，说明我们找到了当前最轻
        的人。对于每个小胖我们都试图寻找当前最轻的小瘦，如果符合x+y<0 && p[y]>0就说明存在它可以与小胖同船。

        显然容易分析出时间复杂度是o(N+limit)，比解法1要优秀.    
    */
    int numRescueBoats(vector<int>& people, int limit) 
    {
        vector<int>p(limit+1,0);
        for (int w: people)
            p[w]++;
        
        int count = 0;
        int x = limit;
        int y = 1;
        
        while (x>0)
        {
            while (x>0 && p[x]==0)
                x--;
            if (x==0) break;
            count++;
            p[x]--;
            
            while (y+x<=limit && p[y]==0) 
                y++;
            if (y+x<=limit && p[y]>0) 
                p[y]--;
        }
                
        return count;
    }
};


class Solution {
public:
    // 作者：xzp
    // 链接：https://leetcode.cn/leetbook/read/sliding-window-and-two-pointers/rw29pr/?discussion=1bwl0t
    // 来源：力扣（LeetCode）
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int ans = 0 , l = 0 , r = n - 1;
        sort(people.begin() , people.end());
        while(l <= r){
            if(people[l] + people[r] > limit) --r;
            else{
                l++;
                r--;
            }
            ans++;
        }
        return ans;
    }
};


// @lc code=end

