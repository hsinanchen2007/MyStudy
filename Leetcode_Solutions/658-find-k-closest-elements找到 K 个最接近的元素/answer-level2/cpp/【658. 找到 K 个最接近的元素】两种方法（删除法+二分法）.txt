## 思路一：删除法
等价于从数组中删除n-k个数，而且每次去掉的数一定在头尾，因为距离x最远的数一定出现在头尾，所以每次比较头尾元素与x的距离，将距离较大的删除。
### 代码
```c++
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {        
        while (arr.size() > k) {
            if (x - arr.front() <= arr.back() - x) {
                arr.pop_back();
            } else {
                arr.erase(arr.begin());
            }
        }
        return arr;
    }
};
```

## 思路二：二分法（最优解）
假设k个数为`[arr[i], arr[i + k -1]]`
我们对 i 进行二分，然后比较 `x - arr[mid]` 和 `arr[mid + k] - x` 距离。
如果 `x - arr[mid] > arr[mid + k] - x`，表示 `[arr[mid + 1], arr[mid + k]]` 区间比 `[arr[mid], arr[mid + k - 1]]`好，所以左移 left。
### 代码
```c++
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - k;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};
```


