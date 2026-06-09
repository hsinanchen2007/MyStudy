- 版本一：双候选模板

先找到和 x 最接近的两个数，再向两边扩展。不过这个方法在 k 值较大的时候会退化，因此比较傻。

```cpp
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    if (arr.size() == 1) return arr; 
    // 双候选
    int lo = 0, hi = arr.size() - 1;
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo >> 1);
        if (x <= arr[mid]) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    deque<int> res;
    int i = lo, j = hi;
    while (res.size() < k) {
        if (j == arr.size() || (i >= 0 && x - arr[i] <= arr[j] - x)) {
            res.push_front(arr[i--]);
        } else {
            res.push_back(arr[j++]);
        }
    }
    return vector<int>(res.begin(), res.end());
}
```

- 版本二：lowerbound 模板

这才是最优解法：只寻找左边界即可。

思路：假设 mid 是左边界，则当前区间覆盖的范围是 [mid, mid + k -1]. 如果发现 a[mid] 与 x 距离比 a[mid + k] 与 x 的距离要大，说明解一定在右侧。

```
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int lo = 0, hi = arr.size() - k;
    while (lo < hi) {
        int mid = lo + (hi - lo >> 1);
        if (x - arr[mid] > arr[mid + k] - x ) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return vector<int>(arr.begin() + lo, arr.begin() + lo + k);
}
```

