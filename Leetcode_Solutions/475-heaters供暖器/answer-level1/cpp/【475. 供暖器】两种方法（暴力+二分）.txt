### 思路一：暴力
开始对houses和heaters进行排序，对于每个房子，在供暖器中查找最近一个可以为其供暖的供暖器的位置，如果后一个供暖器的位置和房屋位置绝对值小于前一个供暖器与房屋位置绝对值，则继续向后找供暖器，否则当前供暖器即为要找的最近位置，然后在与之前的加热半径中求最大值。

### 代码

```cpp
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int res = 0, j = 0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        for (int i = 0; i < houses.size(); ++i) {
            int cur = houses[i];
            while (j < heaters.size() - 1 && abs(heaters[j + 1] - cur) <= abs(heaters[j] - cur)) ++j;
            res = max(res, abs(heaters[j] - cur));
        }
        return res;
    }
};
```

### 思路二：二分
对每个房屋，在供暖器中进行二分查找第一个大于等于房屋位置的供暖器位置，如果找到，则可以求出之间差值dist1，如果这个数不是首个供暖器位置，可以求出和前一个供暖器的位置差值dist2，最后在两者之间求最小值，并更新加热半径。

### 代码
```c++
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int res = 0, n = heaters.size();        
        sort(heaters.begin(), heaters.end());
        for (int house : houses) {
            int left = 0, right = n;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (heaters[mid] < house) left = mid + 1;
                else right = mid;
            }
            int dist1 = (right == n) ? INT_MAX : heaters[right] - house;
            int dist2 = (right == 0) ? INT_MAX : house - heaters[right - 1];
            res = max(res, min(dist1, dist2));
        }
        return res;
    }
};
```

### 简化代码：STL
```c++
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int res = 0;        
        sort(heaters.begin(), heaters.end());
        for (int house : houses) {
            auto pos = lower_bound(heaters.begin(), heaters.end(), house);
            int dist1 = (pos == heaters.end()) ? INT_MAX : *pos - house;
            int dist2 = (pos == heaters.begin()) ? INT_MAX : house - *(--pos);
            res = max(res, min(dist1, dist2));
        }
        return res;
    }
};
```

