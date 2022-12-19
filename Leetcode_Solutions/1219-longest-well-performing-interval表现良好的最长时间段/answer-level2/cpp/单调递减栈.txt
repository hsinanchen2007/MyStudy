### 解题思路
首先将数组转换成-1----1序列，然后，求区间和，首先拿出前缀和。
暴力解法就是向前遍历s[k]里面最远一个小于sum[i]的数。

这种问题的更快的解法是单调栈，求取最远、最近距离当前数组元素。

单调递减栈，将最远的元素压栈，然后向后遍历，依次压入比其小的数，求某一个数离它最远的数，很显然就一层一层往上，知道找到的数大于它本身为止。

### 代码

```cpp
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        vector<int> days;
        for (int i = 0; i < hours.size(); i++) {
            if (hours[i] > 8) {
                days.push_back(1);
            } else {
                days.push_back(-1);
            }
        }
        vector<int> sum(days.size() + 1, 0);
        for (int i = 0; i < days.size(); i++) {
            sum[i+1] = sum[i] + days[i];
        }
        stack<int> decreaseStack;
        for (int i = 0; i < sum.size(); i++) {
            if (decreaseStack.empty()) {
                decreaseStack.push(i);
            } else {
                if (sum[decreaseStack.top()] > sum[i]) {
                    decreaseStack.push(i);
                }
            }
        }
        int maxDays = 0;
        for (int i = sum.size() - 1; i > 0; i--) {
            while(! decreaseStack.empty() && sum[decreaseStack.top()] < sum[i]) {
                maxDays = max(maxDays, i - decreaseStack.top());
                decreaseStack.pop();
            }
        }
        return maxDays;
    }
};
```