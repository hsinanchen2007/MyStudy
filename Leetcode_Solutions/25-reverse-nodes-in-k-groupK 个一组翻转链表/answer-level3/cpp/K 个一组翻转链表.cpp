![图片.png](https://pic.leetcode-cn.com/e202b34fece406f0fa818eb06b7986174bcb6d058e1ff68157f2d37fc6655556-%E5%9B%BE%E7%89%87.png)

分两种情况：
1. 一种是pre为head:
此时来一个节点就插入到pre前面

2. 第二种pre为上一组的最后一个节点
此时来一个节点就插入到pre的后面

```
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 1)
            return head;
        int num = 0;
        ListNode *p = head;
        while(p != nullptr){
            num++;
            p = p->next;
        }
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        ListNode *pre = head;
        int i = num/k;
        
        int count = 1;
        while( i > 0){
            //pre为头结点的情况
            if(pre == head){
                while(true){
                    p1->next = p2->next;
                    p2->next = pre;
                    pre = p2;
                    count++;
                    if(count >= k){
                        head = pre;
                        i--;
                        if(i == 0)
                            break;
                        pre = p1;
                        p1 = p1->next;
                        p2 = p1->next;
                        count = 1;
                        break;
                    }
                    p2 = p1->next;
                }
            }
            //pre不为头结点的情况
            else{
                while(true){
                    p1->next = p2->next;
                    p2->next = pre->next;
                    pre->next = p2;
                    count++;
                    if(count >= k){
                        i--;
                        if(i == 0)
                            break;
                        pre = p1;
                        p1 = p1->next;
                        p2 = p1->next;
                        count = 1;
                        break;
                    }
                    p2 = p1->next;
                }
            }
            
            
        }
        return head;
    }
};
```
