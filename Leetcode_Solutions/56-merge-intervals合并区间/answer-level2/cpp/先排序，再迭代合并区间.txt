
### 解析思路

先对intervals升序排序，再迭代合并区间。

开始时，先把`intervals[0]`设置为上一个区间命名为`pre`。
1. 当前待考察的区间`intervals[i]`命名为`cur`. 
2. 如果`cur`的左边界比`pre`的右边界还要大，说明`pre`是一个独立的区间，不需要再合并了。 
3. 如果`cur`的左边界小于等于`pre`的右边界，那么合并区间，`pre`的右边界取两者的大值。
4. 重复2、3步骤，继续考察下一个区间。


### 代码实现
```cpp []
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 特殊情况先处理
        if (intervals.size() <= 1) return intervals;
        
        // 先排序区间集合，默认使用vector的第一个元素排序
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ret;
        
        vector<int> pre = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            vector<int> cur = intervals[i];
            if (pre[1] < cur[0]) { // 独立区间
                ret.push_back(pre);
                pre = cur;
            } else { // 合并区间，右区间取大值
                pre[1] = max(pre[1], cur[1]);
            }
        }
        
        ret.push_back(pre);
        
        return ret;
    }
};
```


### 复杂度分析
- 时间复杂度：排序区间时间复杂度为O(nlogn), 遍历元素时间复杂度为O(n), 所以整体时间复杂度为O(nlogn).
- 空间复杂度：需要一个vector保存合并的结果，空间复杂度为O(n)
