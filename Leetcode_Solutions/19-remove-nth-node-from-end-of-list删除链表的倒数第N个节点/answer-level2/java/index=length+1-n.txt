### 解题思路
此处撰写解题思路

该链表不带头结点，所以要注意判断删除的是否为第一个结点

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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        
        int length=1;
        ListNode tem = head;
        while(tem.next != null){
            length++;
            tem = tem.next;
        }

        int index = length+1-n;
        
        if(index==1){
            ListNode temm = head;
            temm = temm.next;
            return temm;
        }
        else{
            int num=2;
            ListNode temp = head;
            while(temp.next != null){
                if(index == num){
                    //删除操作。
                    temp.next = temp.next.next;    
                    break;
                }
                num++;
                temp = temp.next;
            }         
        ListNode tempo = head;
        return tempo;
        }  
    }

   
}
```