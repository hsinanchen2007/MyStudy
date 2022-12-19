### 解题思路
策略很简单 遍历每一个效率的值 然后把比当前效率值高的人员全部找出来，取其中最大的k-1个
通过排序加优先队列的方法可以得到不错的复杂度


欢迎大家关注我的leetcode仓库～
[我的题解](https://www.github.com/wfnuser/leetcode)
[我的github](https://www.github.com/wfnuser)
最近沉迷刷题 同时也在学习和实现lua，欢迎交流

### 代码

```cpp
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        if (n == 0) return 0;
        
        int mod = 1;
        for (int i = 1; i <= 9; i++) {
            mod *= 10;
        }
        mod += 7;
        
        if (n == 1) {
            long e = efficiency[0];
            long s = speed[0];
            return (e*s)%mod;
        }
        
        vector<pair<int, long>> eWithS;
        for (int i = 0; i < n; i++) {
            int e = efficiency[i];
            long s = speed[i];
            eWithS.push_back(make_pair(e, s));
        }
        
        sort(eWithS.begin(), eWithS.end());
        reverse(eWithS.begin(), eWithS.end());
        

        
        long ans = 0;
        
        priority_queue<long, vector<long>, greater<long>> pq;
        long sum = 0;
        
        
        for (int i = 0; i < k; i++) {
            sum += eWithS[i].second;
            ans = max(ans, eWithS[i].first * sum);
            pq.push(eWithS[i].second);
        }
        
        for (int i = k; i < n; i++) {
            int rm = pq.top();
            pq.pop();
            pq.push(eWithS[i].second);
            sum -= rm;
            sum += eWithS[i].second;
            ans = max(ans, sum*eWithS[i].first);
        }
        
        return ans%mod;
    }
};
```