题解：
用了近3个小时总算做出来了，
思路：可以理解成将链表看成一条鱼链表，
1， m,n将原链表分成了鱼头链表a，鱼中段链表b，鱼尾链表c，其中（鱼头链表和鱼尾链表可以为空，鱼中段链表不能为空），
2.记录链表a的末尾节点，将链表b反转并记录起始节点，末尾节点，链表c的起始节点。
3.将三个链表拼接起来即可。
时间复杂度：O(n),空间复杂度O(1)
说明：思路理解起来简单，但是写起来挺麻烦的，要考虑多种情况，例如m=n，鱼头链表a或者鱼尾链表c为空等情况，另外指针的操作顺序也很重要，很容易出错，调试才好久才通过。
抛砖引玉，期望有更加简洁优秀的答案



`/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
      if(m==n||head==null) return head;
      int i=1;
      ListNode headEnd=null;//这算是考虑了一种特殊情况把
      ListNode endStart=null;
      ListNode middleStart=null;
      ListNode middleEnd=null;
      ListNode pre=head;
      ListNode node=head;
      ListNode nextNode=null;
      while(node!=null&&i<=n){
        if(i<m-1){
          node=node.next;
          i++;
          continue;
        }
        if(i==1&&m==1){
          //鱼头链表为空，记录鱼中段的尾节点
          middleEnd=head;
          node=node.next;
          i++;
          continue;
        }
        if(i==m-1){
          //记录鱼头的尾节点,鱼中段的尾节点
          headEnd=node;
          pre=node;
          middleEnd=node.next;
          node=node.next;
          i++;
          continue;
        }
        //鱼中段链表反转
        if(i>=m&&i<n){
          nextNode=node.next;
          node.next=pre;
          pre=node;
          node=nextNode;
          i++;
          continue;
        }
        if(i==n){
          //记录鱼中段的头节点
          middleStart=node;
          if(node.next==null){
            //鱼尾链表是空 
            node.next=pre;
            endStart=null;
            break;
            
          }else{
            //鱼尾链表非空，
            endStart=node.next;
            node.next=pre;
            
            break;
          } 
        }      
      }
      //开始连接
      if(headEnd==null){
        //鱼头链表为空
        middleEnd.next=endStart;
        return middleStart;
      }else{
        headEnd.next=middleStart;
        middleEnd.next=endStart;
        return head;
      }
          
}
}`