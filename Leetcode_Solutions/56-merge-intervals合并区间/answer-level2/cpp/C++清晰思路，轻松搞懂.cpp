### 解题思路
![image.png](https://pic.leetcode-cn.com/2c5650107a6e6575484abdaf3b5e9605d929f0c5b12b695f88529ebb54aa9640-image.png)
1. 对intervals二维数组的第一个列数进行整体排序；
2. 对第一个区间存入tmp中；
3. 每次tmp的第二个值与第i个区间的第一个值比较，若第一个大于或等于，则属于重叠区间，反之则中断连续，tmp存入res并且重定位于下一个区间

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.empty() || intervals[0].empty()) return res;
        vector<int> tmp;
        sort(intervals.begin(), intervals.end());
        tmp.push_back(intervals[0][0]);
        tmp.push_back(intervals[0][1]);
        for(int i = 1; i < intervals.size(); i++){
            if(tmp[1] >= intervals[i][0]){
                tmp[0] = min(tmp[0], intervals[i][0]);
                tmp[1] = max(tmp[1], intervals[i][1]);
            }else{
                res.push_back(tmp);
                tmp[0] = intervals[i][0];
                tmp[1] = intervals[i][1];
            }
        }
        res.push_back(tmp);
        return res;
    }
};
```