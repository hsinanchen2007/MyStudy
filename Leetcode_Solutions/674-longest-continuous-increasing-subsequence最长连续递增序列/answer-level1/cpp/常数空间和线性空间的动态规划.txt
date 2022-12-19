### 解题思路

- **线性dp**
- 我们可以定义一维数组dp
- dp[i]表示以i为结尾的数组的最长连续递增序列值
- nums[i+1] > nums[i] 就将该点接在dp[i]后面使值增1，即dp[i+1] = dp[i] + 1;
- 每一点的值长度都为1，故当不满足条件时，重新开始dp[i+1] = 1
- 只需要比较到每点的最大值，所得到的结果即为答案


#### 初始化
dp数组初始化为1


### 状态转换
 
```cpp
if(nums[i] > nums[i-1]) dp[i] = dp[i-1] + 1;
else dp[i] = 1;
```

### 输出

```cpp
rst = max(dp[i], rst);
```
- 时间复杂度：O(n)
- 空间复杂度：O(n)


### 压缩状态

**常数dp**
- 我们发现我们只需要用到前一个数字的序列长度值，并且每次都只是增1，或者重置为1
- 故，我们只需要一个now_len变量指示到目前为止的序列值
- 空间复杂度：O(1)


### 代码

```cpp
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        /* O(n)时空
        // 时间复杂度O(n)
        int len = nums.size();
        if(len < 2) return len;
        vector<int>dp(len, 1);
        int j=1;
        int rst = 0; 
        for(int i=0; j<len; ++i, ++j){
            if(nums[i] < nums[j]) dp[j] += dp[i];
            if(rst < dp[j]) rst = dp[j];
        }
        return rst;
        // 空间复杂度O(n)
        */
        //常数项空间复杂度
        if(nums.size() == 0) return 0;
        int rst = 1; //数组不为空
        int now_len = 1;
        for(int i=1; i<nums.size(); ++i){
            if(nums[i] > nums[i-1]) ++now_len;
            else now_len = 1;
            if(rst < now_len) rst = now_len; 
        }
        return rst;
    }
};
```