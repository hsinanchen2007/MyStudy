# 提交结果
![k个一组翻转.png](https://pic.leetcode-cn.com/17bfc4d9e5065a57be5013bd773d56e2dc9dc7b068690df6c68113ab3fac8868-k%E4%B8%AA%E4%B8%80%E7%BB%84%E7%BF%BB%E8%BD%AC.png)
# 思想
    1. 对每一个组k个节点，找到k个节点的第一个节点ptr,第k个节点tail，以及k+1个节点next。如果不足k个，退出
    2. 通过第一个节点和第k个节点很容易写一个函数翻转这k个节点，返回翻转后的节点头，记为temp
    3. 得到翻转后的头节点temp后，现在可以将这一组节点看成一个整体temp,将原先第一个节点ptr也就是现在翻转后的尾节点与第k+1个节点next连接。
    4. 返回第1步。
# 代码
```
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) 
    {
        ListNode fakeHead=new ListNode(0);
        fakeHead.next=head;
        ListNode pre=fakeHead;
        ListNode ptr=pre.next;
        int count=1;
        while(ptr!=null&&ptr.next!=null)
        {
            count=k;
            ListNode point=ptr;
            while(--count>0&&point.next!=null)//寻找一组k个节点
            {
                point=point.next;
            }
            if(count>0)break;//如果余下的不够k个，退出。
            ListNode next=point.next;//next为k个节点的后一个节点
            ListNode temp=rollBack(ptr,point);//temp返回k个节点倒置后的头节点

            pre.next=temp;
            ptr.next=next;//交换

            pre=ptr;
            ptr=next;
        }
        pre.next=ptr;//！重要，连接整理最后的节点
        return fakeHead.next;
    }
    private ListNode rollBack(ListNode head,ListNode tail)//head为重排节点组的第一个，tail为最后一个
    {
        ListNode ptr=head;
        ListNode temp=ptr.next;
        while(ptr!=tail)//倒置节点，如果ptr到了最后一个节点，那就不必要了
        {
            ListNode tnext=temp.next;
            temp.next=ptr;
            ptr=temp;
            temp=tnext;
        }
        return ptr;
    }
}
```
