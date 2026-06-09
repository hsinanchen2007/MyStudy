### 构建小顶堆，依次取出 k 个堆顶元素

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        if (k == 0) return res;
        priority_queue<int, vector<int>, greater<int>> heap(arr.begin(), arr.end());
        res.resize(k);
        for (int i = 0; i < k; i++) {
            res[i] = heap.top();
            heap.pop();
        }
        return res;
    }
};
```

### 用快速排序的 partition 函数，分治思想
```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        if (k == 0) return res;
        res.reserve(k);
        int low = 0, high = arr.size() - 1;
        while (res.size() != k) {
            int index = partition(arr, low, high);
            if (index - low + 1 <= k - res.size()) {
                for (int i = low; i <= index; i++) {
                    res.push_back(arr[i]);
                }
                low = index + 1;
            } else {
                high = index - 1;
            }
        }
        return res;
    }
    
private:
    int partition(vector<int> &arr, int p, int r) {
        int i = p;
        for (int j = p; j < r; j++) {
            if (arr[j] < arr[r]) {
                swap(arr[i], arr[j]);
                i++;
            }
        }
        swap(arr[i], arr[r]);
        return i;
    }
};
```