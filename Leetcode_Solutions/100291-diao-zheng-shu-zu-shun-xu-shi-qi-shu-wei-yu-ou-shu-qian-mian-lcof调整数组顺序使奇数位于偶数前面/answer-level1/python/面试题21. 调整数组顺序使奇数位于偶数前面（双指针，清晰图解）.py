#### 解题思路：

- 考虑定义双指针 $i$ , $j$ 分列数组左右两端，循环执行：
    1. 指针 $i$ 从左向右寻找偶数；
    2. 指针 $j$ 从右向左寻找奇数；
    3. 将 偶数 $nums[i]$ 和 奇数 $nums[j]$ 交换。
- 可始终保证： 指针 $i$ 左边都是奇数，指针 $j$ 右边都是偶数 。

![Picture14.png](https://pic.leetcode-cn.com/680e6995a4694caf6edf3e2cd7e1cc27a406994db5cb6f3072c49340a85c782d-Picture14.png){:width=450}

##### 算法流程：

1. **初始化：** $i$ , $j$ 双指针，分别指向数组 $nums$ 左右两端；
2. **循环交换：** 当 $i = j$ 时跳出；
   1. 指针 $i$ 遇到奇数则执行 $i = i + 1$ 跳过，直到找到偶数；
   2. 指针 $j$ 遇到偶数则执行 $j = j - 1$ 跳过，直到找到奇数；
   3. 交换 $nums[i]$ 和 $nums[j]$ 值；
3. **返回值：** 返回已修改的 $nums$ 数组。

<![Picture1.png](https://pic.leetcode-cn.com/1a09c5f4e0b2fab80afb3324a0456e893f114f5cf0e259b77345b882b2749ce5-Picture1.png),![Picture2.png](https://pic.leetcode-cn.com/128b130e87affaf2026d2e6775a4d2db483c421672ec94c870eca8b5058c864a-Picture2.png),![Picture3.png](https://pic.leetcode-cn.com/a58c72bee3c5fce1a1c7c8b13de566431e32968caca160019c48c82d39c37c91-Picture3.png),![Picture4.png](https://pic.leetcode-cn.com/4d5a5ebebab6e28f2501ffa3e080a7cfc59113d6e778d1ed000e5c843ae55f78-Picture4.png),![Picture5.png](https://pic.leetcode-cn.com/6fc453aeab27e5e3d8b1b18dee91df35ac7d6902a56ac57c1bf788455c6bbf66-Picture5.png),![Picture6.png](https://pic.leetcode-cn.com/670e91bbab4114e3cb5b0ce4e21e7f7359750698162609b4d1e8b91e1be3f50f-Picture6.png),![Picture7.png](https://pic.leetcode-cn.com/6886f4a728367ba8c0bb4cc5b0f45b7ea7743b3a324c994d6c6165d2c48cce97-Picture7.png),![Picture8.png](https://pic.leetcode-cn.com/9396c35328a181faf482959457151322f02a861dcd504f3cbc3eb74a2cc5bce6-Picture8.png),![Picture9.png](https://pic.leetcode-cn.com/93636dfb3f4ad03be1913681f569e2eecbf500fe3a677a07064a2a247e41a468-Picture9.png),![Picture10.png](https://pic.leetcode-cn.com/c553e9164931b0ebdc17ce57ca5b6384d97b9fa2768e5352fe831c1ec3e1caea-Picture10.png),![Picture11.png](https://pic.leetcode-cn.com/a76fd5db0614592657655fbd539ca4856f5ac743369c4784474986e95213feb9-Picture11.png),![Picture12.png](https://pic.leetcode-cn.com/003f1034c657c9b4d1f315c245ba0701c389a3469f2c29fac6ec7a9b7f668d4d-Picture12.png),![Picture13.png](https://pic.leetcode-cn.com/e6db3771afdf7c0097259730b97de32a2d47a55b8b62cdaeb24b685f571b4827-Picture13.png)>

##### 复杂度分析：

- **时间复杂度 $O(N)$ ：** $N$ 为数组 $nums$ 长度，双指针 $i$, $j$ 共同遍历整个数组。
- **空间复杂度 $O(1)$ ：** 双指针 $i$, $j$ 使用常数大小的额外空间。

#### 代码：

> $x \& 1$ 位运算 等价于 $x \% 2$ 取余运算，即皆可用于判断数字奇偶性。

```python []
class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        i, j = 0, len(nums) - 1
        while i < j:
            while i < j and nums[i] & 1 == 1: i += 1
            while i < j and nums[j] & 1 == 0: j -= 1
            nums[i], nums[j] = nums[j], nums[i]
        return nums
```

```java []
class Solution {
    public int[] exchange(int[] nums) {
        int i = 0, j = nums.length - 1, tmp;
        while(i < j) {
            while(i < j && (nums[i] & 1) == 1) i++;
            while(i < j && (nums[j] & 1) == 0) j--;
            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
        return nums;
    }
}
```