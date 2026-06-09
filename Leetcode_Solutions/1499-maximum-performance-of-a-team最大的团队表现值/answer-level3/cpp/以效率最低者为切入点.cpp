以效率最低者为切入点，计算所有效率比他大的前k个人的速度之和，比较效率最低为多少时团队表现最大，这个容易想到。
关键的优化点是计算k个人的速度之和，需要先以效率排序，再维护一个数组，纪录这k个速度，每次遍历一个效率时，可能更新数组中的一个值。
比较需要用到lamda函数，维护数组需要用到priority_queue.
学到了。
```
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        typedef  long long LL;
        typedef pair<LL,LL> PLL;
        vector<PLL> pr;
        for (int i = 0; i < n; ++ i){
            pr.emplace_back(speed[i], efficiency[i]);
        }
        sort(pr.begin(), pr.end(), [](const PLL& p1, const PLL& p2) -> bool{
            return p1.second > p2.second; 
        });
        LL result=0;
        LL part_max=0;
        LL mod=pow(10,9)+7;
        priority_queue<int,vector<int>,greater<int>> q;
        LL total=0;
        for(int i=0;i<n;++i){
            total+=pr[i].first;
            q.emplace(pr[i].first);
            if(q.size()>k){
                total-=q.top();
                q.pop();
            }
            part_max=total*pr[i].second;
            result=max(result,part_max);
        }
        return result%mod;
    }
};
```
