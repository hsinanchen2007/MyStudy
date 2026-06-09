### 解题思路
创建一个新的链表，遍历比较两个链表，每次把最小的节点放到新的链表中

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
        if(l1==null){
            return l2;
        }else if(l2==null){
            return l1;
        }
        ListNode node1 = l1;//l1辅助节点
        ListNode node2 = l2;//l2辅助节点
        ListNode r=null;//新链表
        ListNode tmp=null;//新链表辅助节点
        while(node1!=null||node2!=null){//只要有一个链表没有遍历完，循环就会继续
            if(node1!=null&&node2!=null){//两个链表都没有遍历到尽头时
                if(node1.val<node2.val){//判断大小
                    if(r==null){//未初始化时初始化
                        r=node1;
                        tmp=r;
                    }else{//加入新链表
                        tmp.next=node1;
                        tmp=tmp.next;
                    }
                    node1=node1.next;
                }else{//同上
                    if(r==null){
                        r=node2;
                        tmp=r;
                    }else{
                        tmp.next=node2;
                        tmp=tmp.next;
                    }
                    node2=node2.next;
                }
            }else if(node1==null){//如果一个链表完成遍历
                while(node2!=null){//把第二个链表的剩余节点全部接入新链表
                    tmp.next=node2;
                    tmp=tmp.next;
                    node2=node2.next;
                }
            }else{//同上
                while(node1!=null){
                    tmp.next=node1;
                    tmp=tmp.next;
                    node1=node1.next;
                }
            }
        }
        //返回新链表
        return r;
    }
}
```