看了题目后，老样子最后一个要求后面再实现

## 方法1：暴力破解

那我最初的思路目测就是遍历这两个链表了，遍历第一个链表的时候把这个链表的id保存到一个列表里面，然后遍历第二个链表的时候去判断当前的id在不在之前的id列表里面（我可真是个小天才，滑稽）

于是有了下面的代码（超时）

```python
class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        id_list = []
        while headA:
            id_list.append(id(headA))
            headA = headA.next
        while headB:
            if id(headB) in id_list: return headB
            headB = headB.next
        return None
```

运行结果

```
43 / 45 个通过测试用例
	状态：超出时间限制
44号测试用例 58904 more char
```

卧槽无情，我每次以为一定会通过的时候总是这么多灾多难。难受，自闭了。

就在我难受的时候我突然又想到了set，之前经过测试set的判断要比list快很多，于是改成set

```python
class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        id_set = set()
        while headA:
            id_set.add(id(headA))
            headA = headA.next
        while headB:
            if id(headB) in id_set: return headB
            headB = headB.next
        return None
```

运行结果

```
执行用时 :220 ms, 在所有 Python3 提交中击败了28.23% 的用户
内存消耗 :29.5 MB, 在所有 Python3 提交中击败了5.13%的用户

执行用时 :292 ms, 在所有 Python3 提交中击败了6.54% 的用户
内存消耗 :29.3 MB, 在所有 Python3 提交中击败了5.13%的用户

执行用时 :208 ms, 在所有 Python3 提交中击败了32.66% 的用户
内存消耗 :29.2 MB, 在所有 Python3 提交中击败了5.13%的用户
```

果然用set就通过了测试，告诉自己，下次再遇到这种类似的思路，千万别用list！千万别用list！！千万别用list！！！

那现在就是实现题目的最后一条要求 O(*n*) 时间复杂度，且仅用 O(*1*) 内存。

## 方法2：双指针

先估摸分析一下，这由于是链表，所以肯定是要遍历的（毕竟如果你不遍历都不知道下一位是什么），那在有交叉的情况下最少的遍历时什么呢？当是是比较长的那个链表，也就是说我至少要遍历都较长结点到交点的次数才行。想到头秃我都没想出有什么办法，果断求助一下官方

我的天，又是双指针，而且又是指针相遇，感觉好像之前的141，142题啊。看了一下大概懂了，但是说时候我很难想到把一个原本属于a或者属于b的指针指到b或者a这种骚操作啊！

然后看了官方解答底下的评论，我的天，各位大佬真是太有才了！！！特别是这位大佬 [Wang_qa](https://leetcode-cn.com/u/wang_qa/) 的

```
我来到 你的城市
走过你来时的路
```

佩服佩服

下面的代码也是从 [Krahets](https://leetcode-cn.com/u/jyd/) 大佬的[代码](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/solution/intersection-of-two-linked-lists-shuang-zhi-zhen-l/)这边直接拿过来了

```python
class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        ha, hb = headA, headB
        while ha != hb:
            ha = ha.next if ha else headB
            hb = hb.next if hb else headA
        return ha
```

运行结果

```
执行用时 :256 ms, 在所有 Python3 提交中击败了16.27% 的用户
内存消耗 :28.5 MB, 在所有 Python3 提交中击败了7.91%的用户

执行用时 :176 ms, 在所有 Python3 提交中击败了64.35% 的用户
内存消耗 :28.7 MB, 在所有 Python3 提交中击败了6.30%的用户

执行用时 :224 ms, 在所有 Python3 提交中击败了26.81% 的用户
内存消耗 :28.9 MB, 在所有 Python3 提交中击败了5.86%的用户
```

欢迎来github上看更多题目的解答[力扣解题思路](https://github.com/WRAllen/LeetCode)

  