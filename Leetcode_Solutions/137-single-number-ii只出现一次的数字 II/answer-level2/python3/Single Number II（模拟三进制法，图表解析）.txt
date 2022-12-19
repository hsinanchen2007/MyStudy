#### 解题思路：

- **二进制下不考虑进位的加法**：本题为 [136. Single Number](https://leetcode-cn.com/problems/single-number/solution/single-number-xor-by-jin407891080/) 的拓展，136 题中我们用到了异或运算。实际上，异或运算的含义是二进制下不考虑进位的加法，即：$0 xor 0=0+0=0$, $0 xor 1=0+1=1$, $1 xor 0=1+0=1$, $1 xor 1=1+1=0$（不进位）。
- **三进制下不考虑进位的加法**：通过定义某种运算 $#$，使得 $0 # 1 = 1$，$1 # 1 = 2$，$2 # 1 = 0$。在此运算规则下，出现了 $3$ 次的数字的二进制所有位全部抵消为 $0$，而留下只出现 $1$ 次的数字二进制对应位为 $1$。因此，在此运算规则下将整个 `arr` 中数字遍历加和，留下来的结果则为只出现 $1$ 次的数字。
- **代码分析：** 请结合代码注释和图表理解。
  - `ones ^= num`：记录至目前元素`num`，二进制某位出现 $1$ 次（当某位出现 $3$ 次时有 $ones = 1$ ，与 $twos = 1$ 共同表示“出现 $3$ 次”）；
  - `twos |= ones & num`：记录至目前元素`num`，二进制某位出现 $2$ 次 （当某位出现 $2$ 次时，$twos = 1$ 且 $ones = 0$ ）；
  - `threes = ones & twos`：记录至目前元素`num`，二进制某位出现 $3$ 次（即当 $ones$ 和 $twos$ 对应位同时为 $1$ 时 $three = 1$ ）。
  - `one &= ~threes`, `two &= ~threes`：将 $ones$, $twos$ 中出现了 $3$ 次的对应位清零，实现 “不考虑进位的三进制加法” 。
- **复杂度分析：**
    - 时间复杂度 $O(N)$：遍历一遍 `nums` 需要线性时间复杂度；
    - 空间复杂度 $O(1)$：使用常数额外空间。

<![Picture1.png](https://pic.leetcode-cn.com/692ea5a3c41665eb227ee9a5004d9401d45ab5a68bd696d48f4635f13c01ee06-Picture1.png),![Picture2.png](https://pic.leetcode-cn.com/31442dd7264f87ad1d9812b34932db659497dddee615c6a19130ccaa56f366bc-Picture2.png),![Picture3.png](https://pic.leetcode-cn.com/93f579277878922bc661f6958864dfaf9b386c7ac25a99fb022832cb5d712776-Picture3.png),![Picture4.png](https://pic.leetcode-cn.com/d1f09d5cfa1c0b6f85e719bba2455f8c6a6d96bba48c94ecded5b36da5ee256f-Picture4.png),![Picture5.png](https://pic.leetcode-cn.com/0e5f5903a24d757a1c15e9dc49fad0780a4a3d71eb7c4a668d40ee8be0de9c77-Picture5.png)>

```Python []
class Solution:
    def singleNumber(self, nums: [int]) -> int:
        ones, twos, threes = 0, 0, 0
        for num in nums:
            twos |= ones & num # 二进制某位出现1次时twos = 0，出现2, 3次时twos = 1；
            ones ^= num  # 二进制某位出现2次时ones = 0，出现1, 3次时ones = 1；
            threes = ones & twos # 二进制某位出现3次时（即twos = ones = 1时）three = 1，其余即出现1, 2次时three = 0；
            ones &= ~threes # 将二进制下出现3次的位置零，实现`三进制下不考虑进位的加法`；
            twos &= ~threes
        return ones
```

```Java []
class Solution {
    public int singleNumber(int[] nums) {
        int ones = 0, twos = 0, threes = 0;
        for(int num : nums){
            twos |= ones & num;
            ones ^= num;
            threes = ones & twos;
            ones &= ~threes;
            twos &= ~threes;
        }
        return ones;
    }
}
```

---

#### 进一步简化：

- 以上过程本质上是通过构建 $3$ 个变量的状态转换表来表示对应位的出现次数：使所有数字“相加”后出现 $3N+1$ 次的位 $ones = 1$，出现 $3N，3N+2$ 次的位为 $ones = 0$。由于 $three$ 其实是 `ones & twos` 的结果，因此我们可以舍弃 $threes$，仅使用 $ones$ 和 $twos$ 来记录出现次数。

| 某位出现   | 1次   | 2次   | 3次   | 4次   | 5次   | 6次   | ... |
| ---------- | ----- | ----- | ----- | ----- | ----- | ----- | --- |
| ones       | 1     | 0     | 0     | 1     | 0     | 0     | ... |
| twos       | 0     | 1     | 0     | 0     | 1     | 0     | ... |
| ~~threes~~ | ~~0~~ | ~~0~~ | ~~1~~ | ~~0~~ | ~~0~~ | ~~1~~ | ... |

- **代码分析：**
    - `ones = ones ^ num & ~twos`：
        - 当 $num = 1$ 时，只当 $ones = twos = 0$ 时将 $ones$ 置 $1$，代表出现 $3N+1$ 次；其余置 $0$，根据 $twos$ 值分别代表出现 $3N$ 次和 $3N+2$ 次；
        - 当 $num = 0$ 时，$ones$ 不变；
    - `twos = twos ^ num & ~ones`：
        - 当 $num = 1$ 时，只当 $ones = twos = 0$ 时将 $twos$ 置 $1$，代表出现 $3N+2$ 次；其余置 $0$，根据 $ones$ 值分别代表出现 $3N$ 次和 $3N+1$ 次。
        - 当 $num = 0$ 时，$twos$ 不变。

<![Picture11.png](https://pic.leetcode-cn.com/ec4d9cb6c5dc7cd56e2ca43fc778e3d63b26ae73d4deed5d282b745a90d11a29-Picture11.png),![Picture12.png](https://pic.leetcode-cn.com/3bc5bb016144a9b333cb8ad6d06265b9ec85977dfd0b4f6259408598245674e8-Picture12.png),![Picture13.png](https://pic.leetcode-cn.com/c68b1b2ded57f9a8a7e3bc2faa8bb2b434047e1be80b9d2c78b1ad0b08934be2-Picture13.png),![Picture14.png](https://pic.leetcode-cn.com/c8032b700a9b9523635f0e56b919286a0df3eef0cd0dda23ca58082895eb5449-Picture14.png),![Picture15.png](https://pic.leetcode-cn.com/0c279aa224f36fd29e039306b92e7733c8c9b7a655ec711ccef20bc353ea894a-Picture15.png),![Picture16.png](https://pic.leetcode-cn.com/63eb0f2c06f289701416eaee46a40ee56e4b685fff2b1c55ad16b00fadf3c8c8-Picture16.png)>

> 感谢评论区$angus123$的精彩代码分享。

```Python []
class Solution:
    def singleNumber(self, nums: [int]) -> int:
        ones, twos = 0, 0
        for num in nums:
            ones = ones ^ num & ~twos
            twos = twos ^ num & ~ones
        return ones
```

```Java []
class Solution {
    public int singleNumber(int[] nums) {
        int ones = 0, twos = 0;
        for(int num : nums){
            ones = ones ^ num & ~twos;
            twos = twos ^ num & ~ones;
        }
        return ones;
    }
}
```