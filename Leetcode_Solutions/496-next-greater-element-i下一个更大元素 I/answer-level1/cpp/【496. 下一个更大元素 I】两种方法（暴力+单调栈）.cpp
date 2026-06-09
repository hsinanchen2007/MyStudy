### 思路一：暴力遍历+哈希
对于num2中每个元素从下一个位置遍历找到其右边第一个大于当前元素的值并使用哈希表保存当前值和右边第一个大于的元素值直接的映射关系，如果没有则记为-1。

### 代码
时间复杂度：O(n^2)
空间复杂度：O(n)
```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ump;
        for (int i = 0; i < nums2.size(); ++i) {
            int j;
            for (j = i + 1; j < nums2.size(); ++j) {
                if (nums2[j] > nums2[i]) {
                    ump.insert({nums2[i], nums2[j]});
                    break;
                }
            }
            if (j == nums2.size()) {
                ump[nums2[i]] = -1;
            }            
        }
        vector<int> res;
        for (auto n : nums1) {
            res.push_back(ump[n]);
        }
        return res;
    }
};
```

### 思路二：单调栈（最优）
单调递减栈，遍历num2
while 栈不为空且栈顶元素小于当前元素
- 则找到栈顶元素右边第一个大于其的元素，那么将栈顶元素和当前元素的映射关系保存到哈希表中。

最后将当前元素放入栈中

### 代码
时间复杂度：O(m+n)
空间复杂度：O(n)
```c++
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        stack<int> st;
        unordered_map<int, int> ump;
        for (auto n : nums2) {
            while (!st.empty() && st.top() < n) {
                ump[st.top()] = n;
                st.pop();
            }
            st.push(n);
        }
        for (auto n : nums1) {
            res.push_back(ump.count(n) ? ump[n] : -1);
        }
        return res;
    }
};
```
