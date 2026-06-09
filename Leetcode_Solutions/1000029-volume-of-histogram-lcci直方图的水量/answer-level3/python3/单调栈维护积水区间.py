### 思路

为何会产生积水量？因为出现了某一段直方图中间低两边高。如果我们可以统计所有中间低两边高的情况，那么答案就自然的求出了。

维护一个严格单调递减的单调栈，当要将栈顶元素弹出的时候，此时即将进入单调栈的元素与单调栈倒数第二个元素 是两边高，即将出栈的元素是中间低，每当出现这样的情况，我们将这一段产生的积水统计进入答案即可。

这个方法有一个好处：在处理某个元素的时候，无须知道后面的信息，那么可以看作一个能运行在流式数据上的算法。但是未必能做到实时，存储空间与每一时刻的运行时间均有可能与数据流长度相关。

时间复杂度：$O(n)$

```cpp []
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> S; 
        int ans = 0, n = height.size();
        
        for (int i = 0; i < n; i++){
            int h = height[i];
            while(!S.empty() && height[S.top()] <= h){
                int last = height[S.top()]; S.pop();
                if (!S.empty()) ans += (i - S.top() - 1) * (min(h, height[S.top()]) - last);
            }
            S.push(i);
        }

        return ans;
    }
};
```
```python3 []
class Solution:
    def trap(self, height: List[int]) -> int:
        S, ans, n = [], 0, len(height)
        
        for i in range(n):
            h = height[i]
            while len(S) > 0 and S[-1][0] <= h:
                cur = S.pop()
                if len(S) > 0:
                    ans += (i - S[-1][1] - 1) * (min(S[-1][0], h) - cur[0])
            S.append((h, i))

        return ans
```
