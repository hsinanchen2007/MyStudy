
遍历链表，设当前节点为p, 对前缀求和设为total，用字典dic记录上一个前缀和为total的节点。
每个节点有三种可能的情况：
1、total=0，直接删除当前节点之前的所有节点，更换头节点h=p.Next, 并清空dic；
2、dic[total] = nil 即之前的节点没有出现过前缀和为total的节点，直接dic[total] = p
3、dic[total] != nil, 删除从上次出现前缀和为total的节点的next节点到当前节点，同时需要将这些节点的前缀和在dic中置为nil
```
func removeZeroSumSublists(head *ListNode) *ListNode {
    dic := make(map[int]*ListNode) 
    h := head
    total := 0
    
    for p:=head; p != nil; p = p.Next {
        
        total += p.Val

        // 情况一
        if total == 0 {
            dic = make(map[int]*ListNode)
            h = p.Next
            continue
        }
        
        // 情况二
        if dic[total] == nil {
            dic[total] = p
            continue
        }
        
        // 情况三
        k := dic[total]
        t := total
        // 遍历的目的是为了清空要删除的这部分在dic中的记录
        for m:= k.Next; m != p; m = m.Next {
            t += m.Val
            dic[t] = nil
        }
        // 删除
        k.Next = p.Next        
    }
    return h
}
```
