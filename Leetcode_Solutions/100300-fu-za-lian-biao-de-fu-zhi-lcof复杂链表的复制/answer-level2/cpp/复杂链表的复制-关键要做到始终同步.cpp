### 解题思路
此处撰写解题思路
本题关键点是random元素，而random在链表中是随意指向的，因此必须在链表构成后，才能对新链表的random进行赋值。赋值时因为新旧链表的地址都不一样，所以我想到的办法就是让两个链表同步遍历，遍历旧链表中还要注意判断旧链表的某一节点的random知否跟另一节点地址相同，所以这里要用到双层循环。因为是新旧链表遍历也都是同步的，所以当发现有地址相同的节点时，把新链表的当前节点地址赋值给外层循环中节点的random值，遍历完成后，所有的random也就都赋完值了。
### 代码

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* l_Cp = new Node(0);
        Node *mk_ret, *mk_src;
        Node* retList = mk_ret =l_Cp;
        Node* srcList = mk_src = head;
        while(head != NULL)
        {
            Node* tmp = new Node(0);
            tmp->val = head->val;
            l_Cp->next = tmp;
            l_Cp = l_Cp->next;
            head = head->next;
        }

        for(head = mk_src, mk_ret = l_Cp = mk_ret->next; mk_src != NULL; )
        {
            
            for(; head != NULL; )
            {
                if(mk_src->random == head)
                {
                    mk_ret->random = l_Cp;
                }
                head = head->next;
                l_Cp = l_Cp->next;
            }
            mk_ret = mk_ret->next;
            l_Cp = retList->next;
            mk_src = mk_src->next;
            head = srcList;
        }

        return retList->next;
    }
};
```