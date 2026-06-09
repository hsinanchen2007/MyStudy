### 解题思路
这个解法时间复杂度比较高O(n^2)，但是比较容易理解。
- 首先设置两个指针slow, fast. fast从slow的下一个节点开始算起.
- 用fast依次遍历剩余的链表，如果遇到比slow->val大的值就break并输入到result中。
- 因为最后一个节点没有后驱结点，所以可不予以遍历，并直接在result中输入0。


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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> result;
        if(head==NULL)
            return result;
    
        ListNode* slow = head;

        while(slow&&slow->next){
            ListNode* fast = slow->next;
            int val = slow->val;
            int max = val;
            while(fast){        
                if(fast->val>max){
                    max = fast->val;
                    break;
                }
                fast = fast->next;
            }
            if(max==val)
                result.push_back(0);
            else
                result.push_back(max);
            slow = slow->next;
        }
        result.push_back(0);
        return result;
    }
};
```