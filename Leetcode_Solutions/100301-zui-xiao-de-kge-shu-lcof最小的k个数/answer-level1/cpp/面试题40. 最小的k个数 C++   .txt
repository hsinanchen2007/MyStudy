### 解题思路
1、最小堆

2、排序

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> heap(arr.begin(), arr.end());

        vector<int> v;
        v.reserve(k);

        for(int i = 0; i < k; ++i)
        {
            v.push_back(heap.top());
            heap.pop();
        }

        return v;
    }


    vector<int> getLeastNumbers(vector<int>& arr, int k) {

        sort(arr.begin(), arr.end());
        return vector<int>(arr.begin(), arr.begin() + k);
    }


    vector<int> getLeastNumbers(vector<int>& arr, int k) {

        nth_element(arr.begin(), arr.begin() + k, arr.end());

        return vector<int>(arr.begin(), arr.begin() + k);
    }
};
```