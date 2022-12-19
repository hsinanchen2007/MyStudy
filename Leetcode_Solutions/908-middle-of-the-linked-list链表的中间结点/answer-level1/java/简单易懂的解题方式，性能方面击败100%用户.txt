![image.png](https://pic.leetcode-cn.com/1802daab04c6ebda315426fd07e0e7e1ec2dcb481eca0ac9375535154082c3b8-image.png)

开始时middle指向head，然后弄一个计数器，偶数时middle向后移一个即可

```
public ListNode middleNode(ListNode head) {
        ListNode middle=head;
        int num=0;
        ListNode temp=head;
        while ((temp=temp.next)!=null){
           if(num%2==0){
                middle=middle.next;
            }
            num++;
        }
        return middle;
    }
```
