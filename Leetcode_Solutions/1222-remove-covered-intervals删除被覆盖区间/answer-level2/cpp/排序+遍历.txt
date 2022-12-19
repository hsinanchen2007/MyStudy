先排序，当左端点相等时右端点大的排在前面，当左端点不相等时左端点小的排在前面，保证前一个区间一定不会包含在后一个区间中。然后遍历比较是否后一个区间包含在前面的区间即可。
```
class Solution {
public:
    static const int maxn=1e3+5;
    struct node{
        int l,r;
        node(){}
        node(int _l,int _r){
            l=_l,r=_r;
        }
    }a[maxn],b[maxn];
    static bool cmp(node a,node b){
        if(a.l==b.l) return a.r>b.r;
        else return a.l<b.l;
    }
    void init(vector<vector<int>>& intervals){
        for(int i=0;i<intervals.size();i++){
            a[i]=node(intervals[i][0],intervals[i][1]);
        }
        int n=intervals.size();
        sort(a,a+n,cmp);
    }
    bool check(node x,int n){
        for(int i=0;i<n;i++){
            int l=b[i].l,r=b[i].r;
            if(x.l>=l&&x.r<=r) return true;
        }
        return false;
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        init(intervals);
        int n=intervals.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(i==0) b[i]=a[i],ans++;
            else{
                if(check(a[i],ans)) continue;
                else b[ans++]=a[i];
            }
        }
        return ans;
    }
};
```
