
### 贪心

#### 算法思路

- 将所有工人按效率从大到小排序
- 优先队列 S集合 维护K个工人组成组成的 表现最好的团队，优先队列按速度从小到大排序
- 枚举 所有工人
  - 当S集合元素数量小于K时，直接加入集合
  - 当S集合元素数量大于等于K时，比较当前工人和S集合堆顶的工人的速度大小
    - 如果当前工人较慢，直接pass
    - 如果当前工人较快，计算堆顶替换成当前工人，是否能够获得更好的表现

#### 时间复杂度

对所有工人排序 O(nlogn)

枚举每个工人，与堆顶比较 O(nlogK)

总体时间复杂度 O(nlogn)

#### C++ 代码

```cpp
bool cmp(vector<int> &n1, vector<int> &n2){
    return n1[1] > n2[1];
}

class Solution {
public:
    const int mod = 1e9 + 7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<vector<int>> workers;
        for (int i =0; i<n; i++){
            workers.push_back({speed[i], efficiency[i]});
        }
        sort(workers.begin(), workers.end(), cmp);

        long long sum = 0;
        long long ans = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto &w: workers){
            if (q.size() <k){
                q.push(w[0]);
                sum += w[0]; 
            } else {
                if (w[0] <= q.top()) continue;
                sum = sum - q.top() + w[0];
                q.pop();
                q.push(w[0]);
            }
            ans = max(ans, sum * w[1]);
        }
        return ans % mod;
    }
};
```

#### 同一类型题

- [LeetCode 857. Minimum Cost to Hire K Workers (hard)](https://github.com/muyids/leetcode/blob/master/algorithms/801-900/857.minimum-cost-to-hire-k-workers.md)

#### 阅读

[从头开始学算法](https://muyids.github.io/simple-algorithm/)