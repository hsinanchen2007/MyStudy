#### 主要思想：
将vector复制一份到尾部，然后使用单调栈一次遍历，返回前半部分的vector就解决了。
#### 战果：
96ms 98.72%,14.3MB 29.92%

主要用了单调栈，如果不懂单调栈，建议看看[下一个更大元素 I 的置顶题解](https://leetcode-cn.com/problems/next-greater-element-i/solution/dan-diao-zhan-jie-jue-next-greater-number-yi-lei-w/)，很详细。

```C++
class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        int sLen = nums.size();
        for (int i = 0; i < sLen; i++) {
            nums.push_back(nums[i]);
        }
        vector<int> rtAll(nums.size());
        stack<int> u;
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!u.empty() && u.top() <= nums[i]) {
                u.pop();
            }
            rtAll[i] = u.empty() ? -1 : u.top();
            u.push(nums[i]);
        }
        vector<int> rtPart(rtAll.begin(), rtAll.begin() + nums.size() / 2);
        return rtPart;
    }
};
```