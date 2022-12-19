### 解题思路
我的想法是把所有0的下标给找到，存放于vector中，一旦K值耗尽（也就是减少到0），起点就更新到0的下一个位置。但是执行效率不高，希望大牛指点。
### 代码

```cpp
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int left = 0;
        int right = 0;
        int ans = 0;
        int size = static_cast<int>(A.size());

        vector<int> mark;
        int index = 0;

        while (right < size) {
            int temp = A[right];
            if (temp != 1) {
                mark.push_back(right + 1);
                if (K != 0) {
                    --K;
                }
                else {
                    left = mark[index++];
                }
            }
            ans = max(ans, right - left + 1);
            ++right;  
        }
        return ans;
    }
};
```