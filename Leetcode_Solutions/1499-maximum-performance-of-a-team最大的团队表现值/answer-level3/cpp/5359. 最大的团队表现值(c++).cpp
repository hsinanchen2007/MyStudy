### 解题思路
参考了前几名大佬的答案，解释下代码几个地方，也算是做个笔记吧。
1. vector中方的是pair对，sort排序默认对第一项，也就是efficiency数组按升序排序，若efficiency相同，则按speed升序排序。
2. 优先队列存储的是speed，根据团队表现值定义，我们要使速度和最大，因此定义为按升序排序，可以让队首speed小的人出队，最后heap这个名称时因为priority_queue底层时用堆实现的。
3. for循环中思路：从后往前遍历，遍历到第i个人时，他的efficiency就是团队最小值，在efficiency确定后，我们要保持有限队列中speed的和尽量大，遍历到下一个人且人数大于k时，将speed最小的出队，在这个过程中不断记录更新最大团队表现值即可。
### 代码

```cpp
using PII = pair<int,int>;  
using LL = long long;
const int M = 1e9 + 7;

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<PII> v;
        for(int i = 0; i < n; ++i) v.emplace_back(make_pair(efficiency[i], speed[i]));
        sort(v.begin(), v.end());

        priority_queue<int, vector<int>, greater<int>> heap;
        LL sum = 0, ans = 0;
        for(int i = n-1; i >= 0; --i){
            heap.push(v[i].second);
            sum += v[i].second;
            if(heap.size() > k){
                sum -= heap.top();
                heap.pop();
            }
            ans = max(ans, sum * v[i].first);
        }
        return ans % M;
    }
};
```