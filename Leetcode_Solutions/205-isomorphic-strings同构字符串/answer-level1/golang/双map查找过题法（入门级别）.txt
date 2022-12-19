### 解题思路
既然是匹配的题目，那我们还是map大法好了，我们设计两个map分别对应两个字符串。不得不说，古人这种对称美学的思想还是有点东西的，我第一次WA竟然是因为没考虑到下面t对s的不匹配。

所以具体的思路呢，根据长度遍历字符串，如果出现了某个曾经出现的字符，就去mapmap里面看看是否和之前统计的一样，如果一样就不管了，如果不一样，那就直接return false！

时间复杂度据我分析应该是O(n)，毕竟map的查找复杂度是O(1)。空间开了俩map所以占用比较高orz

### 代码

```golang
func isIsomorphic(s string, t string) bool {
    if len(s) != len(t){
        return false
    }
    map1 := make(map[string]string)
    map2 := make(map[string]string)
    for i:=0;i<len(s);i++{
        if val, ok := map1[s[i:i+1]]; ok {
            if val != t[i:i+1]{
                return false
            }
        }else if val, ok := map2[t[i:i+1]]; ok{
            if val != s[i:i+1]{
                return false
            }
        } else{
            map1[s[i:i+1]]=t[i:i+1]
            map2[t[i:i+1]]=s[i:i+1]
        }
    }
    return true
}
```