先吐槽一下题目并没有把intervals类写清楚...
=====================
1）根据区间的首位数字对所有区间进行升序排序。
>排序能够提供intervals中下一个区间的start值$\geq$上一个区间的start值
2）设置两个int对象，分别存放当前的区间start值和end值。
3）依次遍历对象，通过判断当前区间的尾end值与下一个区间start值的关系
- 当前区间end值$<$下一个区间的start值，此时区间已中断，可以将已经完成的区间存放进res中
- 当前区间的end值$\geq$下一个区间的start值，说明此时区间仍然延续，只需进一步判断当前区间的end值与下一个区间的end值的关系即可：
    - 如果当前区间的end值$\geq$下一个区间的end值，说明下一个区间被包含进来了，此时end值不需要更新；
    - 如果当前区间的end值$<$下一个区间的end值，说明这个区间仍然可以拓展，则将end值更新为下一个区间的end值

```c++
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());        
        vector<vector<int>> res;
        if(intervals.size()==0) return res;
        int start = intervals[0][0];
        int end = intervals[0][1];
        if(intervals.size()==1){
            vector<int> tmp = PushRes(start, end);
            res.push_back(tmp);
            return res;
        } 
        for(int i=1; i<intervals.size(); i++){
            
            if(end < intervals[i][0]){
                vector<int> tmp = PushRes(start, end);
                res.push_back(tmp);
                start = intervals[i][0];
                end = intervals[i][1];
                if(i==intervals.size()-1){
                    vector<int> tmp = PushRes(start, end);
                    res.push_back(tmp);
                }
            }else if(end >= intervals[i][0]){
                if(intervals[i][1]>end) end = intervals[i][1];
                if(i==intervals.size()-1){
                    vector<int> tmp = PushRes(start, end);
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }
    vector<int> PushRes(int start, int end){
        vector<int> tmp;
        tmp.push_back(start);
        tmp.push_back(end);
        return tmp;
    }
};
```
