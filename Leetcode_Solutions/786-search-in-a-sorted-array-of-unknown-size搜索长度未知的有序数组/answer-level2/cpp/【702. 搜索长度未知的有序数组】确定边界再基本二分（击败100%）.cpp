## 思路
因为越界返回一个固定值，不确定右边界直接二分也可以，但时间效率低。
### 代码
时间复杂度：O(logn)
```c++
class Solution {
    const int MAX = 20000;   
    const int INVALID = 2147483647;
public:
    int search(const ArrayReader& reader, int target) {
        int left = 0, right = 1;
        while (reader.get(right) != INVALID) right *= 2;
        while (left <= right) {
            int mid = left + (right - left) /  2;
            if (reader.get(mid) == target) {
                return mid;
            } else if (reader.get(mid) < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};
```
