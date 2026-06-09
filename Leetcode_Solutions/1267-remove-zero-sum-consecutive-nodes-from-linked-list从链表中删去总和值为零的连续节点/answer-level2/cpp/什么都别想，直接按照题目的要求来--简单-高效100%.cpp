### 解题思路
此处撰写解题思路，击败100%的用户，在内存消耗方面。
![2020-01-10_185321.png](https://pic.leetcode-cn.com/65c2856876f469d3af0552d748ee2a453eaefe7696944cfcbedc00fb6fd68553-2020-01-10_185321.png)

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
            return head;
        vector<int>v;
        ListNode *h=head;
        while(h)
        {
            v.push_back(h->val);
            h=h->next;
        }
        for(size_t i=0;i<v.size();++i)
        {
            int sum=0;//从本身开始，防止结点有0本身出现。
            for(size_t j=i;j<v.size();++j)
            {
                sum+=v[j];
                if(sum==0)
                {
                    v.erase(v.begin()+i,v.begin()+j+1);
                    i=-1;//删除后，需要重头开始
                    break;
                }
            }
        }
        if(0== v.size())
            return nullptr;//防止删完了，还有一个头结点的值
        h=head;
        for(size_t i=0;i<v.size();++i)
        {
            h->val=v[i];
            if(i+1==v.size())
                break;
            h=h->next;
        }
        h->next=nullptr;//尾指针置空
        return head;
    }
};
```