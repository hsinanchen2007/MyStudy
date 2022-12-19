/*
 * @lc app=leetcode.cn id=475 lang=cpp
 *
 * [475] 供暖器
 */

/*

https://leetcode.cn/problems/reverse-string-ii/

475. 供暖器
冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。

在加热器的加热半径范围内的每个房屋都可以获得供暖。

现在，给出位于一条水平线上的房屋 houses 和供暖器 heaters 的位置，请你找出并返回可以覆盖所有房屋的最小加热半径。

说明：所有供暖器都遵循你的半径标准，加热的半径也一样。


示例 1:

输入: houses = [1,2,3], heaters = [2]
输出: 1
解释: 仅在位置2上有一个供暖器。如果我们将加热半径设为1，那么所有房屋就都能得到供暖。

示例 2:

输入: houses = [1,2,3,4], heaters = [1,4]
输出: 1
解释: 在位置1, 4上有两个供暖器。我们需要将加热半径设为1，这样所有房屋就都能得到供暖。

示例 3：

输入：houses = [1,5], heaters = [2]
输出：3
 

提示：

1 <= houses.length, heaters.length <= 3 * 104
1 <= houses[i], heaters[i] <= 109
通过次数61,617提交次数151,114

*/

// @lc code=start
class Solution100 {
public:
    // 2022.7.30, from https://github.com/lzl124631x/LeetCode/blob/master/leetcode/475.%20Heaters/s1.cpp
    // OJ: https://leetcode.com/problems/heaters
    // Author: github.com/lzl124631x
    // Time: O(NlogN)
    // Space: O(1)
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int j = 0, ans = INT_MIN;
        for (int h : houses) {
            while (j < heaters.size() && heaters[j] < h) ++j;
            int d = INT_MAX;
            if (j - 1 >= 0) d = min(d, abs(heaters[j - 1] - h));
            if (j < heaters.size()) d = min(d, abs(heaters[j] - h));
            ans = max(ans, d);
        }
        return ans;
    }
};


class Solution99 {
public:
    // 2022.7.30, from https://github.com/lzl124631x/LeetCode/blob/master/leetcode/475.%20Heaters/s2.cpp
    // OJ: https://leetcode.com/problems/heaters
    // Author: github.com/lzl124631x
    // Time: O(NlogN)
    // Space: O(1)
    // Ref: https://discuss.leetcode.com/topic/71450/simple-java-solution-with-2-pointers
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int i = 0, ans = 0;
        for (int h : houses) {
            while (i < heaters.size() - 1 && heaters[i] + heaters[i + 1] <= h * 2) ++i;
            ans = max(ans, abs(heaters[i] - h));
        }
        return ans;
    }
};


class Solution98 {
public:
    // 2022.7.30, from https://github.com/lzl124631x/LeetCode/blob/master/leetcode/475.%20Heaters/s3.cpp
    // OJ: https://leetcode.com/problems/heaters
    // Author: github.com/lzl124631x
    // Time: O(NlogN)
    // Space: O(1)
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int ans = 0;
        for (int h : houses) {
            int L = 0, R = heaters.size() - 1;
            while (L <= R) {
                int M = (L + R) / 2;
                if (heaters[M] >= h) R = M - 1;
                else L = M + 1;
            }
            int d = INT_MAX;
            if (L < heaters.size()) d = min(d, heaters[L] - h);
            if (R >= 0) d = min(d, h - heaters[R]);
            ans = max(ans, d);
        }
        return ans;
    }
};


class Solution97 {
public:
    // 2022.7.30, from https://github.com/lzl124631x/LeetCode/blob/master/leetcode/475.%20Heaters/s4.cpp
    // OJ: https://leetcode.com/problems/heaters
    // Author: github.com/lzl124631x
    // Time: O(NlogN)
    // Space: O(1)
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int ans = 0;
        for (int h : houses) {
            auto i = lower_bound(heaters.begin(), heaters.end(), h);
            int d = INT_MAX;
            if (i != heaters.end()) d = min(d, *i - h);
            if (i != heaters.begin()) d = min(d, h - *(i - 1));
            ans = max(ans, d);
        }
        return ans;
    }
};


class Solution96 {
public:
    // 2022.7.30, from https://walkccc.me/LeetCode/problems/0475/
    // Time: max(O(mlogm),O(nlogn)), where m=houses and n = heaters
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(begin(houses), end(houses));
        sort(begin(heaters), end(heaters));

        int ans = 0;
        int i = 0;  // point to the heater that currently used

        for (const int house : houses) {
            while (i + 1 < heaters.size() &&
                    house - heaters[i] > heaters[i + 1] - house)
                ++i;  // next heater is better
            ans = max(ans, abs(heaters[i] - house));
        }

        return ans;
  }
};


