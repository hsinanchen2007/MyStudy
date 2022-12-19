### 解题思路
计算机负数用的补码表示, 所以在做位移的时候, 右移负数, 最左边并不是补0 ,而是补1, 这样很混乱不好理解
所以最简单的思路, 就是用一个flag=1, 然后分别去检查原来的数字n的各个位是不是有1, 这样可以不用改动n, 也不用考虑n是否是负数.

### 代码

```swift
class Solution {
    // 考虑负数的解法
    func hammingWeight(_ n: Int) -> Int {
        // 这道题如果考虑负数的话, 就不能去移动n了, 应该设置一个flag=1, 然后flag每次都向左移动去检查原数字有多少个1
        var flag = 1
        
        var count = 0
        
        while flag > 0 {
            if flag & n > 0 {
                count = count + 1
            }
            flag = flag << 1
        }
        
        // flag符号位为1时, 还需要再和n比较一次, 得到n的符号位是否为1 (符号位为1的, 表示负数, 所以小于0)
        if flag & n < 0 {
            count = count + 1
        }
        
        return count
    }
}
```