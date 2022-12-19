
这题肯定是不能真的如题目所说，先处理第一个字符再处理第二个字符，这样会有很多重复的计算。其实我们反过来看，从字符串的末尾开始，只操作一次，倒数第二个元素操作2次，直到第1个元素操作字符串长度n次。所以我们的循环应该从后往前遍历。

而shifts数组记录的是位移的次数，同样我们也是从数组的末尾往数组头开始处理，shifts[i]的值应该是shifts[i+1]+shifts[i]，这样可以得到总位移次数。这个次数也是可以优化的，每位移26次即回到原位，所以shifts[i]的值可以这样改。

    shifts[i] = (shifts[i]+shifts[i+1]) % 26
    
在循环之前往shifts末尾添加多一个元素，值为0，这样好处理shifts最后一个数组的赋值。

    shifts = append(shifts, 0)

```
func shiftingLetters(S string, shifts []int) string {
    s := []byte(S)
    shifts = append(shifts, 0)
    for i := len(s)-1; i >= 0; i-- {
        shifts[i] = (shifts[i]+shifts[i+1]) % 26
        s[i] = 'a' + (s[i] - 'a' + byte(shifts[i])) % 26
    }
    return string(s)
}

```