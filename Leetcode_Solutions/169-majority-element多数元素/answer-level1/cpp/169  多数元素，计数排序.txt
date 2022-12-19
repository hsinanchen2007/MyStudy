### 解题思路
map记录每个元素个数
![image.png](https://pic.leetcode-cn.com/b1fdb26a1fad672409e53122406094685ae8d3213c10f4052931a2cb1a36323d-image.png)

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        int len = nums.size();
        for (auto i :nums) {
            if (m.find(i) == m.end()) m[i] = 0;
            m[i]++;
            if (m[i] > len / 2) return i;
        }
        return 0;
    }
};
```