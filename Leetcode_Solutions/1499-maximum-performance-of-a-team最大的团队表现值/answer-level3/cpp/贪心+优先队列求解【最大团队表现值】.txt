### 解题思路
首先看清题目，不一定是k个人。只有不大于k个就🆗
具体的解题思路：
根据效率从小到大进行排序。
然后遍历效率。当efficiency[i]作为最低的效率时，在左侧选取最多k个最大的速度。
用优先队列存放左侧的速度，一旦队列大小超过k，则将最小的速度移除队列。
### 代码

```cpp
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        const int mod = 1000000007;
        vector<vector<int> >es;
        for(int i=0;i<efficiency.size();i++){
            es.push_back({efficiency[i],speed[i]});
        }
        sort(es.rbegin(),es.rend());

        long long ans = 0;
        long long sum = 0;
        long long eff = INT_MAX;
        priority_queue<int, vector<int>,greater<int>> que;//优先队列，升序
        for(int i=0;i<es.size();i++){
            eff = es[i][0];  
            que.push(es[i][1]);//速度入队列
            sum += es[i][1];
            if(que.size()>k){//最多只能放k个元素
                sum -= que.top(); 
                que.pop();
            }
            ans = max(ans,sum*eff);
        }
        return ans%mod;
    }
};
```