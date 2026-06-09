### 解题思路
一开始以为很简单，贪心奇偶就行了，然后发现并不是。。。
这个先可以简单处理一下只有一个元素、两个元素、三个元素的case
然后用dp，dp[i]表示打劫到第i间房子可以获取的最大收益，那么dp[i]=max(dp[i-1], dp[i-2] + nums[i]). 如果房子不是收尾相连的话，做到这里已经可以了。但问题就在于首位相连，这里最后一个房子是不是打劫会受到第一间房子是否被打劫的影响，所以需要特殊处理一下最后一间房子。
我们用useFirst[i]来表示dp[i]是否打劫了第一间房子。那么在dp递推的时候，就可以处理一下。假设我们打劫了第一间房子，也就是dp[0]=nums[0]. 那么递推过程中有 useFirst[i] 的值为 useFirst[i-1] 或者 useFirst[i-2]. 这样的话，到最后一间房子的时候，可以通过倒数第二和第三间房子是否被打劫了来处理最后的结果。但是这种做法是有局限性的，因为我们打劫了第一间房子会对dp造成影响。所以我们可以用另外一个dp2来存储不打劫第一间房子的最大收益。最后，再判断一下打劫第一间房子的最大收益dp[nums.length-1] 和 dp2[nums.length-1] 就行了。

![WX20191217-105733.png](https://pic.leetcode-cn.com/099232dcdca922b19a44689981b1b2d88f49e40699c95aba51772cb1cbcaa7b3-WX20191217-105733.png)


### 代码

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        long size = nums.size();
        if (size == 0) {
            return 0;
        } else if (size == 1) {
            return nums[0];
        } else if (size == 2) {
            return max(nums[1], nums[0]);
        } else if (size == 3) {
            return max(nums[2], max(nums[1], nums[0]));
        }
        vector<int> dp(size, 0); //打劫第一间房子
        vector<int> dp2(size, 0); //不打劫第一间房子
        vector<bool> useFirst(size, false);
        dp[0] = nums[0];
        useFirst[0] = true;
        if (nums[0] > nums[1]) {
            dp[1] = dp[0];
            useFirst[1] = true;
        }
        dp2[1] = nums[1];
        int res = 0;
        for (int i=2; i<size; i++) {
            if (i != size-1) {
                if (dp[i-1] > dp[i-2] + nums[i]) {
                    dp[i] = dp[i-1];
                    useFirst[i] = useFirst[i-1];
                } else {
                    dp[i] = dp[i-2] + nums[i];
                    useFirst[i] = useFirst[i-2];
                }
                if (dp2[i-1] > dp2[i-2] + nums[i]) {
                    dp2[i] = dp2[i-1];
                } else {
                    dp2[i] = dp2[i-2] + nums[i];
                }
            } else {
                
                if (useFirst[i-1] && useFirst[i-2]) {
                    res = max(dp[i-1], dp[i-2]);
                } else if (useFirst[i-1]) {
                    res = max(dp[i-1], dp[i-2] + nums[i]);
                }
                
                res = max(res, max(dp2[i-1], dp2[i-2] + nums[i]));
            }
        }
        return res;
    }
};
```