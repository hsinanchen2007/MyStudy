/*

https://leetcode.cn/problems/k-empty-slots/

683. K 个关闭的灯泡
困难
78
company
亚马逊
company
英伟达 NVIDIA
company
谷歌 Google

n 个灯泡排成一行，编号从 1 到 n 。最初，所有灯泡都关闭。每天 只打开一个 灯泡，直到 n 天后所有灯泡都打开。
给你一个长度为 n 的灯泡数组 blubs ，其中 bulls[i] = x 意味着在第 (i+1) 天，我们会把在位置 x 的灯泡打开，其中 i 从 0 开始，x 从 1 开始。
给你一个整数 k ，请返回恰好有两个打开的灯泡，且它们中间 正好 有 k 个 全部关闭的 灯泡的 最小的天数 。如果不存在这种情况，返回 -1 。

示例 1：

输入：
bulbs = [1,3,2]，k = 1
输出：2
解释：
第一天 bulbs[0] = 1，打开第一个灯泡 [1,0,0]
第二天 bulbs[1] = 3，打开第三个灯泡 [1,0,1]
第三天 bulbs[2] = 2，打开第二个灯泡 [1,1,1]
返回2，因为在第二天，两个打开的灯泡之间恰好有一个关闭的灯泡。

示例 2：

输入：bulbs = [1,2,3]，k = 1
输出：-1 

提示：

n == bulbs.length
1 <= n <= 2 * 104
1 <= bulbs[i] <= n
bulbs 是一个由从 1 到 n 的数字构成的排列
0 <= k <= 2 * 104

*/

