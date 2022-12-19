刚接触链表 实在懵得很 写增上改查写太多了 
链表其实概念类似于火车 我脑袋想的时候是想成火车一般的 

其实完全理解之后 发现这题得出结果是没有难度的 重点就是考察一个指标 也有锚点 这个锚点是一个对象 指向了当前操作车厢的地址 
理解了这个 基本上这题就过了
```
public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        int x=0,y=0,z=0;
        int pull=0;
        ListNode nodeAll=new ListNode(0);//这是火车
        ListNode nextNode=nodeAll;//这是锚点
        while(l1!=null||l2!=null){

            x=l1!=null?l1.val:0;
            y=l2!=null?l2.val:0;
            z=x+y+pull;//将本次总和计入 并计入上次总和
            pull=0;//上次总和置为0
            if(z>=10){//这一块处理当前节点的总和
                pull+=1;
                z-=10;
            }
            l1=l1!=null?l1.next:null;//进入下一节点
            l2=l2!=null? l2.next:null;//进入下一节点            
            ListNode newnode=new ListNode(z);
            if(pull>0)
            newnode.next=new ListNode(pull);
            nextNode.next=newnode;//我组装一个车厢之后 
            nextNode=nextNode.next;//切换锚点到这个车厢
        }
        return nodeAll.next;
    }
}
```
