### 解题思路
从后向前遍历两个字符串，进行模拟二进制加法.循环结束后需考虑最后的进位问题

### 代码

```golang
func addBinary(a string, b string) string {
    aMax := len(a)
    bMax := len(b)
    aBytes := []byte(a)
    bBytes := []byte(b)
    carry := 0
    result := ""
    for {
        aMax--
        bMax--
        if aMax >= 0 || bMax >=0 {
            aNum := 0
            bNum := 0
            if aMax >= 0 {
                aNum = int(aBytes[aMax]) - 0x30 
            }
            if bMax >=0 {
                bNum = int(bBytes[bMax]) - 0x30
            }
            sumNum := aNum + bNum + carry
            curNum := 0
            if  sumNum == 0 {
                carry = 0
                curNum = 0        
            }else if sumNum == 1 {
                carry = 0
                curNum = 1  
            }else if sumNum == 2 {
                carry = 1
                curNum = 0  
            }else if sumNum == 3 {
                carry = 1
                curNum = 1  
            }
            result =  strconv.Itoa(curNum) + result
        }else{
            break;
        }
    }
    // 考虑最后的进位问题
    if carry > 0 {
        result =  strconv.Itoa(carry) + result
    }
    return result
}
```