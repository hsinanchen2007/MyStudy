#### 解题思路：

> 本题常见解法如下：
> 1. **哈希表统计法：** 遍历数组 `nums` ，用 HashMap 统计各数字的数量，最终超过数组长度一半的数字则为众数。此方法时间和空间复杂度均为 $O(N)$ 。
> 2. **数组排序法：** 将数组 `nums` 排序，由于众数的数量超过数组长度一半，因此 **数组中点的元素** 一定为众数。此方法时间复杂度 $O(N log_2 N)$。
> 3. **摩尔投票法：** 核心理念为 **“正负抵消”** ；时间和空间复杂度分别为 $O(N)$ 和 $O(1)$ ；是本题的最佳解法。

##### 摩尔投票法：

- **票数和：** 由于众数出现的次数超过数组长度的一半；若记 **众数** 的票数为 $+1$ ，**非众数** 的票数为 $-1$ ，则一定有所有数字的 **票数和 $> 0$** 。
- **票数正负抵消：** 设数组 `nums` 中的众数为 $x$ ，数组长度为 $n$ 。若 `nums` 的前 $a$ 个数字的 **票数和 $= 0$** ，则 数组后 $(n-a)$  个数字的 **票数和一定仍 $>0$** （即后 $(n-a)$ 个数字的 **众数仍为 $x$** ）。

![Picture1.png](https://pic.leetcode-cn.com/b6845a71f5737e42c64092c4721582761e22e1ba9103f6e777b7e01dd7a40abd-Picture1.png){:width=500}

##### 算法原理：

- 为构建正负抵消，假设数组首个元素 $n_1$ 为众数，遍历统计票数，当发生正负抵消时，**剩余数组的众数一定不变** ，这是因为（设真正的众数为 $x$ ）：
  - **当 $n_1 = x$ ：** 抵消的所有数字中，有一半是众数 $x$ 。
  - **当 $n_1 \neq x$ ：** 抵消的所有数字中，少于或等于一半是众数 $x$ 。
- 利用此特性，每轮假设都可以 **缩小剩余数组区间** 。当遍历完成时，最后一轮假设的数字即为众数（由于众数超过一半，最后一轮的票数和必为正数）。

##### 算法流程:

1. **初始化：** 票数统计 $votes = 0$ ， 众数 $x$；
2. **循环抵消：** 遍历数组 `nums` 中的每个数字 $num$ ；
   1. 当 票数 $votes$ 等于 $0$ ，则假设 当前数字 $num$ 为 众数 $x$ ；
   2. 当 $num = x$ 时，票数 $votes$ 自增 $1$ ；否则，票数 $votes$ 自减 $1$ 。
3. **返回值：** 返回 众数 $x$ 即可。

<![Picture2.png](https://pic.leetcode-cn.com/a7fd4153096147cd64bcfc014f20b87435a34612ed23ef763089cf1b51bf1033-Picture2.png),![Picture3.png](https://pic.leetcode-cn.com/43989b91950426081c82a83a979c11ec5597ae229627b61ec86db0730a72bf3a-Picture3.png),![Picture4.png](https://pic.leetcode-cn.com/10a7c7e1721833527e2472ef4b7e8745d1ccec1e688a4cfedfec0858b3df3bf7-Picture4.png),![Picture5.png](https://pic.leetcode-cn.com/89cd64ebb5ee60fdc4dd7bdb46c707799c5ff872ff4dc670b0715a6f292fce3d-Picture5.png),![Picture6.png](https://pic.leetcode-cn.com/5de836bfc4f5fb4bcc39110690158e2df239962ea2beec048442d99b88c19263-Picture6.png),![Picture7.png](https://pic.leetcode-cn.com/6f83e7ae7376b626418600dd3ab379c5349639811feb96a6aa9d84c9e224b1d9-Picture7.png),![Picture8.png](https://pic.leetcode-cn.com/fffc11770cf95ee793c5f41ab3dda4949c0e0c689b3bfd27af285e001dcff332-Picture8.png),![Picture9.png](https://pic.leetcode-cn.com/bd505f86741a95260a4804b095146bee33cbd447983f78c7ba5208cfa0651dbb-Picture9.png),![Picture10.png](https://pic.leetcode-cn.com/9d91dd6a308cf607a59d196e908ad4aa5cc3a31b063b1968c2add07c1c7bcb99-Picture10.png),![Picture11.png](https://pic.leetcode-cn.com/e6ce6206da0d14c03789e3ec6b3be67c66cae262227248fe6defd0b6b207599b-Picture11.png),![Picture12.png](https://pic.leetcode-cn.com/14575dfb9a270121be103a2ca60dd34fc3baab79ded3801a4e76d786268b9eb9-Picture12.png),![Picture13.png](https://pic.leetcode-cn.com/f05cde39ac1d9f25780b25556a52968a3246efcd3b5d775d477306c5addc62ea-Picture13.png),![Picture14.png](https://pic.leetcode-cn.com/a357210441735a9b6fda143b5e7ce02156786e241ca50b4384d2572b00b7f0ea-Picture14.png),![Picture15.png](https://pic.leetcode-cn.com/b335a7bb2acb982c3a5ab9eb02bc421b15a1bc72816af2156d912957de921074-Picture15.png)>

##### 复杂度分析：

- **时间复杂度 $O(N)$ ：** $N$ 为数组 `nums` 长度。
- **空间复杂度 $O(1)$ ：** $votes$ 变量使用常数大小的额外空间。

##### 代码：

```python []
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        votes = 0
        for num in nums:
            if votes == 0: x = num
            votes += 1 if num == x else -1
        return x
```

```java []
class Solution {
    public int majorityElement(int[] nums) {
        int x = 0, votes = 0;
        for(int num : nums){
            if(votes == 0) x = num;
            votes += num == x ? 1 : -1;
        }
        return x;
    }
}
```

##### 题目拓展：

- 由于题目明确给定 `给定的数组总是存在多数元素` ，因此本题不用考虑 **数组中不存在众数** 的情况。
- 若考虑，则需要加入一个 “验证环节” ，遍历数组 `nums` 统计 $x$ 的数量。
  - 若 $x$ 的数量超过数组长度一半，则返回 $x$ ；
  - 否则，返回 $0$ （这里根据不同题目的要求而定）。
- 时间复杂度仍为 $O(N)$ ，空间复杂度仍为 $O(1)$ 。

```python []
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        votes, count = 0, 0
        for num in nums:
            if votes == 0: x = num
            votes += 1 if num == x else -1
        # 验证 x 是否为众数
        for num in nums:
            if num == x: count += 1
        return x if count > len(nums) // 2 else 0 # 当无众数时返回 0
```

```java []
class Solution {
    public int majorityElement(int[] nums) {
        int x = 0, votes = 0, count = 0;
        for(int num : nums){
            if(votes == 0) x = num;
            votes += num == x ? 1 : -1;
        }
        // 验证 x 是否为众数
        for(int num : nums)
            if(num == x) count++;
        return count > nums.length / 2 ? x : 0; // 当无众数时返回 0
    }
}
```