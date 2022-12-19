### 解题思路
参考官方解题思路

### 代码

```cpp
/*
双指针:
其实一旦知道这个位置开始的子数组不会是最优答案了，我们就可以移动左端点。
我们用 2 个指针，一个指向数组开始的位置，一个指向数组最后的位置，并维护区间内的
和sum 大于等于 s 同时数组长度最小。

算法:
初始化 left 指向 0 且初始化 sum 为 0
遍历 nums 数组：
将 nums[i] 添加到 sum
当 sum 大于等于 s 时：
更新 ans=min(ans,i+1−left) ，其中 i+1−left是当前子数组的长度
然后我们可以移动左端点，因为以它为开头的满足 sum≥s 条件的最短子数组已经求出来了
将 sum 减去nums[left] 然后增加 left
*/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left=0,sum=0;
        int ans = INT_MAX;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            while(sum>=s)       //将左尾巴缩短，即缩小区间
            {
                ans = std::min(ans, i-left+1);
                sum -= nums[left];
                left++;
            }
        }
        return ans==INT_MAX ? 0 : ans;
    }
};
```
![image.png](https://pic.leetcode-cn.com/5aba629737d49f97f6b63adaa72b362c2219ef707716c56385e0329441f3ee9d-image.png)
