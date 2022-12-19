### 解题思路
回文判断方法：
1. 双指针比较；
2. 倒序处理，然后比较两个字符串是否相等；
对于此题来说这里是个单链表，这里需要做一些处理：
1. 遍历存储val到数组中，之后直接比较即可；
2. 做一遍链表反转，然后比较两个链表的值（理论上会耗时更多些）

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

        vector<int> value;
        while(head!=NULL) {
            value.push_back(head->val);
            head=head->next;
        }

        int size = value.size();
        int i = 0;
        int j = size-1;
        while(i<j){
            if(value[i]!=value[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;


    }
};
```