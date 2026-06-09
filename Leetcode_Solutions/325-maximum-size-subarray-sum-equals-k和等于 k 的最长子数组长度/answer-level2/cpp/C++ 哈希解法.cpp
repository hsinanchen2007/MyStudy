```
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        map<int, int> m{{0, -1}};
        int s = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            s += nums[i];
            if (m.count(s - k)) res = max(res, i - m[s - k]);
            if (m.count(s) == 0) m[s] = i;
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/90de52a2e7b37fee469bb40eee555ac6d88aa06cb7338d3fd7e699dbccceb471-image.png)


