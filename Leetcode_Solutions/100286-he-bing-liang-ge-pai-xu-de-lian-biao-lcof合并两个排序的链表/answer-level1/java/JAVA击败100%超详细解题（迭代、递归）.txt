[楼主个人博客，欢迎关注，留言必回哈](https://blog.csdn.net/qq_36929361)

## 解题分析
这是一道非常常见并且简单的链表面试题；

首先是两个有序链表进行合并，切合并完还是要有序的链表，我们可以比较两个有序链表的头节点的大小，然后小的成为新的链表的头节点，然后再拿这个小的节点的下一个节点和比较大的链表的头节点比较，小的成为新的头节点之后的节点；以此类推；直到，一个链表的所有节点都已经进入了新的链表中，那么剩下这个链表直接嵌入到新的链表中即可；

其实，这个不难理解，加入我们有两队小学3年级的同学，在操场上按个头高低站队，现在两个班级要合在一起去跑圈，那就是两个班级各自最矮的一个先出列（也就是站在最前面的两个人中的一个），然后再在两个班级中剩下的人依次选出最矮的跟上，一旦一个班级的人都出列了，那么剩下一个班级剩下的人直接都跟上就好了，因为原来就是按照大小个去排的；

按照这个思路，我们就可以实现第一种算法，循环法；先定义一个虚拟节点（这样可以省去判断头节点是否为空的时间，链表中经常使用虚拟头节点来减少判断），然后进入一个循环，在循环中依次取出两个链表中剩余节点的最小元素，依次挂在新链表的后面即可，一旦一个没有了节点，剩下一个链表直接挂到新链表结尾即可；

这种做法不需要多余的空间存储变量，只需要遍历一遍两个链表即可（最坏的情况），时间复杂度是O(m+n)，最好的情况就是一个链表最小的元素都比另外一个链表最大的元素大，这样时间复杂度就是O(n)；

---
还有一种方式就是通过递归，使用虚拟机栈的栈结构，把两个链表中最小的元素一次拼成一个链表，最后返回这个链表的头节点，这种做法的时间复杂度和👆的一致，但是空间上，由于递归的高度，空间复杂度可能较高；但是写一遍可以有助于更深刻的理解递归，所以建议大家手写一下，加深对递归的印象，我这里就不多做介绍，代码会一起贴出来，有不会的同学可以给我留言，我一定解答；

## 代码（JAVA实现）
ps：这里笔者使用的jdk为1.8版本
- 循环
```java
public class Merge {

    public static void main(String[] args) {
        ListNode merge = merge(LinkedListUtil.getLinkedList(new int[]{1, 3, 5, 7, 9}), LinkedListUtil.getLinkedList(new int[]{1, 2, 4, 7, 10}));
        LinkedListUtil.printLinkedList(merge);
    }

    /* 循环解法 */
    public static ListNode merge(ListNode list1, ListNode list2) {
        ListNode vir = new ListNode(-1);
        ListNode pointer = vir;
        while (true) {
            if (Objects.isNull(list1)) {
                pointer.next = list2;
                break;
            }
            if (Objects.isNull(list2)) {
                pointer.next = list1;
                break;
            }
            if (list1.val <= list2.val) {
                pointer.next = list1;
                list1 = list1.next;
            } else {
                pointer.next = list2;
                list2 = list2.next;
            }
            pointer = pointer.next;
        }
        return vir.next;
    }
}

```
- 递归
```java
public class Merge {

    public static void main(String[] args) {
        ListNode merge = merge(LinkedListUtil.getLinkedList(new int[]{1, 3, 5, 7, 9}), LinkedListUtil.getLinkedList(new int[]{1, 2, 4, 7, 10}));
        LinkedListUtil.printLinkedList(merge);
    }
    /* 递归解法 */
    public static ListNode merge(ListNode list1, ListNode list2) {
        if (Objects.isNull(list1) && Objects.isNull(list2)) {
            return null;
        } else if (Objects.isNull(list1)) {
            return list2;
        } else if (Objects.isNull(list2)) {
            return list1;
        }

        if (list1.val <= list2.val) {
            list1.next = merge(list1.next, list2);
            return list1;
        } else {
            list2.next = merge(list2.next, list1);
            return list2;
        }
    }
}

```
LinkedListUtil为笔者自定义的链表工具类，代码如下：

```java
public class LinkedListUtil {

    /**
     * 获取一个链表
     */
    public static ListNode getLinkedList(int[] numbers) {

        if (numbers == null || numbers.length == 0) {
            return null;
        }

        ListNode first = new ListNode(numbers[0]);
        ListNode intermediateVariables = first;

        for (int i = 1; i < numbers.length; i++) {
            ListNode temp = new ListNode(numbers[i]);
            intermediateVariables.next = temp;
            intermediateVariables = intermediateVariables.next;
        }

        return first;
    }

    /**
     * 打印一个链表
     */
    public static void printLinkedList(ListNode first) {
        ListNode intermediateVariables = first;

        while (!Objects.isNull(intermediateVariables)) {

            System.out.printf("%s-> ", intermediateVariables.val);
            intermediateVariables = intermediateVariables.next;
        }
        System.out.println();

    }

    // 测试工具类
    public static void main(String[] args) {
        printLinkedList(getLinkedList(new int[]{1, 2, 3, 4, 5, 6, 7}));
    }
}
```
