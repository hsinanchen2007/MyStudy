快排partition思想，quickselect稍微改动一下就行。
期望时间复杂度O(n)，算法导论9.2有证明。
```
class Solution {
public:
    int partition(vector<pair<int,int>> &a,int l, int r){
        swap(a[l],a[l+rand()%(r-l+1)]); //随机化
        int j=l,pivot=a[l].second;
        for(int i=l+1;i<=r;i++)
            if(a[i].second>pivot)     //大的放前，小的放后
                swap(a[i],a[++j]);
        swap(a[l],a[j]);
        return j;
    }
    void select(vector<pair<int,int>> &a,int l,int r,int k){
        if(r==l) return ;
        int j=partition(a,l,r);
        int k1=k-1;
        if(k1==j) return ;
        else if(k1<j) select(a,l,j-1,k);
        else select(a,j+1,r,k);
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> ma;
        for(int i:nums)
            ma[i]++;
        vector<pair<int,int>> ve(ma.begin(),ma.end());
        vector<int> res;
        select(ve,0,ve.size()-1,k);
        for(int i=0;i<k;i++)
            res.push_back(ve[i].first);
        return res;
    }
};
```

