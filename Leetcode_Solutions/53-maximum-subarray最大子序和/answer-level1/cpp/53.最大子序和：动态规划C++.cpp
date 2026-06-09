### 解题思路
就是官方发的方法的C++版
方法三：动态规划（Kadane 算法）
算法：

在整个数组或在固定大小的滑动窗口中找到总和或最大值或最小值的问题可以通过动态规划（DP）在线性时间内解决。
有两种标准 DP 方法适用于数组：


常数空间，沿数组移动并在原数组修改。
线性空间，首先沿 left->right 方向移动，然后再沿 right->left 方向移动。 合并结果。
![image.png](https://pic.leetcode-cn.com/32642df4c067edeede5ca61b27c0fc770752d42e5897ebeafe40987e1f8dc05b-image.png)


我们在这里使用第一种方法，因为可以修改数组跟踪当前位置的最大和。
下一步是在知道当前位置的最大和后更新全局最大和。



### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(),maxSum=nums[0];
        for(int i = 1; i < n; ++i){
            if(nums[i-1] > 0) nums[i] += nums[i-1];
            maxSum = nums[i] > maxSum?nums[i]:maxSum; 
        }
        return maxSum;
    }
};
```