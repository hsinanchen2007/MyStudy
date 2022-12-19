### 解题思路
![image.png](https://pic.leetcode-cn.com/f6d77b586cbcae1b02c111b02711495314fb4dfd623f40fb5c5004df1b217336-image.png)
怎么会运行这么慢，沃德天

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
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        set<ListNode *> ptr_address;
        while(head->next!=NULL){
            ptr_address.insert(head);
            head = head->next;
            if(ptr_address.count(head)) return true;//set容器寻找元素使用count函数
        }
        return false;
    }
};
```