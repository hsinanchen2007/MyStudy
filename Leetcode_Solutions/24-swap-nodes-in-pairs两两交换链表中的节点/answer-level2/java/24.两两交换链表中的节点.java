虽然0ms，但是每次递归都要新建一个节点，内存消耗略高。不用递归直接用循环可能更好。
![1568964086.png](https://pic.leetcode-cn.com/4768df78f80c47412fd57be6d2d4a5a777fe4489974d296af164f5bdbed56ea0-1568964086.png)
``` java
public ListNode swapPairs(ListNode head) {
        if(head == null || head.next == null)//传入节点为空则返回，或者传入节点的下一个节点为空（意味着是奇数个节点）
        {
            return head;
        }
        ListNode temp = new ListNode(0);//新建一个节点用来辅助
        temp.next = head.next;//指向第二个节点
        head.next = swapPairs(head.next.next);//将第三个节点传入递归函数
        temp.next.next = head;

        return temp.next;
    }
```