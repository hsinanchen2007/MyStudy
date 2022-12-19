```
两种方法都是看题解写的==
// 找到环形列表的环的起点
//方法一：快慢指针
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *start = head;
        ListNode *meet = NULL;
        while(fast && fast->next) {
            // 注意点： 先动再比
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                meet = fast;
                break;
            }
        }
        //注意点：没相遇以及头结点为空的情况不成环
        if(meet == NULL || head == NULL) {
            return NULL;
        }
        // 起点与相遇点以步长为1开始移动
        while(start != meet) {
            start = start->next;
            meet = meet->next;
        }
        return meet;
    }
};

//方法二： hash表存链表的节点的地址
#define MaxSize 10007
struct ListNode *detectCycle(struct ListNode *head) {  
    if(!head) return NULL;
    int hash_address[MaxSize] = {0};
    while(head->next) {
        int addr = (int)head % MaxSize;//哈希函数
        if(hash_address[addr] == 0) {  
            hash_address[addr] = head;
        } else { 
            while(hash_address[addr] != 0) {
                if((int)head == hash_address[addr]) {  //已出现则返回该节点
                    return head;
                } else {                               //发生冲突，继续存储在hash表，采用线性散列法解决冲突
                        addr = (addr + 1) % MaxSize;
                    } 
            }
            hash_address[addr] = head; 
        }
        head = head->next;
    }
    return  NULL;
}
```
