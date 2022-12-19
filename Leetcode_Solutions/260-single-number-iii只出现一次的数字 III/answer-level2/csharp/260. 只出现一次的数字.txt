### 解题思路
    位运算
### 代码

```csharp
public class Solution {
    public int[] SingleNumber(int[] nums) {
            /* 异或 (^)：能够保留两个之间的差异，一个数字重复异或两次，相当于没有产生任何变化
             * 因此，出现了偶数次的数全部异或到结果上，不会产生任何影响，
             * 因此最后结果只保留了只出现一次的数据的差异，注意，不是直接记录了那两个数值
             */
            int result = 0;
            foreach (var val in nums)
                result ^= val;

            /* 取反 (~)：把字节所有比特位0或1反转
             * 与 (&)：比较比特位，同为1时为1，否则为0
             * 取负数 (-)：取反后加1，-x=~x+1
             * x & -x：用于保留最靠右的比特 1
             */
            var flag = result & -result;

            /* 此时 flag 里的 1 只能来自于一个出现单次的两个数中的一个
             * 可以通过这个 flag 将 nums 分组，通过继续和相同的组的数字异或，从而还原出两个出现单次的数中的一个
             */
            int x = 0;
            foreach (var val in nums)
                if ((val & flag) > 0)
                    x ^= val;

            /* 此时 x 已经是其中一个出现单次的数字
             * 可以通过与 result 异或，得到另一个数字
             */
            int y = result ^ x;
            return new[] { x, y };
    }
}
```