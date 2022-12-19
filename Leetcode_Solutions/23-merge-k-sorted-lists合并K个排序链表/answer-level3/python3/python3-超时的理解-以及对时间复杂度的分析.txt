注意超时的原因很可能是你用了之前2个链表排序一合并就排序的原因，这样子只要合并一个就执行一次排序 比 先合并后排序快很多，因为k个链表，当每个链表的长度都是1的时候，用头插法是最好的情况，合并的算法时间复杂度是O(N),但是在这最好的情况下，我们如果每合并两个就执行一次排序就会导致算法的时间复杂度是O(N^2). 下面是python的代码：
```
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        def add_2(l1=None,l2=None):
                if l2==None:
                    l2=l1
                    return l2
                else:
                    cur=l2
                    while(cur.next!=None):
                        cur=cur.next
                    cur.next=l1
                    return l2
        def travel(merge):
                cur=merge
                List=[]
                while (cur!=None):
                    List.append(cur.val)
                    cur=cur.next
                return List
        def merge_twoLists(l1,l2):
            def append(l1=None,l2=None):
                if l1==None:
                    l1=l2
                    return l1
                else:
                    cur=l1
                    while (cur.next!=None):
                        cur=cur.next
                    cur.next=l2
                    return l1
            l2= add_2(l1,l2)
            return l2
        length=(len(lists))
        l1=None
        for i in range(length):
            l2=lists[i]
            l1=merge_twoLists(l1,l2) #这个l1就是就是l2
        List_merge=travel(l1)
        List_merge.sort(reverse=True)
        l1=None
        for i in List_merge:
            node_i=ListNode(i)
            l1=add_2(l1,node_i)
        return l1
```
另外：头插法比尾插法省时的前提是插入的元素个数是1，如果插入的链表L2长度为n 比较大， 那么用头插法的时候，你得移动指针到L2的尾部，然后 L2.end.next=l1.head 这样才行。
本题最后的两个测试用例长度很长，而且每个链表的长度为1，所以为了巧妙的过测试用例，本人用了以下两点：
1.用头插法，头插法比尾插法的好处就在于，不管插入的链表很长还是很短，它的时间复杂度就号在了遍历上，一直要遍历到最后一个尾部。
2.先挨个合并之后再排序。不能套前面的2个排序链表的方法，先for一遍合并之后再排序，最坏的情况下：
每个链表的长度都为n，有n个链表，那么合并的时间复杂度是O(N^2),再排序一遍还是O(N^2)。 最好的情况下是每个链表的长度都为1，用头插法，有n个链表，那么合并的时间复杂度是O(N),排序后的时间复杂度是O(NlogN).