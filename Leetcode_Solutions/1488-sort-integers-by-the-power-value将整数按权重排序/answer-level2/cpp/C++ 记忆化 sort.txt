### 解题思路
计算权重时使用记忆化避免重复计算
对[下标，权重]二元组进行排序

![图片.png](https://pic.leetcode-cn.com/215c6645d2985b1ae5d0540f4de0b83996ca47d259d5b0b82f4e7d9dad0a4f2e-%E5%9B%BE%E7%89%87.png)

### 代码

```cpp
class Solution {
public:
    int getKth(int lo, int hi, int k) {
        int n = hi - lo + 1;
        vector<pair<int, int>> arr;
        unordered_map<int, int> mem;
        for (int i = lo; i <= hi; ++i) {
            int curr = i;
            int w = 0;
            while (curr != 1) {
                if (mem.count(curr) == 1) {
                    w += mem[curr];
                    break;
                }
                if (curr % 2 == 0) {
                    curr /= 2;
                } else {
                    curr = curr * 3 + 1;
                }
                ++w;
            }
            mem[i] = w;
            arr.emplace_back(i, w);
        }
        sort(arr.begin(), arr.end(), [](const pair<int, int>& a, const pair<int, int>& b) -> bool {
            return (a.second != b.second) ? (a.second < b.second) : (a.first < b.first);
        });
        return arr[k - 1].first;
    }
};
```