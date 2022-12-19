![image.png](https://pic.leetcode-cn.com/341d5e959c7546b265596f6f16bbbe810272f499a43ef17149c4ae50c03be581-image.png)

### 解题思路
递归

### 代码

```golang
import "strconv"
func countAndSay(n int) string {
    if n==1{
        return "1"
    }
    last := countAndSay(n-1)
    cur := string(last[0])
    idx := 0
    var buff bytes.Buffer
    for _,v := range last{
        if cur == string(v){
            idx++
            continue
        }
        buff.WriteString(strconv.Itoa(idx)+cur)
        cur = string(v)
        idx = 1
    }
    buff.WriteString(strconv.Itoa(idx)+cur)

    return buff.String()    
}
```