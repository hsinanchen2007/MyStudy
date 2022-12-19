### 解题思路
![image.png](https://pic.leetcode-cn.com/d97630411b6818cb59f985e69dcd1f390aa0a87c70605e31c97dff1654e6934c-image.png)

对每一个元素，以其为开始，不断加1，看是否在数组里
直到发现不再，那么其最长连续为next - i
同时缓存之前的计算过的结果
### 代码

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        map<int, int> mm;
        for (auto i : nums) {
            mm[i] = 1;
        }
        int res = 1;
        for (auto i : nums) {
            if (mm[i] != 1) continue;
            int next = i + 1;
            while (mm.find(next) != mm.end()) {
                if (mm[next] != 1) {
                    mm[i] = next - i + mm[next];
                    break;
                }
                next++;
            }    
            if (mm[i] == 1) {
                mm[i] = next - i;
            }
            res = max(res, mm[i]);
            while (next > i) {
                mm[next] = mm[i] - (next - i);
                next--;
            }
        }
        return res;
    }
};
```