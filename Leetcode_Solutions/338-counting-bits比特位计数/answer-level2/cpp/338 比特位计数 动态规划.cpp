### 解题思路
![image.png](https://pic.leetcode-cn.com/78bceb51334a7374eaac9ccd49d5c56b3d6a51d6db83101a867385a52aa10363-image.png)

如果奇数 为mm[t/2] + 1
如果偶数 为mm[t/2]
### 代码

```cpp
class Solution {
public:
    vector<int> countBits(int num) {
        static vector<int> mm;
        int len = mm.size();
        for (int i = len; i <= num; i++) {
            if (i == 0) {
                mm.push_back(0);
                continue;
            }
            int t = i;
            if (t % 2 == 0) {
                mm.push_back(mm[t/2]);
            } else {
                mm.push_back(mm[t/2] + 1);
            }
        }
        vector<int> res(mm.begin(), mm.begin() + num + 1);
        return res;
    }
};
```