### 解题思路
链表值保存到数组里，处理完后再下回链表

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head)
        {
            return head;
        }
        //链表遍历一遍节点值保存到数组里
        vector<int>v;
        ListNode *cur = head;
        while(cur)
        {
            v.push_back(cur->val);
            cur=cur->next;
        }

        for(size_t i=0;i<v.size();++i)
        {
            int sum = 0;//从本身开始，防止结点有0本身出现。
            for(int j = i;j < v.size();++j)
            {
                sum += v[j];
                if(sum == 0)
                {
                    v.erase(v.begin() + i,v.begin() + j + 1);
                    i = -1;//删除后，需要重头开始
                    break;
                }
            }
        }

        if(0== v.size())
        {
            return NULL;//防止删完了，还有一个头结点的值
        }

        //又回到最初的起点
        cur = head;
        for(int i = 0;i < v.size();++i)
        {
            cur->val = v[i];
            if(i + 1 == v.size())
                break;
            cur = cur->next;
        }
        cur->next = NULL;//尾指针置空
        return head;
    }
};
```