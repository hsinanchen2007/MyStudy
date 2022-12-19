### 解题思路
此处撰写解题思路
最大堆 取堆顶的最小值
### 代码

```cpp
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int> res;
        priority_queue<int, vector<int>, greater<int>> heap;//用最大堆做
        for(auto a:arr)
        {
            heap.push(a);
        }
        int i=0;
        while(i++<k)
        {
            res.push_back(heap.top());
            heap.pop();
        }
        return res;
    }
};
```