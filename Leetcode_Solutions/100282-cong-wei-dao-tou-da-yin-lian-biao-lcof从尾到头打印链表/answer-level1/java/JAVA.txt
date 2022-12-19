### 解题思路
此处撰写解题思路
我的思路:
    通过栈的原理。
    先创建一个辅助的节点，将这个辅助节点的值压入到栈中，并且统计链表的长度，然后创建
一个链表长度的数组。
    再循环这个栈中的元素个数，将栈弹出，放入到这个新的数组中，最后返回数组的首地址就可以了！
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
    public int[] reversePrint(ListNode head) {
        Stack<Integer> s1=new Stack<Integer>();

        ListNode temp=head;
    int len=0;
        while(temp!=null){
            len++;
            s1.push(temp.val);
            temp=temp.next;
        }
        int a[]=new int[len];
   
    for(int i=0;i<len;i++){
        a[i]=s1.pop();
    }
    return a;
        
        
    }
}
```