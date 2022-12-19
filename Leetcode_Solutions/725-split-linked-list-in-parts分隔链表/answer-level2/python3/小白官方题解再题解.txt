```
'''
LeetCode 725. 分隔链表
Given a (singly) linked list with head node root,
write a function to split the linked list into k consecutive linked list "parts".
The length of each part should be as equal as possible:
no two parts should have a size differing by more than 1. This may lead to some parts being null.
The parts should be in order of occurrence in the input list,
and parts occurring earlier should always have a size greater than or equal parts occurring later.
Return a List of ListNode's representing the linked list parts that are formed.
Examples 1->2->3->4, k = 5 // 5 equal parts [ [1], [2], [3], [4], null ]
Example 1:
Input:
root = [1, 2, 3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The input and each element of the output are ListNodes, not arrays.
For example, the input root has root.val = 1, root.next.val = 2, root.next.next.val = 3, and root.next.next.next = null.
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but it's string representation as a ListNode is [].
Example 2:
Input:
root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
Output: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1,
and earlier parts are a larger size than the later parts.
Note:
The length of root will be in the range [0, 1000].
Each value of a node in the input will be an integer in the range [0, 999].
k will be an integer in the range [1, 50].

题目大意：
给定一个头结点为 root 的链表, 编写一个函数以将链表分隔为 k 个连续的部分。
每部分的长度应该尽可能的相等: 任意两部分的长度差距不能超过 1，也就是说可能有些部分为 null。
这k个部分应该按照在链表中出现的顺序进行输出，并且排在前面的部分的长度应该大于或等于后面的长度。
返回一个符合上述规则的链表的列表。
举例： 1->2->3->4, k = 5 // 5 结果 [ [1], [2], [3], [4], null ]
示例 1：
输入:
root = [1, 2, 3], k = 5
输出: [[1],[2],[3],[],[]]
解释:
输入输出各部分都应该是链表，而不是数组。
例如, 输入的结点 root 的 val= 1, root.next.val = 2, root.next.next.val = 3, 且 root.next.next.next = null。
第一个输出 output[0] 是 output[0].val = 1, output[0].next = null。
最后一个元素 output[4] 为 null, 它代表了最后一个部分为空链表。
示例 2：
输入:
root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
输出: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
解释:
输入被分成了几个连续的部分，并且每部分的长度相差不超过1.前面部分的长度大于等于后面部分的长度。
提示:
root 的长度范围： [0, 1000].
输入的每个节点的大小范围：[0, 999].
k 的取值范围： [1, 50].

解题思路：
分割链表，两种方法，一种创建新链表，另外一种肯定是拆分
方法1：
1，如果链表有N个结点，则分隔的链表中每个部分中都有 n/k 个结点，且前 N%k部分有一个额外的结点，你用例子想一下即可
2，现在对于每个部分，我们已经计算出该部分有多少个节点：width + (i < remainder ? 1 : 0)。我们创建一个新列表并将该部分写入该列表。
class Solution(object):
    def splitListToParts(self, root, k):
        cur = root
        for N in range(1001): # root 的长度范围： [0, 1000]. # 也可以这样求链表长
            if not cur:
                break
            cur = cur.next
        width, remainder = divmod(N, k) # width是每一段的长度，remain是最后一段可能有剩余

        ans = []
        cur = root
        for i in range(k): # k部分
            head = write = ListNode(0) # 哑节点，这里为什么要head还要right，因为只有head的话，你head指针一直在移动
            # 要返回头你就找不到了，也可以理解为head是临时保存头节点，write是写链表的指针
            for j in range(width + (i < remainder)):
                write.next = write = ListNode(cur.val)
                if cur:
                    cur = cur.next
            ans.append(head.next)
        return ans
方法2：优化方法1
在方法 1 中，我们知道每个部分的大小。我们将不创建新列表，而是直接拆分原链表，并根据需要返回指向原始链表中节点的指针列表。
看代码
'''
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def splitListToParts(self, root, k):
        cur = root
        for N in range(1001):
            if not cur:
                break
            cur = cur.next
        width, remainder = divmod(N, k)

        ans = []
        cur = root
        for i in range(k):
            head = cur # 这里head是每一分割块的链表的头
            for j in range(width + (i < remainder) - 1):
                if cur:
                    cur = cur.next # 这里原来是创建新链表，我们只需要找到合适的指针位置即可
            if cur:
                tmp = cur.next
                cur.next = None # 掐断链表，好返回当前head
                cur = tmp # 便于下一次分割，定义cur为即将要分割的头节点
            ans.append(head)
        return ans

def generateList(l: list) -> ListNode: #这是为了打印结果，写的生成链表的函数，传入列表list即可
    prenode = ListNode(0) #哑节点
    lastnode = prenode
    for val in l: #遍历传入的列表
        lastnode.next = ListNode(val) #不断创建新节点，并链接
        lastnode = lastnode.next #指针后移，不移动的话就是还在原位置后面创新新节点了
    return prenode.next # 别把哑巴节点返回了啊

def printList(l: ListNode):  #打印链表函数，传入的是链表哦
    while l:
        print("%d" %(l.val), end = '->')
        l = l.next
    print('NULL')

if __name__ == "__main__":
    l1 = generateList([1,2,3,4,5,6,7,8,9,10])
    k = 3
    printList(l1)
    s = Solution()
    out = s.splitListToParts(l1, k)
    for i in range(k):
        printList(out[i])
```
