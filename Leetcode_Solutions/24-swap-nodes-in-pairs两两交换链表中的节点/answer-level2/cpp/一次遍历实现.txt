### 解题思路
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :7.8 MB, 在所有 C++ 提交中击败了100.00%的用户

主要思路是是用了dummyHead，即添加了一个头结点，方便节点挂在上面
以及cut的思想，就是断链，返回值为断链处下一段链表的头结点

从头开始，每次断链，只断一个节点然后再断一个，把这两个挂在头节点上，一直重复下去即可
终止条件即为当cut之后返回值为nullptr，表明所有节点都被拆掉了并挂在头结点上了

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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummyHead(0);
        dummyHead.next = head;
        ListNode *p = &dummyHead;//p用作扫描指针，始终指向dummyHead链表的尾巴，使得所有结点都在尾巴处插入
        ListNode *p1,*p2;
        p1 = head;
        p2 = head;
        while(p2!=NULL)
        {
            if(p1 == NULL)
                break;
            if(p1->next == NULL)
            {
                p->next = p1;
                break;
            }
                
            p2 = cut(p1);
            ListNode* left = cut(p2);
            p->next = p2;
            p = p->next;
            p->next = p1;
            p = p->next;
            p1 = left;
        }
        return dummyHead.next;
    }
    ListNode* cut(ListNode* l)//断链函数 a->b->c->d->e l指向b的时候，cut之后，返回指向c的指针，并将b->next 设置为nullptr
    {
        if(l==NULL)
            return NULL;
        if(l->next == NULL)
            return NULL;
        ListNode* temp = l->next;
        l->next = NULL;
        return temp;
    }
};
```