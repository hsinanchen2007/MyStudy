```C++ []
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if (nums.empty()) return {};
        int N = nums.size();
        vector<int> res(N, -1);
        stack<int> st;
        for (int i = 0, k = 0; k < 2;) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                res[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
            i = (i + 1) % N;
            k += i == N - 1;
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/6dd9ad3a077b8962a90039c5a301f8b135cec154d22e2e37b2b6df09edd90cf0-image.png)
