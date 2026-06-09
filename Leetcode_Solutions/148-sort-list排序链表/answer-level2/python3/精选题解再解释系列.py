```
'''
LeetCode 148. 排序链表（看不懂得猛补归并排序）
Sort a linked list in O(n log n) time using constant space complexity.
Example 1:
Input: 4->2->1->3
Output: 1->2->3->4
Example 2:
Input: -1->5->3->4->0
Output: -1->0->3->4->5


题目大意：
在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
示例 1:
输入: 4->2->1->3
输出: 1->2->3->4
示例 2:
输入: -1->5->3->4->0
输出: -1->0->3->4->5

解题思路：
这道题比较难，因为有在 O(n log n) 时间复杂度和常数级空间复杂度下，时间复杂度和空间复杂度都有要求
前置知识点你要会排序，哎，十大排序算法是必须会的哦，https://www.runoob.com/python3/python-merge-sort.html
我给你总结下，归并排序实质就是不断二分数组，然后将这两块数组进行merge，即谁小谁先放入最终合并的辅助数组，空间复杂度不是常数级别哦。
方法1：归并排序-递归法-该方法不满足空间复杂度要求，下面有分析（写出来你也可以学习下，该方法也超级重要）
题目要求时间空间复杂度分别为O(nlogn)和O(1)，根据时间复杂度我们自然想到二分法，从而联想到归并排序；
对数组做归并排序的空间复杂度为 O(n)，分别由新开辟数组O(n)，和递归函数调用O(logn)组成，而根据链表特性：
1，数组额外空间：链表可以通过修改引用来更改节点顺序，无需像数组一样开辟额外空间；
2，递归额外空间：递归调用函数将带来O(logn)的空间复杂度，因此若希望达到O(1)空间复杂度，则不能使用递归。
通过递归实现链表归并排序，有以下两个环节：
1，分割 cut 环节
找到当前链表中点，并从中点将链表断开（以便在下次递归 cut 时，链表片段拥有正确边界）
我们使用 fast,slow 快慢双指针法，奇数个节点找到中点，偶数个节点找到中心左边的节点。（快慢指针找中点可以理解么，看代码，不理解留言）
找到中点 slow 后，执行 slow.next = None 将链表切断。
递归分割时，输入当前链表左端点 head 和中心节点 slow 的下一个节点 tmp(因为链表是从 slow 切断的)。
cut 递归终止条件： 当head.next == None时，说明只有一个节点了，直接返回此节点。
2，合并 merge 环节（将两个排序链表合并，转化为一个排序链表）
双指针法合并，建立辅助ListNode h 作为头部。
设置两指针 left, right 分别指向两链表头部，比较两指针处节点值大小，由小到大加入合并链表头部，指针交替前进，直至添加完两个链表。
返回辅助ListNode h 作为头部的下个节点 h.next。
时间复杂度 O(l + r)，l, r 分别代表两个链表长度。
特别的，当题目输入的 head == None 时，直接返回None。
class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        if not head or not head.next: return head # head为空返回head，只有一个节点，也直接返回即可
        slow, fast = head, head.next # 注意fast是head.next，为了实现，奇数个节点找到中点，偶数个节点找到中心左边的节点。
        while fast and fast.next:  # 找重点
            fast, slow = fast.next.next, slow.next # 此时奇数节点slow指向中间节点，偶数节点slow指向中心左边的节点，你画图模拟下
        mid, slow.next = slow.next, None # 保存然后，切断
        left, right = self.sortList(head), self.sortList(mid) # 递归切断，left是左链表，right是右链表
        h = res = ListNode(0) # 哑节点
        while left and right: # 递归合并
            if left.val < right.val:
                h.next = left
                left = left.next
            else:
                h.next = right
                right = right.next
            h = h.next
        h.next = left if left else right # 无论左边链表还是右边还有剩余，都加入到新链表
        return res.next
方法2：优化归并排序（从底至顶直接合并），不使用递归，迭代实现，也就是自己模拟递归的过程
对于非递归的归并排序，需要使用迭代的方式替换cut环节：
我们知道，cut环节本质上是通过二分法得到链表最小节点单元，再通过多轮合并得到排序结果。
每一轮合并merge操作针对的单元都有固定长度intv，例如：
第一轮合并时intv = 1，即将整个链表切分为多个长度为1的单元，并按顺序两两排序合并，合并完成的已排序单元长度为2。
第二轮合并时intv = 2，即将整个链表切分为多个长度为2的单元，并按顺序两两排序合并，合并完成已排序单元长度为4。
以此类推，直到单元长度intv >= 链表长度，代表已经排序完成。
根据以上推论，我们可以仅根据intv计算每个单元边界，并完成链表的每轮排序合并，例如:
当intv = 1时，将链表第1和第2节点排序合并，第3和第4节点排序合并，……。
当intv = 2时，将链表第1-2和第3-4节点排序合并，第5-6和第7-8节点排序合并，……。
当intv = 4时，将链表第1-4和第5-8节点排序合并，第9-12和第13-16节点排序合并，……。
算法步骤：你最好可以把每道题都这样总结下，有点类似翻译代码一样
模拟上述的多轮排序合并：
1，统计链表长度length，用于通过判断intv < length判定是否完成排序；
2，额外声明一个节点res，作为头部后面接整个链表，用于：
intv *= 2即切换到下一轮合并时，可通过res.next找到链表头部h；
执行排序合并时，需要一个辅助节点作为头部，而res则作为链表头部排序合并时的辅助头部pre
后面的合并排序可以将上次合并排序的尾部tail用做辅助节点。
3，在每轮intv下的合并流程：
a，根据intv找到合并单元1和单元2的头部h1, h2。由于链表长度可能不是2^n，需要考虑边界条件：
在找h2过程中，如果链表剩余元素个数少于intv，则无需合并环节，直接break，执行下一轮合并；
若h2存在，但以h2为头部的剩余元素个数少于intv，也执行合并环节，h2单元的长度为c2 = intv - i。
b，合并长度为c1, c2的h1, h2链表，其中：
合并完后，需要修改新的合并单元的尾部pre指针指向下一个合并单元头部h。（在寻找h1, h2环节中，h指针已经被移动到下一个单元头部）
合并单元尾部同时也作为下次合并的辅助头部pre。
c，当h == None，代表此轮intv合并完成，跳出。
4，每轮合并完成后将单元长度×2，切换到下轮合并：intv *= 2。
直接看代码吧
'''
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        h, length, intv = head, 0, 1
        while h:  # 求链表长度，用于通过判断intv < length判定是否完成排序；
            h = h.next
            length = length + 1
        res = ListNode(0) # 哑巴节点，用于返回结果
        res.next = head # 哑巴节点链接到head
        # 补充一句给你理解，记住每次迭代，送进来的都是一个链接起来的完整的链表，迭代归并与递归不同在于，没有栈来存储中间变量
        # 因此每次迭代，这个链表始终都是完整的，没有真正的切开，只是每intv个进行mergesort
        while intv < length: # 迭代merge sort，每intv个一组进行mergesort，直到intv不小于链表长了
            pre, h = res, res.next
            while h: # 当h == None，遍历到了最后，代表此轮intv合并完成，跳出。
                # 下面是找到左右两个链表的头，分别是h1 h2，其实就是每intv个进行不断迭代mergesort h1和h2
                h1, i = h, intv
                while i and h:
                    h = h.next
                    i = i - 1
                if i:
                    break  # 在遍历h1时候，已经不够了，那就是没有h2了，直接break，遍历h1其实是找h2，你细细品
                h2, i = h, intv
                while i and h:
                    h = h.next
                    i = i - 1 # 再遍历h2，其实是在找下一次的h1，细细品
                c1, c2 = intv, intv - i # 看前面介绍，是每intv个合并，前部分链表h1长度一定是intv个，后半部分h2为intv-i个
                # 这里前面c1 c2都是intv，只有最后一组会有特别！！！
                # 合并过程，都是一样的，和递归
                while c1 and c2:
                    if h1.val < h2.val:
                        pre.next = h1
                        h1 = h1.next
                        c1 = c1 - 1
                    else:
                        pre.next = h2
                        h2 = h2.next
                        c2 = c2 - 1
                    pre = pre.next
                pre.next = h1 if c1 else h2 # 有剩余，参照上面递归是一样的
                while c1 > 0 or c2 > 0: # 因为是迭代的，有剩余的情况此时只是链接到pre上，但上一句没变化pre下标，因此还需要后移动pre
                    pre = pre.next
                    c1 = c1 - 1
                    c2 = c2 - 1
                pre.next = h # 合并单元尾部同时也作为下次合并的辅助头部pre
            intv *= 2 # 下轮mergesort，二分法，由底向上所以是*2
        return res.next

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
    # e.g. 4->2->1->3
    l1 = generateList([4,2,1,3])
    printList(l1)
    s = Solution()
    l2 = s.sortList(l1)
    printList(l2)
```
