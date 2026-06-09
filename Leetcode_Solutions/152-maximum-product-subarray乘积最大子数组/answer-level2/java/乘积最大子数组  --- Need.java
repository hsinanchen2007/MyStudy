### 解题思路
1. 0  还好说； 负数怎么办？
2. [画解算法：152. 乘积最大子序列](https://leetcode-cn.com/problems/maximum-product-subarray/solution/hua-jie-suan-fa-152-cheng-ji-zui-da-zi-xu-lie-by-g/)
    - 遍历数组时计算当前最大值，不断更新
    - **令imax为当前最大值**，则当前最大值为 imax = max(imax * nums[i], nums[i])
    - **由于存在负数**，那么会**导致最大的变最小的，最小的变最大的**。因此还需要维护当前最小值imin，imin = min(imin * nums[i], nums[i])
    - **当负数出现时则imax与imin进行交换再进行下一步计算**
    - res = max(res, imax), res 初始值为float("-inf")
    - 时间复杂度：O(n)

3. **动态规划（由于存在负数）：**
    - 状态定义 dpmax[i]和dpmin[i]分别记录以i号元素结尾的最大子数组乘积和最小子数组乘积。
    - 状态转移： dpmax[i]=max{nums[i],nums[i]*dpmax[i-1],nums[i]*dpmin[i-1]}，类似可更新dpmin[i].
    - 初始化：为了降低空间复杂度，使用premax，premin记录i-1时的最值。

4. [最大和的连续子数组](https://leetcode-cn.com/problems/maximum-subarray/solution/python-zui-da-he-de-lian-xu-zi-shu-zu-by-a-niu-de-/)


### 代码第一版 (注释代码 和 非注释的都存在错误)
```
'''
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        nsize = len(nums)
        if nsize < 2:
            return nums[0]
        pre_0 = 0
        fs = [0]
        cur = 1
        for i, num in enumerate(nums):
            if num == 0:
                m = len(fs)
                if pre_0 is None:
                    if m & 1 == 1:
                        pre_0 = cur 
                    else:
                        for i in range(fs[m-2]+1, fs[m-1]+1):
                            cur_l /= nums[i]
                        for i in range(fs[0], fs[])
                        pre_0 = max(cur_l, cur_r)
                else:
                    pre_0 = max(pre_0, cur)
                cur = 1
                fs = [0]
            elif num < 0:
                fs.append(i)
                cur *= num

'''
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        nsize = len(nums)
        if nsize < 2:
            return nums[0]
        imax, imin = 1, 1
        for i in range(nsize):
            if nums[i] < 0:
                imax, imin = imin, imax 
            
            imax = max(nums[i], imax * nums[i])
            imin = min(nums[i], imin * nums[i])

        return max(float("-inf"), imax)

```


### 代码 最终版

```java
class Solution {
    public int maxProduct(int[] nums) {
        if(nums==null || nums.length==0) return 0;

        //返回值，用来存放阶段性最大值
        int res = Integer.MIN_VALUE;
        
        //创建两个数组，分别存放阶段性最大值和最小值的累乘
        int[] dp_max = new int[nums.length+1];
        int[] dp_min = new int[nums.length+1];
        
        dp_max[0] = 1;
        dp_min[0] = 1;

        //dp的循环
        for(int i=1; i<=nums.length; i++){
            //如果当前的nums[i-1]小于0，那么
            if(nums[i-1]<0){
                int temp = dp_max[i-1];
                dp_max[i-1] = dp_min[i-1];
                dp_min[i-1] = temp;
            }

            dp_max[i] = Math.max(dp_max[i-1]*nums[i-1], nums[i-1]);
            dp_min[i] = Math.min(dp_min[i-1]*nums[i-1], nums[i-1]);

            res = Math.max(res, dp_max[i]);
        }

        return res;
    }
}

python 版本


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        nsize = len(nums)
        if nsize ==0:
            return nums[0]
        res, imax, imin = float("-inf"), 1, 1

        for i in range(nsize):
            if nums[i] < 0:
                imax, imin = imin, imax 
            
            imax = max(imax * nums[i], nums[i])
            imin = min(imin * nums[i], nums[i])
            res = max(res, imax)

        return res 

'''
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        nsize = len(nums)
        if nsize ==0:
            return nums[0]
        res, imax, imin = float("-inf"), 1, 1

        for i in range(nsize):
            if nums[i] < 0:
                imax, imin = imin, imax 
                imax = max(imax * nums[i], nums[i])
                imin = min(imin * nums[i], nums[i])
            elif nums[i] == 0:
                imax = 0
                imin = 0
            elif imax < 0:
                imax =  nums[i]
                imin = min(imin * nums[i], nums[i])

            res = max(res, imax)

        return res 
'''


```