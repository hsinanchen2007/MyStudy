### 解题思路
两种思路：
1.贪心算法：（请参考大神的，我个人觉得有点取巧，不是很好想，属于神来之笔）
如果某一个作为 起跳点 的格子可以跳跃的距离是 3，那么表示后面 3 个格子都可以作为 起跳点。
可以对每一个能作为 起跳点 的格子都尝试跳一次，把 能跳到最远的距离 不断更新。
如果可以一直跳到最后，就成功了。

但是需要进行优化：每次尝试跳的时候，从最远处开始，如果最远处已经是1了，则说明前面全是1；

```cpp
class Solution {
public:
    bool canJump(vector<int> &nums)
    {
        int lastindex = 0;

        for (int i = 0; i < min(lastindex + 1, (int)nums.size()); i++) {
            lastindex = max(nums[i] + i, lastindex);
        }

        if (lastindex >= nums.size() - 1) {
            return true;
        }

        return false;
    }
};
```



2.动态规划（通用解法）
dp[i]表示当前节点是否可达
状态转移矩阵：设j<i,为0~i之间的点，j+nums[j]>i时说明i时从j可达的。0~i之间，只要存在1个j满足情况即可
因此当**存在dp[j] ==1 && nums[j]+j>=i **时，dp[i] = 1;

由于需要遍历i-1~0，因此我们逆序寻找，当找到1个即退出。



### 代码
C++
```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {

        vector<int> dp = vector<int>(nums.size() , 0);
        dp[0] = 1;
        for (int i = 1; i < nums.size();i++){
            int find = 0;
            for (int j = i - 1; j >= 0;j--){
                if(dp[j] && nums[j]+j>=i){
                    find = 1;
                    break;
                }
            }
            if(find){
                dp[i] = 1;
            }

        }

        return dp[nums.size() - 1];
    }
};
```