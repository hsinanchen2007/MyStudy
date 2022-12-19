### 解题思路
![批注 2020-02-15 224246.png](https://pic.leetcode-cn.com/b89b98dbe00ed041cf45d22a55430a0bc4c5f745c45aeec6ff7c5c06b28b1632-%E6%89%B9%E6%B3%A8%202020-02-15%20224246.png)
1.设置dummy节点以便删除头节点重复元素
2.当cur下一段节点为重复节点时，设置临时节点tmp向前探路，当走到重复节点最后一个节点时，让cur->next = tmp->next。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


    struct ListNode* deleteDuplicates(struct ListNode* head){
        //假设1->1->3->3->4
        struct ListNode dummy;
        dummy.next = head;
        //让cur指向dummy
        struct ListNode*cur = &dummy;

        while(cur->next && cur->next->next){ 
            if(cur->next->val == cur->next->next->val){// 1->1满足条件

                struct ListNode *tmp = cur->next;

                while(tmp && tmp->next && tmp->val == tmp->next->val){//不满足
                    tmp = tmp->next;
                }
                cur->next = tmp->next;//跳过前面重复节点，直接3->3-4
            }
            else
                cur = cur->next;
        }
        return dummy.next;
    }
```