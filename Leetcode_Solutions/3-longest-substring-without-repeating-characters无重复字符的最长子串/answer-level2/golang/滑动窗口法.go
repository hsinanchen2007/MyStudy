### 解题思路
利用go的map字典保存每个字符的最新位置(下标+1)，当遇到重复字符时， 更新子字符串的起始位置(l往后移动一个字符)，当字典中的位置大于l时。
然后更新当前字符的最新位置， 然后再更新最大子字符串的长度（(r+1)-l）



### 代码

```golang
func lengthOfLongestSubstring(s string) int {
    d := make(map[string]int)
    var l ,max int = 0,0
    for r, ch := range(s){
        if m_index,ok := d[string(ch)]; ok{
            if m_index > l{
                l = m_index //移动重复字符到下一个字符
            }
        }
        d[string(ch)] = r+1 //标记最新字符的位置下标+1
        if r-l+1 > max {//下标加1
            max = r-l+1//下标加1
        }
    }
    return max
}
```