### 解题思路
执行用时 :8 ms 在所有 cpp 提交中击败了98.80%的用户
首先计算链表count，根据k求得分隔后每个链表的长度并存储在vec中
然后再根据vec和原链表root重新创建链表，并把每个链表头存放在result中

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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<int> vec;
        ListNode* now=root;
        int count=0;
        while(now)
        {
            now=now->next;
            ++count;
        }
        int s1=count/k; int s2=count%k;
        for(int i=0;i<k;++i)
        {
            if(s2>0)
            {
                vec.push_back(s1+1);
                --s2;
            }
           else 
           vec.push_back(s1);
        }

        vector<ListNode*> result(vec.size(),NULL);
		now = root;
		for (int j=0;j<vec.size();++j)
		{
            if(now==NULL) break;
            ListNode* D=new ListNode(now->val);
            result[j]=D;
            
			for (int i = 1; i < vec[j]; ++i)
			{
				now = now->next;	
                D->next=new ListNode(now->val);
                D = D->next;
			}
            now = now->next;
            D->next=NULL;
            
			
		}
        return result;
    }
};
```