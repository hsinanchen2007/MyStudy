### 解题思路
将链表的值放入数组中，然后在数组中采用双指针比较。

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
    bool isPalindrome(ListNode* head) {
        if(head==NULL) return true;
        if(head->next==NULL)return true;
        
        ListNode *i=head;
        vector<int> val;
        //将链表值放入数组
        while(i!=NULL){
            val.push_back(i->val);
            i=i->next;
        }
        int m=0,n=val.size()-1;
        while(m<n){
            if(val[m]!=val[n])
                return false;
            m++;
            n--;
        }
        return true;
    }
};
```