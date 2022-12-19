执行结果：
执行用时 :2 ms, 在所有 Java 提交中击败了34.64% 的用户
内存消耗 :36.5 MB, 在所有 Java 提交中击败了5.03%的用户

战绩十分感人 ，想不明白为什么是一个这么差的结果，可能是我对时间复杂度和空间复杂度的理解有问题吧

思路：前面快慢指针检查有没有环就不说了  。说一下我后面找入口的想法：
在快慢指针的时候我用一个max变量来记录slow走了多少步，这是我们后面找入口要用的。
前面我们已经知道fast和slow 在环里面相遇了，之后他们会抑制困在环里面出不来。我先走一遍环把他的长度测出来；以1和max为边界进行一次二分查找（可能说不上是二分查找，可以说是二分遍历），每次遍历检查某个节点是否出现在环里面。如果出现在环里面，我们到他的前面看是否有比他更早进入环的节点，否则到他的后面找第一个入环的节点。

个人感触：简单看了几个别的题解，我和他们的区别是： 我是用二分法来遍历，这样有一个问题是：我每次到达中点都要从头开始走过去，但是这样可以少走很多次环（从n→→logn），这样再换很大的情况下可能我的算法更有优势。

```
public ListNode detectCycle(ListNode head) {
        if (head==null)return null;//没有节点
        //先快慢指针来判断是否有环
        ListNode fast=head;
        ListNode slow=head;
        int max=1;//用max来记录slow走了多少步
        while (fast.next!=null&&fast.next.next!=null){//追及相遇
            fast=fast.next.next;
            slow=slow.next;
            max++;
            if (fast==slow)break;
        }
        if (fast.next==null||fast.next.next==null)return null;//有终点没有环 ，否则存在环  开始找入环点
        int length=1;//记录环的长度
        while (true){//测量环的长度
            fast=fast.next;
            if (fast==slow)break;
            else length++;
        }
        int min=1;int mid=0;//二分法查找刚好入环节点
        ListNode res=null;
        while (min<=max){
            mid=(min+max)/2;
            ListNode tmp=head;
            for (int i = 1; i <mid; i++) {//走mid步到我们要测量的点
                tmp=tmp.next;
            }
            for (int i = 0; i <length; i++) {//走一遍环  看会不会经过tmp
                fast=fast.next;
                if (tmp==fast){
                    res=tmp;
                    break;
                }
            }
            if (tmp==res)
                max=mid-1;
            else min=mid+1;
        }
        return res;
    }
```
