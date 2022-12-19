### 解题思路
此处撰写解题思路

### 代码

```golang
import "strings"
func countSegments(s string) int {

    str_list := strings.Split(s," ")
	count := 0
    for i:=0;i<len(str_list);i++ {
        if str_list[i]!=""{
            count++
        }

    }
    return count
}
```