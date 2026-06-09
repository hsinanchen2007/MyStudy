### 解题思路
![image.png](https://pic.leetcode-cn.com/04945c453a75b7b5b3544b77ae32d3402d971a9a04f018bd249e5e492db2a4d4-image.png)
类比最小栈：https://leetcode-cn.com/problems/min-stack/
这里类似于一个最大队列的数据结构
其实就是队列里会不断出队入队，需要维护一个最大值
几种情况
1.新入队元素，大于远最大值，最大值为新入队元素
2.原有最大值出队，需要重新遍历维护最大值


### 代码

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.empty()) return res;
        int len = nums.size();
        int cur = 0;
        int max_n = nums[0];
        while (cur < len && cur < k) {
            max_n = max(max_n, nums[cur]);
            cur++;
        }
        res.push_back(max_n);
        if (len < k) return res;
        for (int i = cur; i < len; i++) {
            int pre_cur = i - k;
            if (nums[i] >= max_n) {
                max_n = nums[i];
            } else if (nums[pre_cur] == max_n) {
                //最大元素出队列
                max_n = nums[i];
                for (int j = pre_cur + 1; j <= i; j++) {
                    max_n = max(max_n, nums[j]);
                }
            }
            res.push_back(max_n);
        }
        return res;
    }
};
```