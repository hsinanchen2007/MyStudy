方法1：这个方法时间效率还是挺高的，代码如下：

```
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head -> next == NULL)//空链表或只有一个节点的链表
            return head;
        ListNode *H = new ListNode(INT_MIN);    //头节点可能需要删除，故创建一个新节点指向头节点
        H -> next = head;                       
        ListNode *pre = H;
        ListNode *cur = head;

        while (cur != NULL){
            bool flg = false;
            while (cur -> next != NULL 
                    && cur -> val == cur -> next -> val){
                flg = true;
                ListNode *tmp = cur;
                cur = cur -> next;
                delete tmp;
            }
            if (flg){
                ListNode *tmp = cur;
                cur = cur -> next;
                delete tmp;
                continue;//前面相等的节点删除了，可能紧接着又是需要删除的节点，故返回继续判断。如[1,1,2,2,3]
            }
            pre -> next = cur;//符合要求的节点cur,pre指向它
            pre = pre -> next;
            cur = cur -> next;
        }
        pre -> next = cur;
        ListNode *temp = H;
        temp = H -> next;
        delete H;
        return temp;
    }
};
```

方法2：学习别人的代码写的，这种方法比方法1慢一些

```
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head -> next == NULL)
            return head;
        ListNode *H = new ListNode(INT_MIN);
        H -> next = head;
        ListNode *pre = H;
        ListNode *cur = head;
        ListNode *tmp;
        int value, cnt;

        while (cur != NULL){
            cnt = 0;
            tmp = cur;
            value = cur -> val;
            while (cur != NULL && cur -> val == value){
                cnt++;
                cur = cur -> next;
            }
            if (cnt == 1){
                pre -> next = tmp;
                pre = tmp;
            }
        }
        pre -> next = NULL;
        tmp = H -> next;
        delete(H);
        return tmp;
    } 
};
```

