```C++
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0, r = arr.size() - 1;
        int m;
        while (l < r - 1) {
            m = l + (r - l) / 2;
            // 不用担心 m + 1 数组越界，有取下界：m = floor[(l + r) / 2]
            if (arr[m] < arr[m + 1]) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        if (arr[l] > arr[r]) {
            return l;
        }
        return r;
    }
};
```

![草图 (2).png](https://pic.leetcode-cn.com/55ac832a77e8103bca7b2256e42859e133882e6a924e8b92b095de19e7735f9e-%E8%8D%89%E5%9B%BE%20\(2\).png)