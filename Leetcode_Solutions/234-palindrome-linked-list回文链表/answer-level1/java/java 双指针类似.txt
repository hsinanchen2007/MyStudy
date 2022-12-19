### 解题思路
1.将链表（随机存储结构的列表），放入顺序列表（顺序存储结构的列表）中
2.首尾进行比较到终点

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
    public boolean isPalindrome(ListNode head) {
        if(head == null || head.next==null) return true;
        ArrayList<Integer> test= new ArrayList<Integer>(); 
        while(head!=null){
            test.add(head.val);
            head=head.next;
        }
        int a=test.size();
        for(int i=0;i<a/2;i++){
            if(!test.get(i).equals(test.get(a-1-i))){
                return false;
            }
        }
        return true;
    }
}
```