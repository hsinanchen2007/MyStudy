### 解题思路
此处撰写解题思路
我的思路:
    图方便了，利用栈的特新，先进后出的原则，先利用一个辅助的头节点，循环遍历将
辅助的头节点压栈
    再将栈中的元素取出来，再赋值一个临时的节点变量，循环比较这个从栈中的节点是否相同，
用一个布尔类型的变量来接受确认，如果有一个为false那么就不要执行下去了，直接返回false,就可以了

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
        Stack<Integer> s1=new Stack<Integer>();
        if(head==null){
            return true;
        }
        ListNode temp=head;
        ListNode cur=head;
        int len=0;
        while(temp!=null)
        {
            len++;
            s1.push(temp.val);
            temp=temp.next;
        }
        boolean flag=false;
    for(int i=0;i<len;i++){

        if(s1.pop()==cur.val){
            flag=true;
        }else{
            flag=false;
            break;
        }
        cur=cur.next;
    }
        return flag;


    }
}
```