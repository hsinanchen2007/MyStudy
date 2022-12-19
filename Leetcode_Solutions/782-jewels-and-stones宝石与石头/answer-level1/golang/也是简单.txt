### 解题思路
此处撰写解题思路

### 代码

```golang
func numJewelsInStones(J string, S string) int {
    count:=0
    for i:=0;i<len(S);i++{
        if strings.Contains(J,string(S[i])){
            count++
        }
    }
    return count
}
```