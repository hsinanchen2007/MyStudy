### 解题思路
用数组缓存遍历过的指针对应数据，如果不存在，数据中添加上数据，并指向下一个继续遍历；否则，去除重复数据。
![image.png](https://pic.leetcode-cn.com/6ba2cb68e901776084a818b9da7fca7f32f78fe6434ba20ac9aac3a1eac8a2ce-image.png)

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
    
    ArrayList l = new ArrayList();
    public ListNode removeDuplicateNodes(ListNode head) {
        if(head==null)return head;
        if(l.contains(head.val)){
            return removeDuplicateNodes(head.next);
        }else{
            l.add(head.val);
            head.next = removeDuplicateNodes(head.next);
        }
        return head;
    }
}
```