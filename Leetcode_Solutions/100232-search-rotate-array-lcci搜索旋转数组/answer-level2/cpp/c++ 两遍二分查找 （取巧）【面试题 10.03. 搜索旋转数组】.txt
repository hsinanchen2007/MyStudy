### 解题思路
1. 第一遍二分查找找到转折点，转折点将数组分为前后两个递增序列。
2. 然后判断target值在哪个区间，如果两个区间都在，选择前半段区间
3. 在选定区间中用二分查找第一个不大于target的位置，找到后判断是否等于target，不是则返回-1

找第一个不大于target的位置：
if (arr[mid] >= target) right = mid;                     
else left = mid+1;

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& arr, int target) {
        int left = 0, right = arr.size()-1;      // 先用二分查找找到转折点
        while (left < right) {
            int mid = (left +right) / 2;
            if (arr[mid] <= arr[right]) {
                right = mid;
            } else if (arr[mid] >= arr[left]) {
                left = mid+1;
            }
        }
        if (target >= arr[0]) {                  // 优先先用前半段
            left = 0, right = right - 1;
        } else {
            right = arr.size()-1;
        }
        while (left < right) {
            int mid = (left + right) / 2;
            if (arr[mid] >= target) {            
                right = mid;                     
            } else if (arr[mid] < target) {
                left = mid+1;
            }
        }
        if (arr[right] != target) return -1;
        return right;
    }
};
```