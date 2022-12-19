### 解题思路【常规思路】
把链表先存入数组，然后数组可以直接获取对应的中间结点

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
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> ans;
        while(head!=NULL){
            ans.push_back(head);
            head = head->next;
        }
        return ans[ans.size()/2];

    }
};
```
![image.png](https://pic.leetcode-cn.com/7229aca96a3dc6d781c11347c5b51ee9901b462f44c76ed938651630b6ec0a92-image.png)

### 解题思路【快慢指针】
    使用慢指针 slow 和快指针fast 两个指针同时遍历链表。快指针一次前进两个结点，速度是慢指针的两倍，
    那么，当快指针到达链表末尾时，慢指针正好到达链表的中间。
```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    
    public ListNode middleNode(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;
        while(fast!=null && fast.next!=null){
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;

    }
}
```
