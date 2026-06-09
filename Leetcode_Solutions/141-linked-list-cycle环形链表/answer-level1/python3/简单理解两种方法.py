```
'''
LeetCode 141. 环形链表
Given a linked list, determine if it has a cycle in it.
To represent a cycle in the given linked list, we use an integer pos which represents the position
(0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.
Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the first node.
Example 3:
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.

题目大意：
给定一个链表，判断链表中是否有环。
为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
示例 1：
输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。
示例 2：
输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。
示例 3：
输入：head = [1], pos = -1
输出：false
解释：链表中没有环。

解题思路：
先给你解释一遍题目哈，链表应该不用说了是啥了哈，就是地址不连续的数组，每一个节点包括节点值与节点指针，每个节点靠节点指针相连。
什么是链表的环呢？那就是，最后一个节点不是指向NULL，而是指向前面的某个节点，这不就是有环了。
这道题pos代表尾巴节点指向哪个节点，注意实例3中，只有一个节点，自己指向自己不算环。
对于链表求环有两种方法：
第一种方法：哈希法，python也就是集合法，下面是cpp代码，思想很简单，用指针去遍历，发现某点之前加入过集合，那不就是重复了，就是有环
class Solution {
public:
    bool hasCycle(ListNode *head) {
        std::set<ListNode *> node_set; # set集合
        while(head){
            if(node_set.find(head)!=node_set.end()){
                return true;}
            node_set.insert(head);
            head=head->next; # 链表遍历方式，靠指针的
        }
        return false;
    }
};
方法2：快慢指针法 面试答这个
定义一个走两步的快指针和一个走一步的慢指针，一起走，如果没相遇，且快慢指针中有一个到了终点了，说明无环
class Solution {
public:
    bool hasCycle(ListNode *head) {
    if (!head||!head->next)  return false;
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (slow != fast) {
        if (!fast || !fast->next) {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
    }
};
'''
# 因为是前几次写，我帮你写一下如何运行，后面你会了就可以自己写
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def hasCycle(self, head):
        if(head == None or head.next == None):
            return False
        node1 = head
        node2 = head.next
        while(node1 != node2): # 跳出条件，如果有环，这两个指针一定会相遇，其实和跑步被压了一圈是一个道理
            if(node2 == None or node2.next == None):
                return False
            node1 = node1.next
            node2 = node2.next.next

        return True

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
    print(s.hasCycle(node[0]))


```
