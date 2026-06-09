首先排序，然后相邻的必然i[0]<=j[0],设i=[a,b], j=[c,d]，如果c在[a,b]中，则可以合并；否则不可以合并。
```
class Solution {
    static bool less(const vector<int> &a, const vector<int> &b){
        if(a[0]!=b[0]) return a[0]<b[0];
        else return a[1]<b[1];
    }
public:
    vector<vector<int> > merge(vector<vector<int> > &intervals) {
        if(intervals.size()==0) return intervals;
        sort(intervals.begin(),intervals.end(),less);
        vector<vector<int> > vs(1,intervals[0]);
        for(int i=1; i<intervals.size(); ++i){
            auto &a=vs.back(), &b=intervals[i];
            if(a[1]>=b[0]) a[1]=max(a[1],b[1]);
            else vs.push_back(b);
        }
        return vs;
    }
};
```