### 解题思路
思路就是一个一个解决自己留下的坑的过程。。。
1.新建链表时new ListNode没注意给的构造函数，应该赋予个初始值new ListNode(0)
2.忘了规定res数组的大小，爆
3.规定了res数组的大小忘了最后一位进位要多一位的情况，爆
4.规定res数组的大小过于仓促，导致类似[1] [1]这种情况的数据会输出[2,0]多出个0，在改
5.妈卖批被自己蠢到了
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==0&&l2==0)
        {
            ListNode * out1 =NULL;
            return out1;
        }
        int star = 0;
        int len1=1;//记录l1的长度
        int len2=1;//记录l2的长度
        ListNode* p=l1;
        ListNode* q=l2;
        while(p->next!=NULL)//获取l1的长度
        {
            len1++;
            p=p->next;
        }
        while(q->next!=NULL)//获取l2的长度
        {
            len2++;
            q=q->next;
        }
        vector<int> res(max(len1,len2)+1,0);
        while(l1 != NULL || l2 != NULL)
        {
            int a,b;
            if(l1 == NULL && l2 != NULL)
            {
                a = 0;
                b = l2->val;
                l2 = l2->next;
            }
            else if(l1 != NULL && l2 == NULL)
            {
                a = l1->val;
                b = 0;
                l1 = l1->next;
            }
            else 
            {
                a = l1->val;
                b = l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }
            res[star] = a+b;
            star++;
        }
        cout<<res[0]<<endl;
        int flag = 0;
        for(int i =0 ;i<res.size() ; i++)
        {
            if(res[i]>=10)
            {
                res[i] = res[i]%10;
                res[i+1]++;
            }
        }
        cout<<res[1]<<endl;
        ListNode * head = new ListNode(0);
        ListNode * w;
        w = head;
        for(int i=0 ;i<res.size() ; i++)
        {
            if(i == res.size()-1 &&res[i]==0)
                break;
            ListNode * s = new ListNode(0);
            s->val = res[i];
            w->next = s;
            w = s;
        }
        w->next = NULL;
        return head->next;

    }
};
```