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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*
            这个题要好好写并写博客笔记的。
            1 2 3 4 5
            删除第4个节点 Listnode *tmp = 4->next;
            free(3->next)
            3->next = tmp;

            所以我们可以用快慢指针，让一个先在前面跑。

            求倒数第2，如果有大于等于3个节点。
            1 2 3 
            1 > 2 
            2 > 3 1 > 2
            
            如果正好有两个 1 > 2  发现到达。

            ## 思路分析清楚。

            首先判断是否删除的是头结点。
            在判断是否删除的是尾部节点。
            然后就是中间节点。
        
        */
        int forward = n-1;
        ListNode * forw = head;
        ListNode * second = head;
        while(forward--) forw = forw->next;
        if(forw->next == NULL ){// 特判，待删除的元素是队伍首个
            //说明head就是要删除的。
            ListNode * tmp = head->next;
            delete head;
            return tmp;
        }

        while(forw->next != NULL){
            forw  = forw->next;
            if(forw->next ==  NULL){ 
                if(second->next == forw){ // 如果到达终点后 second->next == forw,说明要删除倒数第一。
                    delete second->next;
                    second->next = NULL;
                       break;
                }else{ // 否者 删除中间的
                    ListNode * tmp = second->next->next;
                    delete second->next; 
                     second->next = tmp;
                        break;
                }
            }
            second = second->next;
        }
        return head;
        
    }
};
```
