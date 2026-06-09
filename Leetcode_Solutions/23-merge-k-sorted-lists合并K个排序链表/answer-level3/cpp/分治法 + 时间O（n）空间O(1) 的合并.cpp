### 解题思路
执行用时 :12 ms, 在所有 C++ 提交中击败了99.68% 的用户
内存消耗 :10.2 MB, 在所有 C++ 提交中击败了100.00%的用户
采用分治法 每次将两个链表合成一个，例如先lists[0] merge lists[1] 再 lists[2] merge lists[3] .....
一轮过后，将链表数目降到 n/2向上取整，接着重复上一步，直到只剩一条链表，输出即是答案
合并两个链表的O(n) O(1)算法只改变指针方向，不需要额外内存空间，参考同leetcode上链表合并那道题（迭代法比递归更省时，尽管递归写法很漂亮）
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> temp;
        if(lists.size()==0)
            return NULL;
        while(temp.size()!=1)
        {
            temp.clear();
            int n = lists.size();
            int times = n/2;
            bool flag = true;
            if(n%2!=0)
                flag = false;
            for(int i=0;i<times;++i)
            {
                ListNode* r = merge2(lists[i*2],lists[i*2+1]);
                temp.push_back(r);
            }
            if(!flag)
                temp.push_back(lists.back());
            lists.clear();
            lists.assign(temp.begin(),temp.begin()+temp.size());
        }
        return temp[0];
    }
    ListNode* merge2(ListNode* l1 , ListNode* l2)
    {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode *p,*p1;
        bool flag = true;
        if(l1->val > l2->val)
        {
            flag = false;
            p = l2;
            p1 = l1;
        }
        else
        {
            p = l1;
            p1 = l2;
        }
        while(p1!=NULL)
        {
            if(p->next == NULL)
            {
                p->next = p1;
                break;
            }
            if(p1->val < p->next->val)
            {
                ListNode* temp = p1->next;
                p1->next = p->next;
                p->next = p1;
                p1 = temp;
                temp = NULL;
                delete temp;
                p = p->next;

            }
            else
            {
                p = p->next;
            }
        }
        if(flag)
            return l1;
        else
            return l2;
    }
};
```