![微信图片_20191226162854.png](https://pic.leetcode-cn.com/551a609fca4b8e82c667614a05a488f128f7b4066c2b1f701d852820fac1774f-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20191226162854.png)
```
/*
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
                        输入:
                        [
                          1->4->5,
                          1->3->4,
                          2->6
                        ]
                        输出: 1->1->2->3->4->4->5->6
解题思路：分治？？？
不重要的话：第一次拿100%，有点开心，记录一下
 */
class Solution
{
    public ListNode mergeKLists(ListNode[] lists)
    {
        int length=lists.length;
        if(length==0) return null;
        while(length!=1)    //0,1,2,3,4,5,6  (7)  /2=3 %2=1       0,1,2,3,4,5  (6)  /2=3 %2=0
        {
            for(int i=0; i<length/2; i++)
                lists[i]=compare(lists[i],lists[length-i-1]);
            length=length/2+length%2;
        }
        return lists[0];
    }
    public ListNode compare(ListNode list1, ListNode list2)  //合并2个链表,以前做过；
    {
        ListNode res=new ListNode(1);
        ListNode temp=res;
        ListNode temp1=list1;
        ListNode temp2=list2;
        while(temp1!=null && temp2!=null)   //节点和null比较而不是与当前值比较
        {
            if(temp1.val<=temp2.val)
            {
                temp.next=temp1; temp1=temp1.next; temp=temp.next;
            }
            else
            {
                temp.next=temp2; temp2=temp2.next; temp=temp.next;
            }
        }
        temp.next=(temp1==null)?temp2:temp1;
        return res.next;
    }
}

```


```