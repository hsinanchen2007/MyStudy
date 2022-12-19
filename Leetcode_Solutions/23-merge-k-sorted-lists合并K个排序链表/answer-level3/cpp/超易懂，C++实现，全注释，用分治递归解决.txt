
```
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;  // 数据为空
       return binaryMerge(lists, 0, lists.size()-1);  // 整个K规模问题，起始下标，末尾下标
    }
    ListNode* binaryMerge(vector<ListNode*>& lists, int start, int end)
    {
        if(start==end)  // 分治到了一侧只有一个链表，不用合并，直接返回
            return lists[start];  
        if(end-start==1)  // 分治到了两个链表，用合并两个链表的函数解决 
            return mergeTwoLists(lists[start], lists[end]);
        int mid=start+end>>1;  // 取区间中点
        ListNode* n1=binaryMerge(lists, start, mid-1);  // 划分左侧区域并求解
        ListNode* n2=binaryMerge(lists, mid, end);  // 划分右侧区域并求解
        return mergeTwoLists(n1, n2);  // 合并两个区域得整个问题的解         
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 此函数可直接用于过合并两个有序数组
        ListNode* p1=l1, *p2=l2;
        ListNode* l3= new ListNode(-1);
        ListNode* q=l3;
        if(p1||p2)  // 两链表之一未遍历完
        {
            while(p1&&p2)  // 二者均未遍历结束，此循环结束后必然有一链表遍历完成
                if(p1->val<=p2->val)
                {
                    q->next=p1;
                    q=q->next;
                    p1=p1->next;
                }
                else
                {
                    q->next=p2;
                    q=q->next;
                    p2=p2->next;
                }
            while(!p2&&p1)  // 若第二链表遍历结束，直接填充链表1元素即可 
            {
                q->next=p1;
                q=q->next;
                p1=p1->next;
            }
            while(!p1&&p2)  // 若第一链表遍历结束，直接填充链表1元素即可 
            {
                q->next=p2;
                q=q->next;
                p2=p2->next;
            }
        }
        q=l3;
        l3=l3->next;
        delete q;
        return l3;
    }
};
```
