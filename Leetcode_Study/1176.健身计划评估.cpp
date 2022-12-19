/*

https://leetcode.cn/problems/diet-plan-performance/

1176. 健身计划评估
你的好友是一位健身爱好者。前段日子，他给自己制定了一份健身计划。现在想请你帮他评估一下这份计划是否合理。

他会有一份计划消耗的卡路里表，其中 calories[i] 给出了你的这位好友在第 i 天需要消耗的卡路里总量。

为了更好地评估这份计划，对于卡路里表中的每一天，你都需要计算他 「这一天以及之后的连续几天」 （共 k 天）内消耗的总卡路里 T：

如果 T < lower，那么这份计划相对糟糕，并失去 1 分； 
如果 T > upper，那么这份计划相对优秀，并获得 1 分；
否则，这份计划普普通通，分值不做变动。
请返回统计完所有 calories.length 天后得到的总分作为评估结果。

注意：总分可能是负数。
 

示例 1：

输入：calories = [1,2,3,4,5], k = 1, lower = 3, upper = 3
输出：0
解释：calories[0], calories[1] < lower 而 calories[3], calories[4] > upper, 总分 = 0.

示例 2：

输入：calories = [3,2], k = 2, lower = 0, upper = 1
输出：1
解释：calories[0] + calories[1] > upper, 总分 = 1.

示例 3：

输入：calories = [6,5,0,0], k = 2, lower = 1, upper = 5
输出：0
解释：calories[0] + calories[1] > upper, calories[2] + calories[3] < lower, 总分 = 0.
 

提示：

1 <= k <= calories.length <= 10^5
0 <= calories[i] <= 20000
0 <= lower <= upper
通过次数5,419提交次数11,390

*/

// Time:  O(n)
// Space: O(1)

class Solution100 {
public:
    // 2022.8.19, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/diet-plan-performance.cpp
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int total = accumulate(calories.cbegin(), calories.cbegin() + k, 0);
        int result = int(total > upper) - int(total < lower);
        for (int i = k; i < calories.size(); ++i) {
            total += calories[i] - calories[i - k];
            result += int(total > upper) - int(total < lower);
        }
        return result;
    }
};


class Solution99 {
public:
    // 2022.8.19, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/1176.%20Diet%20Plan%20Performance
    // OJ: https://leetcode.com/problems/diet-plan-performance/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    int dietPlanPerformance(vector<int>& A, int k, int lower, int upper) {
        int N = A.size(), ans = 0, sum = 0;
        for (int i = 0; i < N; ++i) {
            sum += A[i];
            if (i - k >= 0) sum -= A[i - k];
            if (i >= k - 1) {
                if (sum < lower) --ans;
                else if (sum > upper) ++ans;
            }
        }
        return ans;
    }
};


class Solution98 {
public:
    // 2022.8.19, from https://github.com/liuyubobobo/Play-Leetcode/blob/master/1001-1500/1176-Diet-Plan-Performance/cpp-1176/main.cpp
    // Sliding Window
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {

        int n = calories.size();
        int res = 0;
        int cur = accumulate(calories.begin(), calories.begin() + (k - 1), 0);
        for(int i = k - 1; i < n; i ++){
            cur += calories[i];
            if(cur < lower) res --;
            else if(cur > upper) res ++;
            cur -= calories[i - (k - 1)];
        }
        return res;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/



