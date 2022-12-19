### 解题思路
此处撰写解题思路

### 代码

```golang
func minimumLengthEncoding(words []string) int {
    suffix := map[string]bool{}
    sort.Sort(ByLength(words))
    res := 0
    for _,i := range words{
        if _,ok:=suffix[i];ok{
            continue
        }else{
            res += len(i)+1
        }
        for j := 0 ; j < len(i)-1;j++{
            suffix[i[j:]] = true
        }
    }
    return res
}

type ByLength []string

func (p ByLength) Len() int {
	return len(p)
}
func (p ByLength) Less(i, j int) bool {
	return len(p[i]) > len(p[j])
}
func (p ByLength) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}
```