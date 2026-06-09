### 解题思路
此处撰写解题思路
##### 两个数组同索引的值相同，计数器++即可。
### 代码

```golang
func game(guess []int, answer []int) int {
    var n int
    for k,v :=range guess{
       if v == answer[k] {
           n++
       }
    }
    return n
}
```