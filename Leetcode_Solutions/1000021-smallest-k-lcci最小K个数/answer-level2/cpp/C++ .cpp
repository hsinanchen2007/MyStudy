### 解题思路

使用priority_queue 

### 代码

```cpp
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {

        //最小堆
        priority_queue<int, vector<int>, greater<int>> queue(arr.begin(), arr.end());

        vector<int> v;
        v.reserve(k);
        for(int i = 0; i < k; ++i)
        {
            v.push_back(queue.top());
            queue.pop();
        }

        return v;
    }
};
```