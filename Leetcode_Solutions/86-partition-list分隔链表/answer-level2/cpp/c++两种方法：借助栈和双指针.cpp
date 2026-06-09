### 第一种思路：借助两个栈，分别存放小于x的链表节点 和 大于等于x的链表节点。
哈哈哈，链表的题如果借助栈，真是分分钟解决，就是不够优雅，用了额外的空间，不过，在想不出更好的解决方法时，能获得accepted就是最重要的啦！
```c
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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return NULL;
        
        stack<ListNode*> min;
        stack<ListNode*> max;
        
        ListNode* node = head;
        while(node){
            if(node->val < x)
                min.push(node);
            else
                max.push(node);
            node = node->next;
        }
        
        // 这是从栈中反向打印出链表节点的高级操作
        head = NULL;
        while(!max.empty()){
            max.top()->next = head;
            head = max.top();
            max.pop();
        }
        while(!min.empty()){
            min.top()->next = head;
            head = min.top();
            min.pop();
        }
        return head;
    }
};
```

### 第二种思路：使用双指针和虚拟指针的方法
这里下标为1的变量是存放小于x的节点，下标为2的变量是存放大于等于x的节点。
最后拼接两个链表，注意第二个链表尾节点的`next`要赋为空指针！
```c
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next ) return head;
        ListNode* dummy1 = new ListNode(-1); 
        ListNode* dummy2 = new ListNode(-1);
        ListNode* pre1 = dummy1;
        ListNode* pre2 = dummy2;
        ListNode* cur = head;
        
        while(cur){
            if( cur->val < x){
                pre1->next = cur;
                pre1 = cur;
            }
            else {
                pre2->next = cur;
                pre2 = cur;
            }
            cur = cur->next;
        }
        pre2->next = NULL;
        pre1->next = dummy2->next;
        return dummy1->next;

    }
};
```
