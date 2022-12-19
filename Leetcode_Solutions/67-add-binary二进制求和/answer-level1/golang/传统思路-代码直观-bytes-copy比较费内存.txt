### 解题思路

`append([]byte{temp},ans...)`  非常浪费内存

### 代码

```golang
func addBinary(a string, b string) string {
    la :=len(a)
    lb := len(b)
    ans := []byte{}

    //ce 处理进位的问题
    ce := 0
    i:=la-1
    j:=lb-1
    //倒序遍历
    for i>=0 || j>=0 {
        //设置上一位的 进位值
        sum := ce
        sum += trans(i,a)
        sum += trans(j,b)

        //计算本位的值
        temp := byte( byte(sum%2)+'0')

        //插入元素到头部
        //**浪费内存**
        ans = append([]byte{temp},ans...)

        //计算本位的进位值
        ce = sum/2

        //移动指针
        i--
        j--
    }
    if ce > 0{
        ans = append([]byte{'1'},ans...)
    }
    return string(ans)
}

//a b 字符串长度不同,导致 i 可能位负
func trans(i int,s string)int{
    if i < 0 {
        return 0
    }else {
        return int( s[i]-'0')
    }
}

```