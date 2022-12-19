### 解题思路
此处撰写解题思路
遍历两次完成前走k步操作
第一遍：
   获取最后一个节点的引用；
   获取链表的长度
第二遍：
   通过计算得出的k’，获取到新的head节点的前一个节点
   
两次处理完后，得到新的head节点

在遍历时需要处理三种情况 ：
1、k大于len时，此时需要遍历两遍
2、k小于len时 ，此时遍历一遍即可完成
3、k等于len时，此时遍历一遍即可完成

同时在进入是需要处理边界条件
1、链表为空
2、链表长度为1
3、k为0
4、k为1

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
    public ListNode rotateRight(ListNode head, int k) {

        int maxTime = 0;
        int len = 0 ;
        ListNode beforNewHead = head;
        ListNode newHead = head;
        ListNode tailNode = null;
        ListNode temp = head;
if(head != null && k >0 && head.next != null)
                {
                    while(maxTime < 2)
            {
               if(head != null && k >0 && head.next != null)
                {
                    while(temp != null)
                    {
                        len ++;
                        if(temp.next == null)
                        {
                            tailNode = temp;
                        }
                        temp = temp.next;

                        if((len -1) > k)
                        {
                            beforNewHead = beforNewHead.next;
                        }
                    }
                    if(k<len)
                    {
                        break;
                    }
                    else if(k == len )
                    {
                        beforNewHead = null;
                        break;
                    }
                    k = k%len;
                    len = 0;
                    temp = head;
                    maxTime ++ ;
                }
                else{break;}
            }
            if(beforNewHead != null && k > 0)
            {
                newHead = beforNewHead.next;
                tailNode.next = head;
                beforNewHead.next = null;
            }
                }
            
        
        return newHead;
    }
}
```