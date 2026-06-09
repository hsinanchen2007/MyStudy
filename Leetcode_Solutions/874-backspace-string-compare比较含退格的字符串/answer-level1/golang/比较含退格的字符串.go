#### 思路

使用栈来做最方便了, 遍历字符串, 当发现字符串不为#时, 将字符插入数组中, 若为#时, 则删除栈中最末尾的元素, 删除时记得判栈空。

最后将两个处理好的字符串再做比较

#### code


```
func backspaceCompare(S string, T string) bool {
    list1, list2 := []byte{}, []byte{}
    for i := 0; i < len(S); i++ {
        if S[i] != '#' {
            list1 = append(list1, S[i])
        } else if len(list1) > 0 {
            list1 = list1[:len(list1)-1]
        }
    }
    for i := 0; i < len(T); i++ {
        if T[i] != '#' {
            list2 = append(list2, T[i])
        } else if len(list2) > 0 {
            list2 = list2[:len(list2)-1]
        }
    }
    return string(list1) == string(list2)
}
```