### 解题思路
每个数字每个位的 1 有或者没有
所以每个数字 做xor 操作 必然改变 某些位的 奇偶性
所以 对AB 总有 策略 可以保证 结果是 某个位是奇数个1的
所以 最终结果 是看 总数字数量的 奇偶性

### 代码

```csharp

class MinMaxXor{
    public bool XorGame(int[] nums) {
        // var init = new NumState();
        var n = 0;
        foreach(var nv in nums) n ^= nv;
        // init.xorValue = n;
        var initV = n;
        // init.nums.AddRange(nums);
        //alice 胜利
        // if(init.IsZero()) return true;
        if(initV == 0) return true;
        // 221 这种结构 只有必然拆奇数 才会导致失败  但是任意数字 只能位只能整体+1 -1
        //修改偶数 部分-》奇数 不为0  避免修改奇数部分 修改奇数部分可以 顺带修改偶数部分
        var mod = nums.Length % 2;
        if(mod == 1) return false;
        return true;
    }
}
public class Solution {
    public bool XorGame(int[] nums) {
        var mm = new MinMaxXor();
        return mm.XorGame(nums);
    }
}
```