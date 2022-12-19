![image.png](https://pic.leetcode-cn.com/7e2a546dc45c2f77962a9618af71187acb4853ccb1562316dc626a5dcc202a84-image.png)

思路就是变循环链表，再计算跳几次，以哪个节点为头拆成单链表
```
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* a;
        a=head;
        int len=1;  //记录链表的长度
        if(a==NULL||a->next==NULL)  //特殊情况，空链表或者只有一个节点的链表，直接返回
            return a;
        while(a->next!=NULL){  //找到最后一个非NULL节点
            a=a->next;
            len++;
        }
        a->next = head;  //首尾相接变为循环链表
        int jump = len-k%len;  //需要从最后一个非NULL节点，再跳几次
        for(int i=0;i<jump;i++){  //跳就完事了
            a = a->next;
        }
        head = a->next;  //已经跳到了指定位置，把循环链表以指定节点为头分割为单链表
        a->next = NULL;
        return head;
    }
};
```
