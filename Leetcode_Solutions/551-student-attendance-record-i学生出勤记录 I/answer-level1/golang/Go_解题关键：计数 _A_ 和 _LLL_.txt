解：同时满足以下两个条件，即可判定为 "TRUE";其他为 "FALSE"
1. "A" 出现次数小于等于 1
2. "LLL" 出现次数等于 0


```
    func checkRecord(s string) bool {
        if strings.Count(s,"A")<=1 && strings.Count(s,"LLL")==0{
            return true
        }
        return false
    }
```
