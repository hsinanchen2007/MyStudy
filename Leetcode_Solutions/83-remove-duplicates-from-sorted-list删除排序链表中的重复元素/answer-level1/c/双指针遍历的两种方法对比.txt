### 解题思路
**双指针法**
一个指针p标记已处理好处，一个指针q去遍历。
典型的双指针链表操作。
1. 方法1:直捣黄龙：p->val==q->val时执行while，直到将q定位到下一个不等处并加入。（此方法可能避免了法2对结尾重复数据的处理，推荐）
2. 方法2:见机行事：遍历q结点，若发现p,q值不相等就加入。易错点：为了处理[3,3]这类结尾的数据，所以必须在q右移走后，将p->next置空。（断绝前后关系）
法2代码如下：
### 代码

```c

struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head == NULL) return head;
    struct ListNode *p = head,*q = head->next;
    while(q != NULL){
        if(p->val != q->val){   //找到第一个不相等,q就加入，并将p移到q处
            p->next = q;
            p = q;
        }
        //q必定右移
        q = q->next;
        p->next = NULL;         //这步很关键！避免[3,3]结尾时不能剔除最后一个3
    }
    return head;
}
```

第一个写题解，有错误的地方还请大家指出。