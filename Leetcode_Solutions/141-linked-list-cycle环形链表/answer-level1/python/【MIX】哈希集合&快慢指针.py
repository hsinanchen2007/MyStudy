### 解题思路
1. 使用HashSet记录访问节点
2. 使用快慢指针

### 代码

```java []
public class Solution {
    public boolean hasCycle(ListNode head) {
        // 双指针
        ListNode pFast = head;
        ListNode pSlow = head;

        while(pFast != null && pFast.next != null){
            pFast = pFast.next.next;
            pSlow = pSlow.next;
            if(pFast == pSlow)
                return true;
        }
        return false;
    }
}
```
```python []
class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        # 双指针
        pSlow, pFast = head, head
        while pFast != None and pFast.next != None:
            pSlow = pSlow.next
            pFast = pFast.next.next

            if pFast == pSlow:
                return True
        return False
```
```c++ []
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
        set<ListNode *> rec;
        ListNode *cur = head;
        while(cur != nullptr){
            if(rec.find(cur) == rec.end()){
                rec.insert(cur);
                cur = cur->next;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
```
