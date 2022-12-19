### 解题思路
在回溯法的基础上，添加了对vector的push_back的优化，预先用reserve预留了result的容量大小，这样不至于在频繁push_back的时候出现多次重新申请内存以及元素拷贝。

在每层递归时，需要过滤出上层递归已经选择过的元素，从剩下的元素里遍历挑选。所以在遍历nums时，用find来寻找current里是否已经出现了num，整体是O(n的2次方)，感觉好低效。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        result.reserve(get_factorial(nums.size()));
        vector<int> current;
        recursive(nums, current, result);
        return result;
    }

    void recursive(vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (int num : nums) {
            if (find(current.begin(), current.end(), num) == current.end()) {
                current.push_back(num);
                recursive(nums, current, result);
                current.pop_back();
            }
        }
    }
    int get_factorial(int num) {
        int fac = 1;
        for (int i = 1; i <= num; ++i)
        {
            fac *= i;
        }

        return fac;
    }
};
```

![微信截图_20200407030057.png](https://pic.leetcode-cn.com/8584a9b6740d9096b93cae9300bdf3feda08fdb46c3b2b13d4cb78b6b70785b5-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200407030057.png)
