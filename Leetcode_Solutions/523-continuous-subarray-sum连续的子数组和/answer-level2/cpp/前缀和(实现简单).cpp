### 解题思路
  #### 该题要回答两个问题：1. 如何找到连续的子数组使的他们的和为k的倍数。 2. 该子数组的长度至少为2。
  **先回答第一个问题**：对于给出的`[a,b,c,d,e]`,`k = i`. 假如前2位`[a,b]`之和对`k`取mod为`sur`，前4位`[a,b,c,d]`对`k`取mod也为`sur`，说明`[c,d]`之和为`k`的倍数(这点没人否认吧？)。那么`[c,d]`即是满足为`k`的倍数的一个解。换句话说，即我们要找到两个位置，他们的前缀和对`k`取mod相等，此时函数返回`true`。
  **第二个问题的解决方案是**：当处理完当前第`n`位的前`n`项和，判断记录中(这里用set记录)是否存在和第`n`位具有相同的余数的位置。再将第`n-1`位的前`n-1`项和插入到记录中。这样每次处理第`n`位时，扫描的都是`n-2`位及以前的结果。这就保证了子数组长度至少为`2`

#### 同类题型：
[560. 和为K的子数组](https://leetcode-cn.com/problems/subarray-sum-equals-k/solution/qian-zhui-he-shi-xian-jian-dan-by-jarvis1890/)

### 代码

```cpp
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (k == 0) {
            for (int i = 1; i < nums.size(); ++i) {
                if (nums[i] == 0 && nums[i - 1] == 0) {
                    return true;
                }
            }
            return false;
        }
        //预处理，假如k=-6，而且存在子数组是6的倍数的话，它一定是-6的倍数
        k = abs(k);
        //记录出现过的前n项和。要有初始化s{0}，否则[1,2,1,2], k = 6这样的输入不会有正确结果 
        unordered_set<int> s{0};

        //延迟插入
        int cur = nums[0] % k;
        for (int i = 1; i < nums.size(); ++i) {
            int pre = cur;
            cur = (cur + nums[i]) % k;
            if (s.count(cur) > 0) {
                return true;
            }
            s.insert(pre); 
        }
        return false;
    }
};


```