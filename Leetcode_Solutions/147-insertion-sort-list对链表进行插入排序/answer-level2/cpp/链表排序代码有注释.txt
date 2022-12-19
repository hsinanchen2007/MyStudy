`
class Solution {
public:
    
    ListNode* insertionSortList(ListNode* head) {
        
        //基本合法检查，还不涉及排序过程
        if(head == NULL || head->next == NULL) {
            return head;
        }

        //01 依赖空间 
        ListNode first(0); //有序链表头开始部分，固定头节点位置，保证插入节点元素 pre节点一定存在。
        first.next=head; //第一默认有序  head->6->5->1->8

        ListNode* cur = head; // 有序链表头结束部分 初始化 默认第一

        ListNode* pre = NULL;//插入排序需要插入记录位置，每次都需要重新计算
        
        //从第一个元素开始遍历链表，假设第一个元素是有序的
        while(cur) {
            //不是有序数据
            if(cur->next &&cur->next->val <cur->val)
            {
                //寻找插入位置  .
                pre=&first;//从有序链表head开始遍历.次数，pre 指向head节点，没有数据
                while(cur->next&&pre->next && cur->next->val>pre->next->val) // head->6->5->1->8
                {
                    pre=pre->next;//pre->next 就是插入地方。pre是前面一个节点。存在插入规则，是在固定节点后面插入
                }

                //插入过程 类似节点翻转最前面位置（pre->next 就是插入地方）
                ListNode* temp = cur->next; //记录待插入元素5，head->6->5->1
                cur->next=temp->next; //移除待插入元素5 ，移动下一个元素 head->6->1
                
                temp->next =pre->next;//待插入元素5后面节点。 
                                    //                    5  ->6->1    
                                    //                    head->6->1 

                pre->next=temp;//待插入元素5前面节点。 head->5->6->1
            //这里不需要一定cur=cur->next，移动下一个元素 head->6->1 完成
            }else
            {   
                cur=cur->next;// 有序数据||最后一个元素 循环结束
            }             
        }

        return first.next;
    }
};
`