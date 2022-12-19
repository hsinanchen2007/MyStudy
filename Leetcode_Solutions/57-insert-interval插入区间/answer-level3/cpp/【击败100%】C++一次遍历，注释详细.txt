遍历intervals中的每个区间，与newInterval没有交集时，直接插入；有交集时，记录合并区间起点start和终点end，继续遍历继续合并。在新的遍历区间不再满足合并条件时，把[start,end]作为合并后区间塞进去。
![image.png](https://pic.leetcode-cn.com/0af0e4951a46da9bc663bc0f6a2726a2588f8613b7adf04692b17be1492280f0-image.png)

```
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        size_t count = intervals.size();
        vector<vector<int>> res;
        res.reserve(count);
        bool pushed = false; //是否已处理过newInterval
        bool merging = false; //是否正在合并区间
        int start=0, end=0; //merging为true时，记录起点和终点
        
        for(int i=0; i<count; ++i) {
            if(!merging) { //当前未在合并区间，此分支需要检查是否满足合并区间条件
                if(intervals[i][1] < newInterval[0]) { //当前遍历的intervals[i]终点比newInterval的起点还小，直接插
                    res.push_back(intervals[i]);
                } else if (intervals[i][0] > newInterval[1]) { 
                    //当前遍历的intervals[i]起点比newInterval的终点还大，没有交集。
                    //若newInterval还没被合并过，那么需要先把newInterval插进去，然后再插当前遍历的vec；
                    //否则，直接插interval[i]
                    if(pushed) {
                        res.push_back(intervals[i]); 
                    } else {
                        res.push_back(newInterval);
                        res.push_back(intervals[i]);
                        pushed = true;
                    }
                } else { //不满足上面两个分支的话，说明当前的intervals[i]与newInterval是有交集的
                    merging = true; //标记正在合并区间
                    pushed = true; //标记newInterval已被处理
                    start = std::min(intervals[i][0], newInterval[0]); //合并后的区间起点取两者最小
                    end = std::max(intervals[i][1], newInterval[1]); //合并后的区间终点取两者最大
                }
            } else { //merging
                //当前正在合并，需要判断当前遍历的newInterval[i]是否可以也合并进去
                if(intervals[i][0] <= end) { //也可以合并进去
                    end = std::max(end, intervals[i][1]);
                } else { 
                    //不可以合并了，那就把之前合并后的区间[start,end]塞进去吧，再把当前的intervals[i]塞进去
                    merging = false; //标记合并结束
                    res.push_back({start,end});
                    res.push_back(intervals[i]);
                }
            }
        }
    
        if(merging) { //合并可能持续到最后，还一直在合并，那就遍历结束后统一处理
            merging = false;
            res.push_back({start,end});
        }
        if(!pushed) { //遍历的区间全都小于newInterval，直接把它塞进去
            res.push_back(newInterval);
            pushed = true;
        }
        return res;
    }
};
```
