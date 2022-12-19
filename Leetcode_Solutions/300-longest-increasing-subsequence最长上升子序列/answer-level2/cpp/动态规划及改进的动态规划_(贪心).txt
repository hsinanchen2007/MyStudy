### 解题思路

这道题的思路应该可以参考[674.最长连续递增序列](https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence/solution/chang-shu-kong-jian-he-xian-xing-kong-jian-de-dong/)

**求解连续子序列与子序列的关系**
- 当求解连续子序列的时候相等于隐型加入了一个限制，即到该点的递增子序列长度的变化与否只取决于该点与前一点的大小关系
    - 大于，长度增1
    - 不大于，长度初始化为1 
- 当求解子序列的时候我们不仅需要考虑与前一个结点的关系还需要考虑与之前所有结点的大小关系
- 基于这个思路我们就可以得到O(n^2)时间复杂度的动态规划
- 设置dp[i]表示以i为结尾的子序列的最大长度
- 判断还是基于nums[j] 与 nums[i]`if nums[i] < nums[j] && dp[i] >= dp[j]`
    - 然而这里的i并不仅仅是j-1而是0 ~ j-1间的数据
    - 同时我们还必须满足将nums[i]并入nums[j]的子序列后所得到的序列比当前的最大值要长
    - 即：
        - nums[j] > nums[i] 为判别条件
        - dp[i] >= dp[j] 为更新条件
## 动态规划


### 初始化

`dp[i] = 1`每段为单独子序列长度为1


### 状态转换

```cpp
i = 0 to j-1 
if nums[j] > nums[i] && dp[i] >= dp[j]  dp[j] = dp[i] + 1
```


### 输出

`i = 0 to len - 1; rst = max(rst, dp[i])`所有结点的最大值


### 代码

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 采用二分查找处理(0, i)上的上升子序列
        // O(n^2)
        // dp[i]记录以该点为结尾得最长上升子序列长度
        // 初始化为1
        // nums[j] > nums[i] && dp[j] <= dp[i]
        int len = nums.size();
        vector<int> dp(len, 1);
        int rst = 0;
        for(int i=0; i<len; ++i)
        {
            for(int j=0; j<i; ++j)
            {
                if(nums[i] > nums[j] && dp[i] < dp[j]+1) dp[i] = dp[j]+1;
            }
            rst = max(rst, dp[i]);
        }
        return rst;
    }
};
```

## 升级版的动态规划

### 思考状态

- 我们能不能把O(n^2)的时间复杂度降低到O(nlgn)呢？
    
    - 首先思考我们得到的连续子序列
        
        - 对于给定的序列1 5 2 4 3 6
        - 我们知道其最长上升子序列为1 2 3 6
        - 在更新到3之前我们看长度为2的上升子序列有3个即
            - 1,5;  1,2;  1,4
        - 然而3都无法跟到5和4的后面
    - 能否降低内层循环的查找次数
        - 我们知道，内层循环主要是来寻找比要判断的数据小的最长连续子序列。
        - 既然是比较大小，那么如果前面的数据是有序的，我们就可以用二分查找法使内层循环将为lgn。
        - 但是如果对前面的数据进行排序就会破坏结构所得到的数据就是不对的
        - 我们得到的连续上升子序列本身即是连续的
        - 通过前面的分析我们知道对于长度相同的连续子序列其尾部的值越小（数据和数据之间越紧凑）加入新数据的可能性就越大

- 定义一维数组dp_pro其中dp_pro[i]为长度为i+1的连续子序列的最小末尾值
- 如何根据dp[i]得到dp_pro[i]呢，解决了这个问题也就得到了状态转换方程

### 初始化

`dp_pro[0] = nums[0]`

### 状态转换

我们知道dp_pro中存储的是当前连续子序列的数值并且目的是为了让他尽可能的紧凑
那么每到一个数据我们就与该子序列的最后元素进行比较
- 如果大于末尾元素表明可以加入子序列中，并使得最长长度增加1
- 如果不可以，表示子序列的最大长度不变但我们可以使dp_pro变得更加紧凑
    - 找到第一个大于该数据的数将他替换掉
**此时已经不属于动态规划了，因为替换后并不一定是子问题的解** 


```cpp
end = 0;
i = 1 to len-1
if(nums[i] > dp_pro[end]) dp[++end] = nums[i]
else
    search[2] = {0, end} //边界
    while(search[0] < search[1]>)
        mid = (search[0] + search[1])>>1
        if(nums[i]>dp_pro[mid]) search[0] = mid + 1
        else search[0] = mid
    dp_pro[search[0]] = nums[i] 
// 二分法查找到第一个大于nums[i]的数替换   
```

### 输出
`end + 1 `即为最后答案



### 代码
```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp_pro(len, 1);
        if(len == 0) return 0; // 特判
        dp_pro[0] = nums[0];  // 初始化
        int end = 0; // dp_pro的长度
        for(int i=1; i<len; ++i)
        {
            if(nums[i] > dp_pro[end]) dp_pro[++end] = nums[i];
            else 
            {
                // 找到第一个大于nums[i]的数
                int search[2] = {0,end};
                while(search[0] < search[1])// 二分查找
                {
                    int mid = search[0] + ((search[1] - search[0]) >> 1); //除以2
                    if(nums[i] > dp_pro[mid]) search[0] = mid+1; 
                    else search[1] = mid;
                }
                dp_pro[search[0]] = nums[i]; 
            }
        }
        ++end;
        return end;
    }
```
