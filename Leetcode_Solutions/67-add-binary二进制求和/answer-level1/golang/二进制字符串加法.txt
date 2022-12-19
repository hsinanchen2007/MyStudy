### 解题思路
这个题目跟链表、数组的加法都是一样的，注意for循环的边界条件处理即可
### 代码

```golang
func addBinary(a string, b string) string {
    if len(a) == 0 {
        return b
    }
    if len(b) == 0 {
        return a
    }
    lastA, lastB := len(a)-1, len(b)-1

    //预分配内存，避免slice扩容带来的内存碎片
    max := len(a)
    if len(a) < len(b) {
        max = len(b)
    }
    var result []byte = make([]byte, 0, max+1)
    var carry int
    //只要字符串不为空或者进位不为0，都应该继续处理
    for lastA >= 0 || lastB >= 0 || carry > 0 {
        sum := carry
        if lastA >= 0 {
            sum = sum + int(a[lastA] - '0')
            lastA-- 
        }
        if lastB >= 0 {
            sum = sum + int(b[lastB] - '0')
            lastB--
        }
        carry = sum / 2
        result = append(result, byte(int('0') + sum%2))
    }
    reverse(result)
    return string(result)
}

func reverse(input []byte) {
    if input == nil || len(input) <= 1 {
        return
    }
    for i, j := 0, len(input)-1; i < j; i, j = i+1, j-1 {
        input[i], input[j] = input[j], input[i]
    }
}
```