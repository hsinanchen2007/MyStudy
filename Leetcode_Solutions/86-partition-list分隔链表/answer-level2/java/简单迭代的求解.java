### 解题思路
理解题意理解了半天。。
举个例子说一下，就拿题的例子，小于3的节点1,2,2在链表左侧，大于等于3的节点4,3,5在右侧，同时每一侧的若干节点排列顺序要和初始的保持一致。
**首先先理清下链表的插入过程，接着拿题的例子{1,4,3,2,5,2}**
1. 遍历到2的时候将2移到左侧，同时要保持顺序插在1后边，此时链表{1,2,4,3,5,2}
2. 到最后一个2时，继续插入左侧，同时保持顺序，此时链表{1,2,2,4,3,5}

**程序实现**
1. 通过插入的过程，可以发现当找到一个小于x值得节点时，将该节点插入到一个左边小于x，右边大于x的节点中间。
2. 所以最开始，要先找到首个大于x值的节点，就称为firstBig，每遍历到一个小于x值的节点，就将该节点插入到firstBig节点之前，之后就是比较多的next指针指向的变化和空值临界的判断，这里细心操作就行了。
3. 同时为了方便操作，首先定义一个空节点指向头结点


### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode partition(ListNode head, int x) {
        //空节点
        ListNode emptyHead = new ListNode(0);
        emptyHead.next = head;
        //插入指针，小于x的节点都插入到该指针后方
        ListNode insert = emptyHead;
        //遍历指针
        ListNode point = emptyHead;
        //临时指针，指向遍历到的小于x值的节点，方便操作
        ListNode temp = null;
        //首先找到首个大于等于x值的节点
        while(insert.next != null && insert.next.val < x){
            insert = insert.next;
        }
        point = insert.next;
        while (point != null && point.next != null){
            if(point.next.val < x){
                //找到小于x值的节点，将其插入到指定位置，同时调整其他指针的指向
                temp = point.next;
                point.next = temp.next;
                temp.next = insert.next;
                insert.next = temp;
                insert = insert.next;
            }
            else{
                point = point.next;
            }
        }
        return emptyHead.next;
    }
    
}
```