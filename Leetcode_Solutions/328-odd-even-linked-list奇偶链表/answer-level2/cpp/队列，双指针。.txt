### 解题思路
这道题首先想到的是用队列。然后想到的是用双指针。

队列首先是把偶数下表的节点存入队列。再把它们和原来的节点串起来。  时间o(n),空间o(n)

双指针就时一个指针指奇数节点。一个指针指偶数节点，再把它们连接起来。 时间o(n),空间o(1)

最后一种也是双指针法。去除了末尾链接的步骤。但是不知道为什么更慢了。 时间o(n),空间o(1)

### 代码

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
    // 执行用时 :24 ms, 在所有 C++ 提交中击败了9.37% 的用户
    // 内存消耗 :10.4 MB, 在所有 C++ 提交中击败了6.18%的用户
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next||!head->next->next) return head;
        queue<int> ql;
        ListNode* p = head;
        while(p->next&&p->next->next){
            ql.push(p->next->val);
            p->next = p->next->next;
            p = p->next;
        }
        if(p->next){
            ql.push(p->next->val);
        }
        while(!ql.empty()){
            p->next = new ListNode(ql.front());
            ql.pop();
            p = p->next;
        }
        p->next = NULL;
        return head;
    }

    // 执行用时 :12 ms, 在所有 C++ 提交中击败了78.48% 的用户
    // 内存消耗 :9.6 MB, 在所有 C++ 提交中击败了49.81%的用户
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next||!head->next->next) return head;
        ListNode* p1 = head, *p2 = head->next, *temp, *p = p2;
        while(p1&&p2&&p2->next){
            temp = p2->next;
            p2->next = temp->next;//连接下一个偶数节点
            p1->next = temp;//连接下一个奇数节点

            p2 = p2->next;
            p1 = p1->next;
        }
        p1->next = p;
        return head;
    }


    // 执行用时 :20 ms, 在所有 C++ 提交中击败了23.55% 的用户
    // 内存消耗 :9.4 MB, 在所有 C++ 提交中击败了98.84%的用户
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next||!head->next->next) return head;
        ListNode* p1 = head, *p2head = head->next, *temp, *p2 = p2head;
        while(p2&&p2->next){
            temp = p2->next;
            p2->next = temp->next;
            p1->next = temp;
            
            p1 = p1->next;
            p2 = p2->next;
            p1->next = p2head;
        }
        return head;
    }

};
```