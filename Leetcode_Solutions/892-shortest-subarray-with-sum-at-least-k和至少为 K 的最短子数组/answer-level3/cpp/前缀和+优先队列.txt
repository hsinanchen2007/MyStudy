### 解题思路
连续数组的和，可以使用前缀和的思想，然后利用优先队列，先找小的，瞬间爆炸。

### 代码

```cpp
class Solution {
public:
    struct node {
        long long preSum;
        int currentIndex;
        node (long long iP, int iC) {
            preSum = iP;
            currentIndex = iC;
        }
    };
    struct cmp {
        bool operator() (node a, node b) {
            return a.preSum > b.preSum;
        }
    };
    int shortestSubarray(vector<int>& A, int K) {
        vector<long long> preSum(1, 0);
        for (int i = 0; i < A.size(); i++) {
            preSum.push_back(preSum[i] + A[i]);
        }
        priority_queue<node, vector<node>, cmp> minQueue;
        int ans = 50001;
        for (int i = 0; i < preSum.size(); i++) {
            while(! minQueue.empty() && preSum[i] - minQueue.top().preSum >= K) {
                ans = min(i - minQueue.top().currentIndex, ans);
                minQueue.pop();
            }
            minQueue.push(node(preSum[i], i));
        }
        return ans == 50001 ? -1 : ans;
    }
};
```