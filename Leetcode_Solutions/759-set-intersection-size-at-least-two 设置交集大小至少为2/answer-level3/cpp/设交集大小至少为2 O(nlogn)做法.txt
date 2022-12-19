首先，我们可以去掉给定的一部分区间：如果有两个区间，区间A为[a1, a2]，区间B为[b1, b2]，如果b1 >= a1且b2 <= a2，即区间B包含在区间A中，那么我们可以直接去掉区间A，因为如果我们最后给出的集合能够与B有两个交点，那么一定就和A至少有两个交点，而约束的区间越少越好。
收集处理后的区间，对它们按照左端点位置排序，排序后这些区间一定满足“早开始的早结束”。我们维护一个集合记录所有需要的数，然后按照顺序依次考虑这些区间。对于第i个区间，我们根据前i-1个区间中得到集合中的数与它有多少个交点（集合中数要求从小到大，而且只要看集合中最后两个数和区间i是否相交即可），分为3种情况：
（1）集合中数与区间i至少有2个交点。此时不进行任何操作；
（2）集合中数与区间i有1个交点。此时把区间i的右端点加入到集合中；
（3）集合中数与区间i没有交点。此时把区间i+1到区间n中，左端点小于等于区间i的右端点的最后一个区间的左端点加入到集合中，然后再把区间i的右端点加入到集合中；

为什么这么做是对的？需要观察到两件事：
（1）我们集合中取的数只需要考虑区间端点（显然）
（2）当我们依次满足集合中的每一个区间i的时候，我们选择的端点要尽可能的“靠后”，这样这个端点有更大的可能覆盖到第i+1到第n个区间

排序过程的时间复杂度是O(nlogn)，其他部分的时间复杂度是O(n)

```
class Solution {
public:
    static bool cmp(const vector<int>& a,const vector<int>& b) {
        if(a[0] < b[0]) return true;
        else if(a[0] == b[0]) return a[1] > b[1];
        else return false;
    }

    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        if(intervals.size() == 0)
            return 0;
        int ans = 0;
        vector<int> s;
        vector<vector<int> >temp;
        sort(intervals.begin(), intervals.end(), cmp);
        temp.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++) {
            while(temp.size() > 0 && intervals[i][1] <= temp[temp.size() - 1][1])
                temp.pop_back();
            temp.push_back(intervals[i]);
        }
        int cur = 0, tot = temp.size();
        for(int i = 0; i < tot; i++){
            int start_pos = temp[i][0], end_pos = temp[i][1], last = -1, remain = 2, sz = s.size();
            if(sz >= 1 && s[sz - 1] >= start_pos && s[sz - 1] <= end_pos)
                --remain;
            if(sz > 1 && s[sz - 2] >= start_pos && s[sz - 2] <= end_pos)
                --remain;
            if(remain == 0)
                continue;
            else if(remain == 1){
                s.push_back(end_pos);
                ++ans;
            }
            else{
                for(;cur < tot && temp[cur][0] < start_pos; ++cur);
                for(;cur < tot && temp[cur][0] < end_pos; ++cur){
                    last = temp[cur][0];
                }
                if(last == -1){
                    s.push_back(start_pos);
                    ++ans;
                }
                else{
                    s.push_back(last);
                    ++ans;
                }
                s.push_back(end_pos);
                ++ans;
            }
        }
        return ans;
    }
};
```

