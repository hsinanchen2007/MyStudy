
# JAVA基本思路解题

我觉得基础不好的童鞋跟我的思路应该是一致的，也比较简单，希望各位能看得懂！~

PS：顺便附上本地代码测试用例，付不起会员，只能在idea上写代码了！

**1.通过method方法找到深度链表深度depth；

2.depth的一半就是截取链表的长度，因为depth/2会向下取整，所以初始化depth=1；

3.通过copyListNode截取链表，大功告成；**


```
public class Solution {

    private static int depth = 1;

    public static ListNode middleNode(ListNode head) {
        return copyListNode(head,method(head)/2);
    }

    private static int method(ListNode node){
        if (node.next == null){
            return depth;
        }else {
            depth++;
            return method(node.next);
        }
    }

    private static ListNode copyListNode(ListNode ori,int index){
        while (index > 0){
            index--;
            ori = ori.next;
        }
        return ori;
    }


    public static void main(String[] args) {
        ListNode listNode1 = new ListNode(1);
        ListNode listNode2 = new ListNode(2);
        ListNode listNode3 = new ListNode(3);
        ListNode listNode4 = new ListNode(4);
        ListNode listNode5 = new ListNode(5);
//        ListNode listNode6 = new ListNode(6);
        listNode1.next = listNode2;
        listNode2.next = listNode3;
        listNode3.next = listNode4;
        listNode4.next = listNode5;
        listNode5.next = null;
//        listNode5.next = listNode6;
//        listNode6.next = null;

        middleNode(listNode1);
        System.out.println("1");
    }


    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }
}
```
