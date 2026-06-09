### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        int arr[3] = {2, 3, 5};
        int res = 0;
        set<long> s;    // 使用set避免中间数据结合中有重复数据，同时保证排序，为避免溢出，使用long
        // 每一轮取上一轮的最小值，用2，3，5相乘，保存到中间结果集中
        // 在从中间结果集中，取出最小值，更新本轮最小值
        for (int i = 1; i <= n; ++i) {
            if (i == 1) {
                res = 1;
                continue;
            }
            for (int j = 0; j < 3; ++j) {
                s.insert((long)arr[j] * res);
            }
            res = *s.begin();
            s.erase(s.begin());
        }
        return res;
    }
};
```