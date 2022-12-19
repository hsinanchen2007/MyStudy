### 解题思路
注意方向和边界。

### 代码

```cpp
class Solution {
public:
    struct node {
        int index;
        int value;
        node (int iIndex, int iValue) {
            index = iIndex;
            value = iValue;
        }
    };
    struct cmp {
        bool operator() (node a, node b) {
            return a.value < b.value;
        }
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> results;
        priority_queue<node, vector<node>, cmp> slidingWindow;
        for (int i = 0; i < k; i++) {
            slidingWindow.push(node(i, nums[i]));
        }
        for (int i = k; i <= nums.size(); i++) {
            while(! slidingWindow.empty() && slidingWindow.top().index < i - k) {
                slidingWindow.pop();
            }
            if (! slidingWindow.empty()) {
                results.push_back(slidingWindow.top().value);
            }
            if (i != nums.size()) {
                slidingWindow.push(node(i, nums[i]));
            }
        }
        return results;
    }
};
```