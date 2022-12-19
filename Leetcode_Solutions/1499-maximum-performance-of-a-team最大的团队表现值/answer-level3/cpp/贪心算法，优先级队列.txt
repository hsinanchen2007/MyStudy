1. 一定要在最后的返回结果再取模，否则就出错。
```c++
typedef pair<int,int> pii;

class Solution {
public:
    static bool cmp(pii & a,pii & b){
        if(a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    }
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        long long res = 0;
        long long mod = 1e9+7;
        vector<pii> p;
        
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i = 0; i < n; ++i){
            p.push_back(make_pair(efficiency[i],speed[i]));
        }
        sort(p.begin(),p.end(),cmp);
        long long sum = 0;
        for(int i = 0; i < n; ++i){
            if(pq.size() >= k && p[i].second <= pq.top()) continue;
            sum += p[i].second;
            pq.push(p[i].second);
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            res = max(res,(sum*p[i].first));
        }    
        
        return res%mod;
    }
};
```