* [官方题解](https://leetcode-cn.com/problems/majority-element/solution/duo-shu-yuan-su-by-leetcode-solution/)已经总结得非常全面了（不过没提位运算），从解法到证明都很详细，值得一读。在`随机法`中，由于太久没搞高数了，证不来n取无穷时为何收敛到2，挖个坑。

* 第一思路是hashmap，时间复杂度O（N），空间复杂度O（N）。
* 第二思路是sort，时间复杂度O（NlogN），空间复杂度可以达到O（1）。
* 这两个思路都很朴素，不必赘述。

* 下面实现了两种比较新颖的方法。

### 投票法

* `candidate`记录此刻的待定众数。`count`记录票数，遇到自己就加一票，遇到别人就减一票，当减到0时，下一位数就成为新的`candidate`。留到最后的`candidate`就是我们的众数。
* 怎么讲，看到这个算法后，直观上也挺好理解，官方给出的借助`value`数组证明的方法也很好。但是要靠自己想到这样的算法，确实有困难。唯有多学习多积累啊。
* 时间复杂度O(N)，空间复杂度O(1)。

```python []
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        # 投票法
        candidate = nums[0]
        count = 0
        for n in nums:
            if count == 0:
                candidate = n
            if n == candidate:
                count += 1
            else:
                count -= 1
        return candidate
```

### 位运算
* 最初假定`nums`中的元素是**32位unsign**，即从`0`到`2**32-1`，提交后的反馈告诉我们，数组里是会有负数滴。于是踩坑后把我们的假定调整为**32位sign**，即从`-2**31`到`2**31-1`
* 复习一下，对于32位sign：
    * 最高位是符号位，1是负数，0是正数。
    * 最高位的权值是负数，为`-2**31`，其他位的权值是正数，跟unsign时一样，为`2**i`。
    * 举例：`100...(省略n个0)...101`，代表的十进制数字为`-2**31 + 4 + 1`
* 这个算法的motivation在于，**把`nums`中的每个元素`n`都看做二进制数，如果某元素为众数，那它的二进制表示中的每一位都是众数**。例如，假设众数为7，它的二进制是00...01011，那么统计所有元素的二进制的最右一位，它们的众数肯定是1，同理，右二的众数肯定是1，右三的众数肯定是0……
* 所以算法思路如下：
    * 用`res`表示众数，初始为0。
    * 对于32位中的每一位`i`，寻找这位0多还是1多。具体做法是统计1出现的个数是否大于`len(nums)//2`
        * 如果1多，且不是最高位，那么`res`加上`2**i`
        * 如果1多，且是最高位，说明这个数是负数，那么`res`减去`2**31`
* 时间复杂度O(n)，空间复杂度O(1)

```python []
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        res = 0
        k = len(nums)//2
        for i in range(32):
            ones = 0
            for n in nums:
                ones += (n >> i)& 1
                if ones > k:
                    if i == 31:
                        res -= 2**31
                    else:
                        res += 1 << i
                    break
        return res
```