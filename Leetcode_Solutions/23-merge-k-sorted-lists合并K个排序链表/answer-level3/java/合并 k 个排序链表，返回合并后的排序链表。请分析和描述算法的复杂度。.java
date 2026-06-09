### 解题思路
//单链表
 public class ListNode {
     int val;
     ListNode next;
      ListNode(int x) { val = x; }
 }

合并k个有序单链表，我们可以将问题拆分  先将连个有序链表进行合并l;
当两个有序链表进行比对时 既
        l1.val<l2.val   ：l1+ 对比(l1.next,l2)的最小值
        l1.val>=l2.val  : l2+ 对比(l1,l2.next)的最小值
根据总结规律可写出mergetwoLists  方法
然后再进行分析
        1）我这里写的方法时对称进行比对，然后将比对合并的结果放回l1链表中  进行一轮合并后，我们就将数组的后半部分合并到前部分，由此可知，我们要在进行合并  直至数组的len为1；
        2）其实也可以逐个比对，
                代码如下：


        public ListNode mergeKLists(ListNode[] lists) {
             int len=lists.length;
                if(len==0){return null;}
                for(int i=0;i<len-1;i++){
                    lists[i+1]=mergetwoLists(lists[i],lists[i+1]);
                }
           
                    return lists[len-1];
                  }
    }

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
    public static ListNode mergetwoLists(ListNode l1,ListNode l2){
        if(l2==null){
            return l1;
        }
        if(l1==null){
            return l2;
        }
        if(l1.val<l2.val){
              l1.next=  mergetwoLists(l1.next,l2);
            return l1;
        }else{
             l2.next= mergetwoLists(l1,l2.next);
            return l2;
        }
    }
    public ListNode mergeKLists(ListNode[] lists) {
      int len=lists.length;
        if(len==0){return null;}
        while(len>1){
            for(int i=0;i<len/2;i++){
                lists[i]=mergetwoLists(lists[i],lists[len-1-i]);
            }
            len=len-len/2;
           
        }
                    return lists[0];
                  }
    }
        
```