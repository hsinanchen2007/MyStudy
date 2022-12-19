### 解题思路
此处撰写解题思路

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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        //定义一个最终结果
        ListNode result=new ListNode(0);
        ListNode temp=result;
        //没有声明临时变量直接操作l1和l2
        while(l1!=null||l2!=null){
            //用于存储临链表的下一节点的临时变量
            ListNode next1,next2;
            //如果l1为空,说明l1已经全部比较完了,l2的剩下的元素直接拼接在链表后方即可,并且跳出循环直接返回即可,同理l2为空也是一样
            if(l1==null){
                temp.next=l2;
                break;
            }else if(l2==null){
                temp.next=l1;  
                break;
            }
            //对当前节点的值进行比较
            if(l1.val>l2.val){
                //先保存下一个节点
                next2=l2.next;
                //将当前节点连接到temp下
                temp.next=l2;
                //将下面节点换成null
                l2.next=null;
                //替换l2
                l2=next2;
            }else{
                //同上面操作一样
                next1=l1.next;
                temp.next=l1;
                l1.next=null;
                l1=next1;
            }
            //取下一个
            temp=temp.next;  
        }
        //最终的result.next就是想要的结果
        return result.next;
    }
}
```