## 思路分析
本题与[141-环形链表](https://leetcode-cn.com/problems/linked-list-cycle/)的思路是一致的，即是使用快慢指针（双指针），而唯一的区别在于，找到环的入口。总体的思路仍是先找到第一次相遇的节点，然后慢指针再继续向前走k个节点，而第k个节点就是整个链表的第k个节点。为什么是这样？下面将用一个简单的方式来进行证明。

首先做一个假设：
- 一个链表有n个节点（每个节点均用编号标识1,2,3,4,5，....，n），其一定会存在一个环；
- 环的入口节点的编号是index；
- 第一次相遇的节点编号为k；
- 快慢指针开始的起跑点：slow 在节点编号 1，fast指针在节点编号2；
- fast指针每次移动两个节点，slow指针每次移动1个节点；

> 接下来的解释没有附图，过于抽象，可一边读一边自己画图，案例图会在后面给出。

此时便可以得出环占上的节点数为 m = n - index + 1；当slow走到第K个节点的时候与fast相遇，此时slow走了K-1个节点（起点为1），fast走了2k-2个节点（起点为2，假设把快慢指针的起点也作为以移动的距离，那么此时可以得出，fast = 2 slow。这里节点从编号1开始，则当slow到k的时候，fast的编号应该是：2k = n + 绕环节点数x（包含编号为index 的节点） => x = 2k-n。fast和slow的相遇，所以他们在环上的移动节点数应该是一样的（fast去重情况下）,而slow在环上移动节点数为k-index+1。所以得出结论如下：

(2k-n)%m = k-index+1 , m = n -index + 1

=> 2k-n=k-index+1 => index=n-k+1  当fast指针只绕环一圈时
=> (2k-n)%(n-index+1) = k-index+1 当fast指针绕环大于1圈时


下面进行实例说明，这里附上案例图，有9个节点的链表，或者说是9个节点的有向图。

index = 3 , k = 7  | 符合公式  index=n-k+1
![link-1.png](https://pic.leetcode-cn.com/b458a887b27b9352ed134f7f4390429e319be071ea5a06406679af2c9ecdae07-link-1.png)

index = 4, k = 6  | 符合公式  index=n-k+1
![link-1.png](https://pic.leetcode-cn.com/bc05de802aeac94bebd6825c42de4e2e757875df6f39d7da40487935f4c1914f-link-1.png)


index = 8, k = 8  | 符合公式 (2k-n)%(n-index+1) = k-index+1
![link-1.png](https://pic.leetcode-cn.com/591445be67f8d2467380aadccbefe2b2d969636cf6ca63311a55b94d74a7828d-link-1.png)


因此证明成立！！！

## 代码实现
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr||head->next==nullptr) return nullptr;
        ListNode * fast = head->next,*slow=head,*p = nullptr;
        while(fast!=nullptr&&fast->next!=nullptr){
            if(fast==slow) {
                p=slow;
                break;
            };
            fast=fast->next->next;
            slow=slow->next;
        }
        if(p==nullptr) return nullptr;
        p = p->next;
        ListNode * q = head;
        while(p!=q){
            p=p->next;
            q=q->next;
        }
        return p;
    }
};
```