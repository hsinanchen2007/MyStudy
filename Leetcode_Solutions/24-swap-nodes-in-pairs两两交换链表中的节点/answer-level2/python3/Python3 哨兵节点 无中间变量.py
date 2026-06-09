本解类似这个[Go解法](https://leetcode-cn.com/problems/swap-nodes-in-pairs/solution/xian-xing-zhe-si-xiang-yi-xing-dai-ma-jie-ti-by-jo/)

**策略**
*使用哨兵简化了原头节点swap、无前序节点的麻烦
奇数情况末节点交给`while pre.next.next`判断
循环中，前驱节点`pre`可以导出需要变更的后继节点，所以使用驱前节点作为循环参数可以不引入其他变量。*

**思路**
循环体中利用python多变量赋值的特点：
1. 赋值前，右侧会预先解析并存储，相当于隐式的临时变量。
2. 赋值语句左侧，由左到右依次分别（解析`next`调用链并赋值）。为了规避`next`属性变更影响后继的赋值，可以让后继节点优先变更，顺序为：`pre.next.next.next, pre.next.next, pre.next`

**直观解法**
```python
class Solution:
  def swapPairs(self, head: ListNode) -> ListNode:
    guard, guard.next = ListNode(0), head
    pre = guard
    while pre.next and pre.next.next:
      pre.next.next.next, pre.next.next, pre.next = pre.next, pre.next.next.next, pre.next.next
      pre = pre.next.next
    return guard.next
```

**一行流（学习用，工程慎用）**
注意pre指向变更后的下下个节点
```python
class Solution:
  def swapPairs(self, head: ListNode) -> ListNode:
    head, _ = pre, pre.next = ListNode(0), head
    while pre.next and pre.next.next:
      pre.next.next.next, pre.next.next, pre.next, pre = pre.next, pre.next.next.next, pre.next.next, pre.next
    return head.next
```

**变换解法**
也可以顺着来，注意右侧是顺序不是`解一`的逆序，而是考虑了前序`next`值的变更。此时左侧的顺序完全是`变更后的顺序`。
```python
class Solution:
  def swapPairs(self, head: ListNode) -> ListNode:
    guard, guard.next = ListNode(0), head
    pre = guard
    while pre.next and pre.next.next:
      pre.next, pre.next.next, pre.next.next.next = pre.next.next, pre.next, pre.next.next.next
      pre = pre.next.next
    return guard.next
```
*拆解套娃辅助工具：左右侧表达式侧和节点的对应关系*
```
  等号左侧  pn=     pnn=    pnnn=
             1 ----> 2 ----> 3 ----> ?
  等号右侧    =p      =pn     =pnn    =pnnn

例：将3指向2
左侧：3对应pnnn=
右侧：2对应=pn
#=> p.next.next.next = p.next

例：将2指向?，3指向2
左侧：2对应pnn=，右侧：?对应=pnnn
左侧：3对应pnnn=，右侧：2对应=pn
为了规避变更传递，远端属性优先赋值更改
#=> p.next.next.next, p.next.next = p.next, p.next.next.next
```