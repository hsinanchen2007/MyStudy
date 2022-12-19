如果看过[双指针经典题目的经典解法，适合新手小白！](https://leetcode-cn.com/problems/max-consecutive-ones/solution/shuang-zhi-zhen-jing-dian-ti-mu-de-jing-dian-jie-f/)，这道题就可以庖丁解牛：
1. 初始化快指针i，当然是`for i in range (len(nums))`
2. 初始化慢指针j, `j=0`
3. 构造慢指针更新的触发条件(下面讨论)
4. 执行慢指针更新逻辑(下面讨论)

我们这么想，随着快指针i的移动，当慢指针和快指针之间数字和>=s，这时就会有一个连续子数组。
然后求此连续子数组的最短长度，就是所有连续子数组的局部最优！

怎么求此连续子数组的最短长度？最直观的方法是while循环，和>=s 时，慢指针右移一位，再求和，直到和<s即可。

然后代码就很轻松地出来了：
```
class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        j = 0 ## 基本套路：初始化慢指针j
        rst = len(nums) if sum(nums)>= s else 0 ## 业务代码：初始化结果值
        for i in range(len(nums)): ## 基本套路：初始化快指针i
            while sum(nums[j:i+1])>=s and j <=i: ## 基本套路：慢指针触发
                j += 1 ## 基本套路：慢指针更新
                rst = min([rst,i-j+2]) ## 业务代码：结果值更新
        return rst
```
执行结果真是日了狗：

时间 1920 ms，战胜约5%；
空间 16.4 MB，战胜约5%！

这个双指针套路没有错，为啥这么差？
比较了各位大佬，原因出在慢指针触发里`sum(nums[j:i+1])>=s`,每次循环重新切片求和，速度特别慢。针对这一点改进一下，把它单独赋值一个变量，每次求和改成求和后每次减一个`nums[j]`:
```
class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        j = 0
        rst = len(nums) if sum(nums)>= s else 0
        sub_sum = 0 ## 新增中间变量
        for i in range(rst):
            sub_sum += nums[i]
            while sub_sum>=s and j <=i:
                sub_sum -= nums[j] ## 不用while每次求和，每次减`nums[j]`
                j += 1
                rst = min([rst,i-j+2])
        return rst
```
然后就正常了：
执行用时 :88 ms, 在所有 Python3 提交中击败了86.28%的用户
内存消耗 :16.6 MB, 在所有 Python3 提交中击败了5.14%的用户

是不是很容易理解！