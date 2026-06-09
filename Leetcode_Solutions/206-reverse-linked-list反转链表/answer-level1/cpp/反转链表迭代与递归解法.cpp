### 解题思路
此处撰写解题思路

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
//递归解法
class Solution {
public:
ListNode* reverseList(ListNode* head){
       return helper(head , NULL);
      
    }
    ListNode* helper(ListNode* cur,ListNode* nextnode){
        if(cur == NULL)return nextnode;
        ListNode* tmp = cur -> next;
        cur -> next = nextnode;
        return helper(tmp,cur);
    }
};
//思路2 迭代
    /*
    ListNode* reverseList(ListNode* head) {
        ListNode* nextnode = NULL;
        //ListNode* tmp = head -> next;
        while(head){
            ListNode* tmp = head -> next;
            head -> next = nextnode;
            nextnode = head ;
            head = tmp ;
        }
        return nextnode;
    }
};
    //思路3：遍历存储数字，再遍历修改数字
    /*ListNode* reverseList(ListNode* head) {
        vector<int> vals;
        ListNode* head1 = head;
        int n = 0;
        while(head)
        {
            vals.push_back(head -> val);
            head = head-> next;
            n++;
        }
        ListNode* head2 = head1;
        while(head1)
        {
            head1 -> val = vals[n-1];
            head1 = head1-> next;
            n--;
        }
        return head2;
    }
};