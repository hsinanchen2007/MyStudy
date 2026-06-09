### 解题思路
此处撰写解题思路
![IMG_20200402_122210.jpg](https://pic.leetcode-cn.com/5ea19911668192f267602a59208632eba3ec3e7e7118ec61ff21bcabf7deae4e-IMG_20200402_122210.jpg)



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
    public ListNode swapPairs(ListNode head) {
        if(head==null || head.next == null){
            return head;
        }
        
        // 返回值为初始头结点的第二个节点，第二个节点变成头了
        ListNode back =head.next;

        ListNode pre =null;
        ListNode cur =head;
        ListNode next =null;
        ListNode tempCur =null;
        ListNode tempPre =null;
        ListNode tempNext =null;
        while(cur!=null){
            next = cur.next;
            tempPre = cur;
            //此处处理链表为单数情况，即最后一个单数不处理
            if(next!=null){
                tempCur = next.next;
            }else{
                //直接退出循环返回结果即可
                break;
            }
            // 第一个前向节点为空，不处理指针链接情况
            if(tempCur!=null){
                tempNext = tempCur.next;
            }
            
            // 共执行三步指针交换，必须注意pre节点不能顺序移动，
            // 它的位置上前一二个节点已经交换了位置
            next.next = cur;
            cur.next = tempCur;
            if(pre!=null){
                pre.next = next;
            }
            pre = tempPre;
            cur = tempCur;
            next = tempNext;
        }
        return back;

    }
}
