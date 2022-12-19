```
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> m{{0, -1}};
        int s = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            s += (nums[i] == 0) ? -1 : 1;
            if (m.count(s)) res = max(res, i - m[s]);
            else m[s] = i;
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/b82db34bcfd1303382a4a2e16fd662d29ea73eaee47f33a2ae05fef77890fcf7-image.png)
