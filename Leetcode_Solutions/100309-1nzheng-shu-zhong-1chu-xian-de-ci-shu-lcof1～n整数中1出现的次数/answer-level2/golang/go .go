```golang
func countDigitOne(n int) int {
    if n == 0 {
        return 0
    }
    digit := []int{}
    for n != 0 {
        digit =append(digit, n % 10)
        n /= 10
    }
    res := 0
    for i := len(digit) - 1; i >= 0; i -- {
        left , right , t := 0, 0, 1
        for j := len(digit) - 1; j > i; j -- {
            left = left * 10 + digit[j]
        } 
        for j := i - 1; j >= 0; j-- {
            right = right * 10 + digit[j]
            t *= 10
        }
        res += left * t;
        if digit[i] == 1 {
            res += right + 1
        } else if digit[i] > 1{
            res += t
        }
    }
    return res;
}
```