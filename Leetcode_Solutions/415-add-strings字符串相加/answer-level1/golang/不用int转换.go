![image.png](https://pic.leetcode-cn.com/45675669927a06f80aae3ef25a1546459eb46cc40f48029808a1abebd00a26b3-image.png)

```
func addStrings(num1 string, num2 string) string {
    var i int = len(num1) - 1
    var j int = len(num2) - 1
    var r byte = 0
    var s = []byte{}
    for i >=0 || j >= 0 || r != 0{
        if i >= 0 {
            r += (num1[i] - '0')
            i--
        }
        if j >=0 {
            r += (num2[j] - '0')
            j--
        }
        
        s = append(s,((r % 10) + '0'))
        r /= 10
    }
    var n int = len(s)-1
    for i:=0; i<n; i++{
        s[i],s[n] = s[n],s[i]
        n--
    }
    
    return string(s)
}

```
