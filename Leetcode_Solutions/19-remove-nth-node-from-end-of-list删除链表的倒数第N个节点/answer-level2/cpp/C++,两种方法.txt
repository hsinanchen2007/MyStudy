### 解题思路
方法1：先遍历求出长度，再从前往后遍历找到并删除
方法2: 双指针，当快的前进n时，慢的开始；当快的到结尾时，慢的正好到可以删除的那个节点前一个
### 方法1

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=1;
        ListNode* temp=head;
        while(temp->next){
            temp=temp->next;
            len++;
        }
        if(n==len) return head->next;  //如果是第一个，则直接返回head->next;
        int m=len-n-1;                 //倒数第n个，就是从头开始第len-n+1个，但是我们要保存他的前一个数字，并且数字是从1开始的；这里减了一个2
        ListNode* pre=head,* now=head->next;
        while(m>0){
            pre=pre->next;
            now=now->next;
            m--;
        }
        pre->next=now->next;
        return head;
    }
};
```
### 方法2：
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {   
        ListNode* dummy = new ListNode(NULL);
        dummy->next = head;  //添加头节点，便于操作
        ListNode* slow=dummy,* fast=dummy;
        int distance=0;
        while(fast->next){
            if(distance<n){
                fast=fast->next;
                distance++;
            }else{
                fast=fast->next;
                slow=slow->next;
            }
        }
        slow->next=slow->next->next;
        return dummy->next;
    }
};
```
