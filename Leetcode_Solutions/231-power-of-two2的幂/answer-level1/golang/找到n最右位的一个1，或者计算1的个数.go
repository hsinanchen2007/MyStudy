### 解题思路
此处撰写解题思路

### 代码

```golang
func isPowerOfTwo(n int) bool {
    if n == 0 {
        return false
    }
    // 最简单的一个实现，-n = ^n + 1就是n按位取反加上1，n&(-n)表示找到最后一位1，其他位都是0，如果等于n表示n只有一个1
    // 那么就是2的幂次方
    // return n & (-n) == n
    // 方法二
    // 找到n的最右边的1，如果此时n==1表示n只有一个1，那么就和方法一异曲同工了
    for n != 0 {
        if n % 2 == 0 {
            n = n >> 1
            continue
        }
        return n == 1
    }
    return false
}


```