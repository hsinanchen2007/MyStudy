### 解题思路
滑动窗口
![image.png](https://pic.leetcode-cn.com/e91a8e6b5a314208b897bb67975ba238e46cf98dae5e74f891c382ce52edf611-image.png)


### 代码

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::deque<int> d;
        vector<int> vals;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (res.size() < k) {
                res.push_back(nums[i]);
                while (!d.empty() && d.back() < nums[i]) {
                    d.pop_back();
                }
                d.push_back(nums[i]);
            } 
            if (res.size() == k) {
                vals.push_back(d.front());
                int tmp = res.front();
                res.erase(res.begin());
                if (tmp == d.front()) {
                    d.pop_front();
                }
            }
        }
        return vals;
    }
};
```
![码农黑板报.png](https://pic.leetcode-cn.com/1d77d8e3e51b39e0f954c2246c23d7845f724dba2e1d81d1ba3117d1ad550dee-%E7%A0%81%E5%86%9C%E9%BB%91%E6%9D%BF%E6%8A%A5.png)
