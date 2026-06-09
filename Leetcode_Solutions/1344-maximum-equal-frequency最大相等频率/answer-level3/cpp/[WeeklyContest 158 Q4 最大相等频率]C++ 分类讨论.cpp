[[WeeklyContest 158 Q1 分割平衡字符串]C++](https://leetcode-cn.com/problems/split-a-string-in-balanced-strings/solution/weeklycontest-158-q1-fen-ge-ping-heng-zi-fu-chuan-/)
[[WeeklyContest 158 Q2 可以攻击国王的皇后]C++ 迭代](https://leetcode-cn.com/problems/queens-that-can-attack-the-king/solution/weeklycontest-158-q2-ke-yi-gong-ji-guo-wang-de-hua/)
[[WeeklyContest 158 Q3 掷骰子模拟]C++ 动态规划](https://leetcode-cn.com/problems/dice-roll-simulation/solution/weeklycontest-158-q3-zhi-tou-zi-mo-ni-c-dong-tai-g/)
[[WeeklyContest 158 Q4 最大相等频率]C++ 分类讨论](https://leetcode-cn.com/problems/maximum-equal-frequency/solution/weeklycontest-158-q4-zui-da-xiang-deng-pin-lu-c-fe/)

```
事后总结：这种题目需要分类讨论，找出所有满足答案得情况再动手。直接分析写代码导致遇到特殊情况乱改代码。

问题分析：
能够满足答案的条件:
1、只有一种数字。如：1 1 1 1 1 
2、有多种数字，但每个数组只出现一次。 如：1 2 3 4 5
3、有多种数字，其中一种数字出现n+1次，其他出现n次。如：1 1 1 2 2 3 3 4 4
4、有多种数字，其中一种数字出现1次，其他出现n次。如：1 2 2 2 3 3 3 4 4 4
两个数组，arr_a 和 arr_b, arr_a[i]表示数字i出现次数，arr_b[i]表示出现频率为i的数字个数。
因此，成立条件为，arr_b[1]==n || 最高频次==1
                || (arr_b[最高频次]==1 && arr_b[最高频次-1]==(n-1))
                || (arr_b[最高频次]==(n-1) && arr_b[1]==1)
由此，又需要维护两个变量，n: 一共有多少种数字，ma: 最高频次为多少
```


```
class Solution {
    int arr_a[100005], arr_b[100005];
public:
    int maxEqualFreq(vector<int>& nums) {
        int n = 0, ma = 0, ans = 0;
        memset(arr_a, 0, sizeof(arr_a));
        memset(arr_b, 0, sizeof(arr_b));
        for(int i = 0; i < nums.size(); i++){
            int cur = nums[i];
            if(arr_a[cur]==0) n++;
            arr_a[cur]++;
            ma = max(ma, arr_a[cur]);
            arr_b[arr_a[cur]]++;
            if(arr_a[cur]>1) arr_b[arr_a[cur]-1]--;

            if(ma==1 || arr_b[1]==n || (arr_b[ma]==1 && arr_b[ma-1]==(n-1))|| (arr_b[ma]==(n-1) && arr_b[1]==1)){
                ans = i+1;
            }
        }
        return ans;
    }
};
```