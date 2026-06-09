### 解题思路
* 当前元素的下一个指向下下个。 crawlNode.next = crawlNode.next.next
* 注意如果是第一个元素就进行了合并，要及时更新要返回的head数值

### 提醒
* 所有输入参数都不要直接使用
```java
// 不要直接修改函数输入参数
while(head != null) {
    head = head.next;
}
```


### 代码

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
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null) {
            return head;
        }
        ListNode crawl = head;
        while(crawl != null) {
            if(crawl.next != null && crawl.val == crawl.next.val) {                
                if(crawl == head) {
                    crawl.next = crawl.next.next;  
                    head = crawl;
                } else {
                    crawl.next = crawl.next.next;  
                }
            }else {
                crawl = crawl.next;
            }                        
        }
        return head;
        
    }
}
```