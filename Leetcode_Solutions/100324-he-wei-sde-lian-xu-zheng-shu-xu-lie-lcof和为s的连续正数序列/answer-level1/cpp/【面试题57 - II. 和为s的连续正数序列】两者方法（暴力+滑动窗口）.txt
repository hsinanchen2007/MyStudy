## 思路一：暴力
从 1 到 target/2，以每个数为开始检查是否存在连续和为 target。

### 代码
时间复杂度：O(n^2)
空间复杂度：O(1)
```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        for (int i = 1; i <= target / 2; ++i) {
            vector<int> tmp;
            int sum = i;
            tmp.push_back(i);
            for (int j = i + 1; j <= target / 2 + 1; ++j) {
                sum += j;
                tmp.push_back(j);
                if (sum == target) {                    
                    res.push_back(tmp);
                    break;
                } else if (sum > target) {
                    break;
                }
            }            
        }
        return res;
    }
};
```

### 简化代码
延迟临时数组保存，找到满足条件的数组再保存。
```c++
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        for (int i = 1; i <= target / 2; ++i) {            
            int sum = i;            
            for (int j = i + 1; j <= target / 2 + 1; ++j) {
                sum += j;                
                if (sum == target) {                    
                    vector<int> tmp;
                    for (int k = i; k <= j; ++k) tmp.push_back(k);
                    res.push_back(tmp);
                    break;
                } else if (sum > target) {
                    break;
                }
            }            
        }
        return res;
    }
};
```

## 思路二：滑动窗口（双指针）
设置双指针 l 和 r，初始值分别从1 和 2 开始，通过数学方法计算sum值，然后sum值和target大小关系分下面三种情况讨论：
- sum == target：找到满足条件的[l, r]，加入结果集；
- sum < target：则移动右指针
- sum > target：则移动左指针

终止条件为 l >= r，这种情况只有当r 移到 target / 2 + 1位置时，导致l < r 的时候区间大于target，移动l 使两者相等。

### 代码
时间复杂度：O(n)
空间复杂度：O(1)
```c++
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        int l = 1, r = 2;
        while (l < r) {
            int sum = (l + r) * (r - l + 1) / 2;
            if (sum == target) {
                vector<int> tmp;
                for (int i = l; i <= r; ++i) tmp.push_back(i);
                res.push_back(tmp);
                ++l;
            } else if (sum < target) {
                ++r;
            } else {
                ++l;
            }
        }
        return res;
    }
};
```

