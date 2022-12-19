定义数值长度为 n,中间节点的位置为mid,根据题目要求，可以发现如下规律：
n=1时，mid=1;
n=2时，mid=2;
n=3时，mid=2;
n=4时，mid=3;
n=5时，mid=3;
n=6时，mid=4;
n=7时，mid=4;
n=8时，mid=5;
n=9时，mid=5;
...
相比大家已经发现了规律，当n=1时，mid=1 当n>1时 mid=n/2+1；但由于这是一个链表，只有遍历之后才能知道长度n,且即使知道了也无法直接定位到mid,获取其数值和next;
因此需要再一次解读这个规律，可以发现，mid的值是间隔性的增长，因此可以使用一个flag，遍历链表时，flag=true时，mid+1,flag=false时，mid不变，代码如下：
```
   if (head.next == null) {
            return head;
        }

        ListNode listNode = head;

        boolean flag = true;
        do {
            head = head.next;
            if (flag) {
                listNode = listNode.next;
            }

            flag = !flag;

        } while (null != head.next);

        return listNode;
```
