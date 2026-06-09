做完题，发现很多题解评论，然后清一色的不满足题目要求，一次遍历！那些使用栈，或者开几个while循环的都不是一次遍历的。所以就把自己的做法，发出来，烦请批评指正
```c++
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
        //链表分为三种情况
        //   a-->b-->c-->d-->e-->f-->null                
        //假设   ---         --- 
        //       |           |
        //      \|/         \|/
        //       m           n
        //边界情况一
        //   a-->b-->c-->d-->e-->f-->null                
        //  ---         --- 
        //   |           |
        //  \|/         \|/
        //   m           n
        //边界情况二
        //   a-->b-->c-->d-->e-->f-->null                
        //      ---             --- 
        //       |               |
        //      \|/             \|/
        //       m               n
        
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n) return head;
        ListNode* node=head;
        ListNode* subnode=head;
        ListNode* pre=nullptr;
        ListNode* curr=nullptr;
        ListNode* next=nullptr;
        ListNode* Flag;
        int num=0;
        //引入（num+1>n）条件，确保翻转结束节点为最后节点时，更新返回值
        while(node!=nullptr||num+1>n){

            ++num;
            if(num<m){
                //记录开始反转的上一个节点，以便连接翻转部分链表
                if(num+1==m){
                    subnode=node;
                }
                node=node->next;
            continue;
            }
            //判断是否完成反转部分
            if(num>n){
                //开始翻转部分需要直接链接上后续未翻转部分
                Flag->next=node;
                if(m!=1){ //如果是从收个节点反转，则头结点调整
                    subnode->next=pre;
                }else{
                    //如果从第一个节点开始翻转，其首节点改变
                    head=pre;
                }
                break;
            }
            curr=node;
            next=node->next;
            node->next=pre;
            pre=curr;
            node=next;
            //此处记录开始翻转的节点
            if(num==m){
                Flag=pre;
            }
        }
        return head;
    }
    
};
```

