### 解题思路
因为官方没有考虑到一种情况就是当节点的数量和n一样大时，first为空的时候，如果还将first->next赋值给first这在C++里面会报错，所以我给head增加了一个头节点，因此就算是循环n+1次时first是NULL，而不是NULL的下一个值。
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 多次遍历
        // ListNode* swap = head;
        // ListNode* t = head;
        // int cnt = 0;
        // while(swap){
        //     swap = swap->next;
        //     cnt++;
        // }
        // //当删除的是第一个元素时 直接不要第一个 返回head
        // if(cnt == n){
        //     head = head->next;
        //     return head;
        // }   
        // //当删除的不是第一个元素时 先利用循环把中间的删除掉，然后返回之前保存的t
        // int i = 1;
        // while(i != cnt-n){
        //     head = head->next;
        //     i++;
        // }
        // head->next = head->next->next;
        // return t;

        // 一次遍历
        ListNode *dump = new ListNode(0);
        dump->next = head;
        ListNode* first = dump;
        ListNode* second = dump;
        for(int i = 1; i <= n+1; i++){
            first = first->next;
        }
        while(first){
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return dump->next;
    }
};

```