```
'''
LeetCode 142. 环形链表 II
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) 
in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.
Note: Do not modify the linked list.
Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example 2:
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
Example 3:
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.

题目大意：
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
说明：不允许修改给定的链表。
示例 1：
输入：head = [3,2,0,-4], pos = 1
输出：tail connects to node index 1
解释：链表中有一个环，其尾部连接到第二个节点。
示例 2：
输入：head = [1,2], pos = 0
输出：tail connects to node index 0
解释：链表中有一个环，其尾部连接到第一个节点。
示例 3：
输入：head = [1], pos = -1
输出：no cycle
解释：链表中没有环。

解题思路：
这道题和LeetCode 141.差不多，是141的前置题，区别在于141只需要返回是否有环，这道题要返回入环处的节点
也是两种方法
方法1：哈希set法，和141类似，使用一个visited set集合，如果发现当前node之前看过，返回即可，否则继续遍历把节点放入集合
class Solution(object):
    def detectCycle(self, head):
        visited = set()
        node = head
        while node is not None:
            if node in visited:
                return node
            else:
                visited.add(node)
                node = node.next
        return None
方法2：快慢指针法
算法：
step1：先让快慢指针一起走直到相遇
step2：固定快指针，慢指针从头开始，然后快慢指针一起走，再次相遇的地方就是入环处
这里面涉及到大量数学计算，是可以证明的，你感兴趣可以自己百度，我就不证明了，你直接背下来就可以，就是这样子求环
注意：面试答快慢指针法，因为该方法空间复杂度为线性的，cpp代码
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    	ListNode *fast = head;
    	ListNode *slow = head;
    	ListNode *meet = NULL;//定义快慢指针
    	while(fast){//这块是让快慢指针向前走，计算meet
    		slow = slow->next;
    		fast = fast->next;
    		if (!fast){//因为fast较快，所以一旦fast指向空，就说明无环
		    	return NULL;
		    }
		    fast = fast->next;
		    if (fast == slow){//快慢指针相遇说明有环
    			meet = fast;
    			break;
    		}
	    }
	    if (meet == NULL){//如果meet为空就返回无环
    		return NULL;
    	}
    	while(head && meet){//此时head在起始点，meet在快慢指针相遇点
	    	if (head == meet){//让head和meet一起走，相遇处就是入环点
	    		return meet;
	    	}
	    	head = head->next;
	    	meet = meet->next;
	    }
        return NULL;
    }
};
python版本：
class Solution:
    def detectCycle(self, head):
        if head is None or head.next is None: # 空链表或者只有一个节点，肯定无环
            return None
        slow = head
        fast = head # 快慢指针都是从头节点开始
        meet = None
        while fast:
            slow = slow.next
            fast = fast.next
            if fast is None: # 注意fast走到快，所以判断fast即可，fast走到None就是到底了，没环
                return None
            fast = fast.next # fast一次走两步
            if fast is slow: # step1：先让快慢指针一起走直到相遇
                meet = fast
                break
        if meet is None: # 相遇为空，返回无环
            return None
        # step2：固定快指针，慢指针从头开始，然后快慢指针一起走，再次相遇的地方就是入环处
        # 此时的meet是step中相遇的位置
        while head and meet:
            if head is meet:
                return meet
            head = head.next
            meet = meet.next
        return None # 切莫忘了，只要没返回meet，就是无环
'''
'''
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
'''
class Solution:
    def detectCycle(self, head):
        if head is None or head.next is None: # 空链表或者只有一个节点，肯定无环
            return None
        slow = head
        fast = head # 快慢指针都是从头节点开始
        while fast.next and fast.next.next: # 这里的判断条件你要注意啊，不是单纯判断fast，因为当fast为最后一个节点，fast.next.next就越界了
            fast = fast.next.next # 快指针一次走两步
            slow = slow.next # 慢指针一次走一步
            if fast == slow: # step1：先让快慢指针一起走直到相遇
                break
        if fast.next is None or fast.next.next is None: # 这是通过上面的while循环后快慢指针没相遇，那肯定是一个走到终点了，另一个还有就是无环
            return None
        # step2：固定快指针，慢指针从头开始，然后快慢指针一起走，再次相遇的地方就是入环处
        # 此时的fast和slow就是step1中相遇的位置，也就是meet
        slow = head
        while slow != fast:
            slow = slow.next
            fast = fast.next # 一起走
        return slow # 返回meet，此时slow和fast一样的

'''
if __name__ == "__main__":
    # 对于该输入 head = [3,2,0,-4], pos = 1，这个例子
    head = [3,2,0,-4]
    pos = 1
    # 构造链表
    node = []
    for i in head:
        node.append(ListNode(i)) # 创建每一个链表节点
    for i in range(len(node)-1):
        node[i].next = node[i+1] # 相当于这样链接3->2->0->-4->NULL
    node[len(node)-1].next = node[pos] # -4这个节点指向node[1]也就是2
    s = Solution()
    cycle_node = s.detectCycle(node[0]) # 求出入环处的节点
    print(cycle_node.val) # 打印入环处节点的值，为2，是head中的第1个值，与pos=1对
'''
```