class Solution100 {
public:
    // 2023.2.20, from https://walkccc.me/LeetCode/problems/0683/
    /*
        Time: O(n)
        Space: O(n)
    */
    int kEmptySlots(vector<int>& bulbs, int k) {
        const int n = bulbs.size();
        int ans = INT_MAX;
        // day[i] := the day when bulbs[i] is turned on
        vector<int> day(n);

        for (int i = 0; i < n; ++i)
        day[bulbs[i] - 1] = i + 1;

        // Find a subarray of day[l..r], where its length is k + 2
        // For all that l < i < r, day[i] > max(day[l], day[r])
        int l = 0;
        int r = l + k + 1;
        for (int i = 1; r < n; ++i)
        if (i == r) {
            ans = min(ans, max(day[l], day[r]));
            l = i;
            r = i + k + 1;
        } else if (day[i] < max(day[l], day[r])) {
            l = i;
            r = i + k + 1;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};


class Solution99 {
public:
    // 2023.2.20, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/k-empty-slots.cpp
    // Time:  O(n)
    // Space: O(n)
    int kEmptySlots(vector<int>& flowers, int k) {
        vector<int> days(flowers.size());
        for (int i = 0; i < flowers.size(); ++i) {
            days[flowers[i] - 1] = i;
        }
        auto result = numeric_limits<int>::max();
        for (int i = 0, left = 0, right = k + 1; right < days.size(); ++i) {
            if (days[i] < days[left] || days[i] <= days[right]) {   
                if (i == right) {
                    result = min(result, max(days[left], days[right])); 
                }
                left = i, right = k + 1 + i;
            }
        }
        return (result == numeric_limits<int>::max()) ? -1 : result + 1;
    }
};


class Solution98 {
public:
    // 2023.2.20, from https://github.com/wisdompeak/LeetCode/blob/master/Greedy/683.K-Empty-Slots/683.K-Empty-Slots.cpp
    /*
        683.K-Empty-Slots
        此题可以用set的迭代器来做，每插入一个元素，只要在这个有序容器里找到前面和后面一个元素，看看之间是否相差ｋ即可．

        更巧妙的o(n)解法是一个贪心策略．

        我们将题目的条件转换成另一个数组days[i]，表示位置ｉ的花在days[i]这一天开放．那么我们希望得到什么呢？我们希望有这么
        一个宽度为k+1的区间[left,right],对于任意left<i<right，都有days[i]>days[left] && days[i]>days[right]．这说明这
        个区间内部的花都比两边的要晚开．等到left或right其中较晚的一个开放时，他们正好就是一对间隔Ｋ个ｐａｉｒ．

        那么如何找到这样一个窗口呢？我们尝试让它滑动起来．令left=0,right=left+k+1,然后逐个考察其中的ｉ是否符合条件．如果遇到
        不符合条件的，说明days[i]要比两边的都要早，成为了一个＂钉子户＂,所有小于i的left都不可能符合要求了．那么显然，我们的策略
        就是让这个钉子户作为新的left，进行下一次的搜索．

        注意,一旦找到一个合适的区间,那么输出的答案应该是max(days[left],days[right]),因为只有两边的花都开了,这个区间才成立.    
    */
    int kEmptySlots(vector<int> &flowers, int k) 
    {
        int N = flowers.size();
        vector<int>days(N);
        for (int i=0; i<N; i++)
            days[flowers[i]-1] = i;
        
        int result = INT_MAX;
        int candidate;
        for (int i=0; i<N; i++)
        {
            int left = i;
            int right = left+k+1;
            if (right>=N) break;
            
            bool flag = 1;
            for (int j=left+1; j<=right-1; j++)
            {
                if (days[j]<days[left] || days[j]<days[right])
                {
                    flag = 0;
                    i = j-1;
                    break;
                }
            }
            if (flag) 
            {
                candidate = max(days[left],days[right])+1;
                result = min(result,candidate);
            }
        }
        if (result==INT_MAX)
            return -1;
        else
            return result;
    }
};


class Solution97 {
public:
    // 2023.2.20, from https://zxi.mytechroad.com/blog/?s=LeetCode+683.
    // Author: Huahua
    // Runtime: 228 ms
    int kEmptySlots(vector<int>& flowers, int k) {
        int n = flowers.size();
        if (n == 0 || k >= n) return -1;        
        set<int> xs;        
        for (int i = 0; i < n; ++i) {
            int x = flowers[i];
            auto r = xs.insert(x).first;
            auto l = r;
            if (++r != xs.end() && *r == x + k + 1) return i + 1;
            if (l != xs.begin() && *(--l) == x - k - 1) return i + 1;
        }
        
        return -1;
    }
};


class Solution96 {
public:
    // 2023.2.20, from https://zxi.mytechroad.com/blog/?s=LeetCode+683.
    // Author: Huahua
    // Runtime: 196 ms (better than 94%)
    int kEmptySlots(vector<int>& flowers, int k) {
        int n = flowers.size();
        if (n == 0 || k >= n) return -1;
        ++k;
        int bs = (n + k - 1) / k;
        vector<int> lows(bs, INT_MAX);
        vector<int> highs(bs, INT_MIN);
        for (int i = 0; i < n; ++i) {
            int x = flowers[i];
            int p = x / k;
            if (x < lows[p]) {
                lows[p] = x;
                if (p > 0 && highs[p - 1] == x - k) return i + 1;
            } 
            if (x > highs[p]) {
                highs[p] = x;
                if (p < bs - 1 && lows[p + 1] == x + k) return i + 1;
            }            
        }
        
        return -1;
    }
};


class Solution {
public:
    // 作者：xzp
    // 链接：https://leetcode.cn/leetbook/read/sliding-window-and-two-pointers/ruaaes/?discussion=VhWUl6
    // 来源：力扣（LeetCode）
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    int kEmptySlots(vector<int>& bulbs, int k) {
        int n = bulbs.size();
        set<int> rec;
        for(int i = 0 ; i < n ; i++) {
            int x = bulbs[i];
            rec.insert(x);
            auto it = rec.lower_bound(x);
            if(it != rec.end()){
                int x_next = *(++it);
                if(x_next - x == k + 1) return i + 1;
            }
            it--;
            if(it != rec.begin()){
                int x_prev = *(--it);
                if(x - x_prev == k + 1) return i + 1;
            }
        }
        return -1;
    }
};
