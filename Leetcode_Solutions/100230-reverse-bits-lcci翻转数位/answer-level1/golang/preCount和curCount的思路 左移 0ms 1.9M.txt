### 解题思路
两个count，一个表示上一次1的个数，另一个表示这一次1的个数，循环中计数的时候遇到0就停下来，每次计数完毕以后将curCount赋给preCount，然后curCount置0，在下次循环重新开始计数。如果遇到连续的0的话preCount会等于0，这时候可以将后面连续的0全都清除，然后重新计数，这样会提高效率。     

**注意要用左移不能用右移**，因为右移是补符号位，左移是补零，右移如果输入负数的话就会出问题。但是估计是因为测试用例都是正数，右移也能通过。

### 代码

```golang
func reverseBits(num int) int {
    if num == 0 {
        return 1
    }
    // 注意要用左移不能用右移，因为右移是补符号位，如果输入负数的话就会出问题
    // 但是估计测试用例都是正数，右移也能通过
    preCount := 0
    curCount := 0
    result := 0
    for num != 0 {
        // preCount为0说明刚开始，或者遇到了连续2个0
        if preCount == 0 {
            for num != 0 && num&0x80000000 != 0x80000000 {
                num <<= 1
            }
        }
        for num&0x80000000 == 0x80000000 {
            curCount++
            num <<= 1
        } 
        if sum := preCount+curCount+1; sum>result {
            result = sum
        }
        preCount = curCount
        curCount = 0
        num <<= 1
    }
    return result
}
```