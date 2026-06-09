跟[小偷](https://leetcode-cn.com/problems/house-robber/)这道题非常相似，最常见的序列型动态规划，我们很容易想到状态：要么接受第`k`位客人的预约，要么不接受。状态转移也很好写，由于只跟上一位客人是否接受预约有关，所以只需要两个状态值就能完成转移。
```
class Solution {
public:
    int massage(vector<int>& nums) {
        int lastR = 0, lastNR = 0, nextLastR = 0;
        // lastR:上一位客人的预约接受 lastNR:上一位客人的预约没有接受
        // nextLastR在这里是为了避免改变前一次的lastR状态，而影响lastNR的转移
        for (auto& v : nums) {
            nextLastR = max(lastR, lastNR + v);
            lastNR = max(lastNR, lastR);
            lastR = nextLastR;
        }
        return max(lastNR, lastR);
    }
};
```
如果对同学有帮助，star一下吧