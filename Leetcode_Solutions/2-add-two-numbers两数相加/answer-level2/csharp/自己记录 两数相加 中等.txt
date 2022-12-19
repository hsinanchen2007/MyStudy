### 解题思路
此处撰写解题思路

### 代码

```csharp
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        int flag=0;   //进位标记
        ListNode start =new  ListNode(0);     // start节点记录结果， 将第一个node先设为{val=0 next=null }
        ListNode nextnode =start;             // 将start的内存 赋予nextnode 节点 此时 nextnode 也是{val=0 next=null }
        while (l1!=null ||l2!=null||flag!=0)   // 如果l1 l2 和进位标记flag之中 有一个有值 就要继续运算
        
         {
            nextnode.next=new ListNode(((l1!=null?l1.val:0)+(l2!=null?l2.val:0)+flag)%10); 
            //将nextnode的下一个节点 赋值为 l1.val+l2.val+进位flag 除10取余 第一次运行时 start和nextnode是{val=0 next={val=(l1.val+l2.val+flag)%10 next=null}}
            nextnode=nextnode.next;  // nextnode的内存换到原来的next的节点  start不变，还是记录所有node  而nextnode只负责运算下一个node 并把内存转到下一个node
            flag = ((l1!=null?l1.val:0)+(l2!=null?l2.val:0)+flag)/10;  //运算是否有进位
            l1=l1!=null?l1.next:null;   // l1 l2  指向next节点
            l2=l2!=null?l2.next:null;
        }
        return start.next;   //运算结束时start里存的是{val=0 next={val=result1 next={val=result2 next={......}}}}  因为第一个点是定义start时插入的val=0 所以答案要舍弃第一个点 故 start.next
    }
}
```



执行用时 :
132 ms
, 在所有 C# 提交中击败了
54.56%
的用户
内存消耗 :
27.7 MB
, 在所有 C# 提交中击败了
5.17%
的用户