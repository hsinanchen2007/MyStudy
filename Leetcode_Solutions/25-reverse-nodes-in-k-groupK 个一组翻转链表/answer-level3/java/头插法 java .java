### 解题思路
类似的题有
翻转链表所有节点；
翻转链表m到n个节点间的；
每两个节点翻转；
以及本题，每k个节点翻转，并且最后如果节点个数少于k则不翻转；

一般而言解题方法有：递归、头插法、直接逆向法等
个人比较喜欢头插法，原地一次遍历即可解决：O（n）+ O（1）；
头插法关键点：（此题分为若干段，每k个为一段。）
（1）头结点   hed（每段的第一个节点的前一个节点）
（2）当前节点 cur
（3）翻转后的最后一个节点 last（在一次翻转中始终不变，即等于当前段未开始翻转前的第一个节点）
（4）临时变量temp保存cur的下一个节点

一段中翻转过大致过程：
//头插
temp = cur.next；
cur.next = hed.next;
hed.next = cur;
//更新节点
last.next = temp;
cur = temp;

//当一段翻转完后，更新下一段的相关节点即可
hed = last;//下一段的hed等于上一段最后一个
last = cur;//下一段的last等于下一段的第一个节点，且始终不变

//由于题目要求，如果最后不足k个，则不用翻转，因此加入一个计数count判断
//当count < k时，将最后一段重新翻转一下即可
//需要更新一下相关节点
//由于判断写在下一次更新前，所以hed依旧没变，而last已经指向最后一个节点，
//所以更新last = hed.next;cur = last;
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
    public ListNode reverseKGroup(ListNode head, int k){
        ListNode top = new ListNode(-1);
        top.next = head;

        ListNode hed = top;//当前翻转段的头节点
        ListNode cur = head;//当前节点
        ListNode last = cur;//当前翻转段的最后一个节点
        ListNode temp;//临时存放当前节点的下一个节点
        int count;//用于计数，当前翻转了几个节点，若小于k，则重新翻转一下
        while(cur != null){
            count = 0;
            for(int i = 0;i < k && cur != null;i++){//翻转k个节点，并且cur！=null
                temp = cur.next;
                cur.next = hed.next;
                hed.next = cur;
                last.next = temp;
                cur = temp;
                count++;
            }
            if(count != k){//判断是否翻转了k个节点，若不是，则把最后的节点重新翻转一下
                last = hed.next;//重新赋值，当前段的最后一个节点（始终不变，
                                //当前段的最后一个节点相当于开始的第一个节点）
                cur = last;//重新赋值，当前段的第一个节点
                for(int i = 0;i < k && cur != null;i++){
                    temp = cur.next;
                    cur.next = hed.next;
                    hed.next = cur;
                    last.next = temp;
                    cur = temp;
                }
            }
            //更新下一段的头结点和last节点
            hed = last;
            last = cur;
        }
        return top.next;
    }
}
```