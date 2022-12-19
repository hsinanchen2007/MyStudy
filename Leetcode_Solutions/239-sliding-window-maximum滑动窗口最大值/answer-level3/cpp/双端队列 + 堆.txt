### 解题思路

效率很低的方法。

执行用时 :2152 ms, 在所有 C++ 提交中击败了5.10% 的用户
内存消耗 :185.6 MB, 在所有 C++ 提交中击败了5.10%的用户

### 代码

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> Q;
        vector<int> res;
        
        for(int i=0; i<nums.size(); i++) {
            if(i < k) {
                Q.push_back(nums[i]);
                if(i == k - 1) {
                    vector<int> vec(Q.begin(), Q.end());
                    std::make_heap(vec.begin(), vec.end());
                    res.push_back(vec[0]);
                }
            } else {
                Q.pop_front();
                Q.push_back(nums[i]);
                vector<int> vec(Q.begin(), Q.end());
                std::make_heap(vec.begin(), vec.end());
                res.push_back(vec[0]);
            }
        }
        return res;
    }
};
```