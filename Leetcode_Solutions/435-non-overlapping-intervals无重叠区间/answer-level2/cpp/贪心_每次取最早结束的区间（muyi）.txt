
### 解题思路

贪心算法 -- 区间调度

每次都取结束最早的区间

结束最早，剩下部分的空间最大，可以容纳最多的区间数目

### 代码

```cpp
int cmp(vector<int> &n1, vector<int> &n2){
        return n1[1] < n2[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int ans = 0;
        int end = intervals[0][1]; 
        for (int i = 1; i< intervals.size(); i++){
            if (intervals[i][0] < end) {
                ans++;
            } else {
                end = intervals[i][1];
            }
        }
        return ans;
    }
};
```

[更多题解...](https://github.com/muyids/leetcode)