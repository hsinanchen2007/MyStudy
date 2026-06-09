### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> v(128, -1);
        int left = 0;
        int right = 0;
        int max = 0;

        for (right = 0; right < s.size(); right++) {
            if (v[s[right]] >= left) {
                // 在滑窗内移动左指针
                left = v[s[right]] + 1;
            } else {
                // 不在滑窗内更新长度
                if (max <= (right - left + 1)) {
                    max = right - left + 1;
                }
            }
            // 更新vis数组中对应下边索引
            v[s[right]] = right;
        } 
        return max;
    }
};
```
![image.png](https://pic.leetcode-cn.com/d644520a5ad79b8764861d959d75b2e75c936b844e35cc546e65723c29e1d497-image.png)
