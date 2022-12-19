### 解题思路

简单的思路：先将区间排序，再依次比较
因为排序好的，比较条件只需要看上个区间的右边界right1是否和下个区间的左边界有无交集即可
1，没有交集，更新上个区间的左，右边界，将新的结果放到结果数组中去，继续和下个区间比较即可
2，有交集，不停更新右边界，同时不断刷新对应的结果值即可

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.size() <= 0) {
            return res;
        }
        if (intervals.size() == 1) {
            res.push_back({intervals[0][0], intervals[0][1]});
            return res;
        }
        sort(intervals.begin(), intervals.end(), [](const vector<int>& var1, const vector<int>& var2) {
            if (var1[0] < var2[0]) {
                return true;
            } else {
                return false;
            }
        });
        int left1 = intervals[0][0];
        int right1 = intervals[0][1];
        int resIndex = 0;      
        res.push_back({left1, right1});  
        for (int i = 1; i < intervals.size(); i++) {            
            int left2 = intervals[i][0];
            int right2 = intervals[i][1];
            // printf("(%d, %d) vs (%d, %d)\n", left1, right1, left2, right2);
            if (right1 < left2) {
                // 无交集的情况
                resIndex ++;
                left1 = left2;
                right1 = right2;
                res.insert(res.begin()+resIndex, {left1, right1}); 
            } else {
                // 有交集的情况
                right1 = max(right1, right2);
            }
            // printf("update to (%d, %d), resIndex=%d\n", left1, right1, resIndex);
            res[resIndex] = {left1, right1};
        }
        return res;
    }
};
```