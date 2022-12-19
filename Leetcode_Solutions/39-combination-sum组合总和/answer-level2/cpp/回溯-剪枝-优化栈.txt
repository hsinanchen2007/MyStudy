### 解题思路
回溯法 [@liweiwei1419](/u/liweiwei1419/) 已经讲得很清楚了，我是在他的基础上优化了一下栈，缩短了栈的调用深度；(4ms, beat 99%)
idea：对于枚举元素，直接在本层枚举它出现的次数，从 0 到 sum/a[i] 次，而非靠递归枚举

### 代码

```cpp
typedef vector<vector<int>> VII;
typedef vector<int> VI;

class Solution {
public:
    // enum all candidates, 0-s/x times
    //回溯法1，枚举每个元素，并枚举它的次数，向下传递 i+1 ，避免重复
    VII combinationSum(vector<int>& a, int s) {
        VII res;
        VI cur;
        sort(a.begin(), a.end());
        bt2(a, s, res, cur, 0);
        return res;
    }

    void bt2(VI& a, int s, VII& res, VI& cur, int start) {
        if (s == 0) {
            res.push_back(cur);
            return;
        }
        
        for (int i = start; i < a.size() && s - a[i] >= 0; ++i) {
            for (int j = 1; j <= s / a[i] && s - j * a[i] >= 0; ++j) {
                for (int k = 0; k < j; ++k) {
                    cur.push_back(a[i]);
                }
                bt(a, s - j * a[i], res, cur, i + 1);
                for (int k = 0; k < j; ++k) {
                    cur.pop_back();
                }
            }
        }
    }
};
```