class Solution95 {
public:
    // 2022.7.30, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/heaters.cpp
    // Time:  O((m + n) * logn), m is the number of the houses, n is the number of the heaters.
    // Space: O(1)
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int min_radius = 0;
        for (const auto& house : houses) {
        	auto equal_or_larger = lower_bound(heaters.cbegin(), heaters.cend(), house);
        	auto curr_radius = numeric_limits<int>::max();
        	if (equal_or_larger != heaters.cend()) {
        	    curr_radius = *equal_or_larger - house;
        	}
        	if (equal_or_larger != heaters.cbegin()) {
        	    auto smaller = prev(equal_or_larger);
        	    curr_radius = min(curr_radius, house - *smaller);
        	}
        	min_radius = max(min_radius, curr_radius);
        }
        return min_radius;
    }
};


class Solution94 {
public:
    // 2022.7.30, from https://www.acwing.com/activity/content/code/content/561362/
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/561362/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    bool check(int mid, vector<int>& houses, vector<int>& heaters) {
        for (int i = 0, j = 0; i < houses.size(); i ++ ) {
            while (j < heaters.size() && abs(heaters[j] - houses[i]) > mid)
                j ++ ;
            if (j >= heaters.size()) return false;
        }
        return true;
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int l = 0, r = INT_MAX;
        while (l < r) {
            int mid = (long long)l + r >> 1;
            if (check(mid, houses, heaters)) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};


class Solution93 {
public:
    // 2022.7.30, from https://github.com/grandyang/leetcode/issues/475
    /*
        这道题是一道蛮有意思的题目，首先我们看题目中的例子，不管是houses还是heaters数组都是有序的，
        所以我们也需要给输入的这两个数组先排序，以免其为乱序。我们就拿第二个例子来分析，我们的目标是
        houses中的每一个数字都要被cover到，那么我们就遍历houses数组，对每一个数组的数字，我们在
        heaters中找能包含这个数字的左右范围，然后看离左右两边谁近取谁的值，如果某个house位置比
        heaters中最小的数字还小，那么肯定要用最小的heater去cover，反之如果比最大的数字还大，就用
        最大的数字去cover。对于每个数字算出的半径，我们要取其中最大的值。通过上面的分析，我们就不难
        写出代码了，我们在heater中两个数一组进行检查，如果后面一个数和当前house位置差的绝对值小于
        等于前面一个数和当前house位置差的绝对值，那么我们继续遍历下一个位置的数。跳出循环的条件是遍历
        到heater中最后一个数，或者上面的小于等于不成立，此时heater中的值和当前house位置的差的绝对
        值就是能cover当前house的最小半径，我们更新结果res即可，参见代码如下：

        解法一：
    */
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n = heaters.size(), j = 0, res = 0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        for (int i = 0; i < houses.size(); ++i) {
            int cur = houses[i];
            while (j < n - 1 && abs(heaters[j + 1] - cur) <= abs(heaters[j] - cur)) {
                ++j;
            }
            res = max(res, abs(heaters[j] - cur));
        }
        return res;
    }
};


class Solution92 {
public:
    // 2022.7.30, from https://github.com/grandyang/leetcode/issues/475
    /*
        还是上面的思路，我们可以用二分查找法来快速找到第一个大于等于当前house位置的数，如果这个数存在，
        那么我们可以算出其和house的差值，并且如果这个数不是heater的首数字，我们可以算出house和前面一个
        数的差值，这两个数中取较小的为cover当前house的最小半径，然后我们每次更新结果res即可，参见代码如下：

        解法二：
    */
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int res = 0, n = heaters.size();
        sort(heaters.begin(), heaters.end());
        for (int house : houses) {
            int left = 0, right = n;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (heaters[mid] < house) left = mid + 1;
                else right = mid;
            }
            int dist1 = (right == n) ? INT_MAX : heaters[right] - house;
            int dist2 = (right == 0) ? INT_MAX : house - heaters[right - 1];
            res = max(res, min(dist1, dist2));
        }
        return res;
    }
};


class Solution {
public:
    // 2022.7.30, from https://github.com/grandyang/leetcode/issues/475
    /*
        我们可以用STL中的lower_bound来代替二分查找的代码来快速找到第一个大于等于目标值的位置，
        其余部分均和上面方法相同，参见代码如下：

        解法三：
    */
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int res = 0;
        sort(heaters.begin(), heaters.end());
        for (int house : houses) {
            auto pos = lower_bound(heaters.begin(), heaters.end(), house);
            int dist1 = (pos == heaters.end()) ? INT_MAX : *pos - house;
            int dist2 = (pos == heaters.begin()) ? INT_MAX : house - *(--pos);
            res = max(res, min(dist1, dist2));
        }
        return res;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// 2022.8.15, not in top list

// @lc code=end

