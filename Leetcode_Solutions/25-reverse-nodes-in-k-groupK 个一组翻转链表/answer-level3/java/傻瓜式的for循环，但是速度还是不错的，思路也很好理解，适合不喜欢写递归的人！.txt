### 解题思路
此处撰写解题思路
本人是一个不爱写递归的傲娇人（主要是不会写）。所以一开始在思考这道题的时候，就在想该如何来通过简单的for循环就能解决。
由于单项列表只能找到每个结点的下一个结点，而无法找到他的上一个，所以限制了我们在进行结点交换的时候，只能从前往后。（之所以这么说，因为我不用递归呀！）
接下来就来讲解一下具体的操作流程。
首先我们从简单的说起，对于一个固定的长度的链表，我们如何将它通过gfor循环倒序呢？看图（对于1234）：
首先找到他的最后一个结点，然后从头节点开始，依次交换到尾结点的后面：
![1.png](https://pic.leetcode-cn.com/358102489a172ec7d3412f496fdef47aca4d5b5c5358030efa1d1266d03ad030-1.png)

这是对于一个固定长度的链表进行倒序的方法，原理很简单，写得过程中要注意更新头节点；
那么对于这道题目而言，复杂的在于对于一个链表和参数k；
首先通过for循环，找到第一个k个结点的子列表，利用刚刚的方法进行逆序。
注意，在第一次倒序的时候，要记录头节点，这将是最后返回的结点。
同时,每一次逆序的时候，需要记录倒序完成后的最后一个结点，这将是第二个k个结点倒序时的承接的点，并通过此点索引到下一个K！
推出循环的标志是索引到的结点为null！
![image.png](https://pic.leetcode-cn.com/651f87242285b4112f4b030463b2bb2866d3fc029a2210c7ee1012b424c17038-image.png)

（工科女吊丝第一次写思路，希望大家多多多多包涵）



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
    public ListNode reverseKGroup(ListNode head, int k) {
        if(k==1 || head==null){
            return head;
        }
        ListNode ff=head;
        ListNode tmp_ne=head;
        ListNode ans_head=head;
        ListNode before=head;
        ListNode before_tmp=head;
        int count=0;
        int loop_count=0;
        while(true){
            while(count<k-1 && ff!=null){
                ff=ff.next;
                count+=1;
            }  
            if(ff==null){
                return ans_head;
            } 
            if(loop_count==0){
                for(int i=0;i<k-1;i++){ 
                    ListNode tmp=head.next;  //下一次交换的结点
                    head.next=ff.next; 
                    ff.next=head;                  
                    head=tmp;      
                    if(i==0){
                        tmp_ne=ff.next.next;
                        before_tmp=ff.next;
                    }           
                }                   
                ans_head=head;
            }
            else{
                for(int i=0;i<k-1;i++){ 
                    ListNode tmp=head.next;  
                    head.next=ff.next; 
                    ff.next=head;
                    head=tmp; 
                    before.next=head;  
                    if(i==0){
                        before_tmp=ff.next;
                        tmp_ne=ff.next.next;
                    }                                 
                }  
            }
            before=before_tmp;           
            count=0;
            loop_count+=1;
            ff=tmp_ne;
            head=ff;
        }
    }
}
```