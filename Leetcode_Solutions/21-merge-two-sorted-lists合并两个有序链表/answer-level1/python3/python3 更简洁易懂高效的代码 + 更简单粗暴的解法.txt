### 方法1--更简单粗暴的解法：

看到这题，为何大家思路都是指针遍历？把节点都存入列表，按val排序此列表，然后新建节点按序存入此列表，这才是最简单粗暴的思路吧：
```
class ListNode:
    def __init__(self, x, y):
        self.val = x
        self.next = y

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        visited = [] ## 建立缓存所有节点的列表
        while l1:
            visited.append(l1)
            l1 = l1.next
        while l2:
            visited.append(l2)
            l2 = l2.next
        visited.sort(key=lambda x:x.val) ## 存完全部节点后，按节点val排序
        rst = None ## 新建结果节点，将列表节点存入此结果
        while visited:
            rst = ListNode(visited.pop().val,rst)
        return rst

```
这样时间复杂度O((m+n)log(m+n))，空间复杂度O(m+n)，感觉也不是很差。

### 方法2--更简洁易懂高效的代码：

新建节点rst及其指针p，`l1`和`l2`哪个小，`p.next`就指向谁，并把这个最小的next到下一个节点，再比较大小，更新`p.next`....这也算是双指针吧：
```
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        p = rst =ListNode(None) ## 新建节点和指针
        while True:
            try:
                while l1.val<=l2.val: ## 若l1更小，`p.next`就指向l1,同时更新l1，p节点
                    p.next = l1
                    l1, p = l1.next, p.next
                while l1.val>l2.val:  ## 若l2更小，`p.next`就指向l2,同时更新l2，p节点
                    p.next = l2
                    l2, p = l2.next, p.next
            except:break ## 发生异常时，一定l1/l2至少一个为None了
        p.next = l1 or l2 ## 接上不为None的节点
        return rst.next ##返回新建指针
```
值得一提的是，上述代码效果如下：
**执行用时 :40 ms, 在所有 python3 提交中击败了98.64%的用户**  
**内存消耗 :13.8 MB, 在所有 python3 提交中击败了5.66%的用户**  

### 总结一下：

链表类的题目的解题工具，就是(**新建链表**or**修改原链表**)跟(**给原链表上指针**or**给新链表上指针**)的排列组合。
另外，将节点存入列表，操作列表，生成新建链表并返回，几乎通杀全部返回新链表类题目。