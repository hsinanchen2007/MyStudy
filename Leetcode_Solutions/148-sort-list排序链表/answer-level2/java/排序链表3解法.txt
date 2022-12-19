### 解题思路
**Solution1**
1. 一开始想到的就是使用快排了，但是貌似空间复杂度不是O（1），算了，先写出来在说吧，快排都忘了咋写了。。。
2. 快排的思路主要是选择一个哨兵，然后将序列中小于哨兵的放在左侧，大于的放在右侧。然后在将左侧和右侧重复操作。
3. 快排的实现思路有两种，一种是单向，一种是双向。
4. 单向适用于链表，本题用的是这个思路。因为是单链表，所以哨兵选择head结点，然后定义两个指针，一个指向head，名为first，一个指向head.next，名为second。快排的判出条件是head为空或等于tail。
5. second遍历链表直至tail（不包含），如果second的值小于哨兵的值，说明second的值应该放在前面，first指向下一个结点，如果first不等于second，交换f和s的val值。因为如果相等，没必要交换。可见，first指向的结点及其左侧小于哨兵，右侧至second（不包含）大于哨兵。
6. 最后遍历结束后，需要交换first和哨兵的val。因为first是分界点的左侧（first指向的值小于哨兵）
7. 递归。
8. 
**Solution2**
1. 一开始也想到归并排序，但是在找中间点的地方卡了一下，就没有细想。
2. 参考了评论席上的各路大鸟，发现归并挺合适的。
3. 找中间点的方法利用了快慢指针，并且有一个pre指向慢指针的前节点，用于分割字符串。
4. 字符串的归并，要把字符串切割再合并。思想和数组的很像。主要难点在于切割时的结点以及合并的哑结点的设置，需要细心。
5. 
**Solution3**
1. 归并排序的非递归方法，采用从底向上的思想，首先两两结点归并，然后四四，然后八八。。
2. 关键在于得到链表长度后，将链表进行切割，因此定义了一个切割函数。通过输入头结点和要切割的长度完成切割，并返回剩余链表的头结点。
3. 然后在主函数中，设置哑头结点，第一轮将切割后合并的字符串插入到哑结点之后，然后tail指针右移到尾部，等待继续插入。代码的关键在于哑结点和切割函数的配合，判出条件的设置等。
4. 
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
class Solution1 {
    public ListNode sortList(ListNode head) {
        if(head == null || head.next == null) return head;
        quickSort(head, null);
        return head;
    }

    public void quickSort(ListNode head, ListNode tail){
        if(head == tail || head.next == tail) return;
        ListNode first = head, second = head.next;
        while(second != tail){
            if(second.val < head.val){
                first = first.next;
                if(first != second){
                    int tmp = first.val;
                    first.val = second.val;
                    second.val = tmp;
                }    
            }
            second = second.next;
        }
        int tmp = first.val;
        first.val = head.val;
        head.val = tmp;

        quickSort(head, first);
        quickSort(first.next, tail);
    }
}

class Solution2 {
    public ListNode sortList(ListNode head) {
        return head == null ? null : mergeSort(head);
    }

    public ListNode mergeSort(ListNode head){
        if(head.next == null) return head;
        ListNode p = head, q = head, pre = null;
        while(q != null && q.next != null){
            pre = p;
            p = p.next;
            q = q.next.next;
        }
        pre.next = null;
        ListNode l = mergeSort(head);
        ListNode r = mergeSort(p);
        return merge(l, r);
    }

    public ListNode merge(ListNode left, ListNode right){
        ListNode dummy = new ListNode(0), cur = dummy;
        while(left != null && right != null){
            if(left.val < right.val){
                cur.next = left;
                left = left.next;
            }
            else{
                cur.next = right;
                right = right.next;   
            }
            cur = cur.next;
        }
        if(left != null) cur.next = left;
        if(right != null) cur.next = right;
        return dummy.next;
    }
}

class Solution3 {
    public ListNode sortList(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode p = head;
        int length = 0;
        while(p != null){
            length++;
            p = p.next;
        }
        for(int i = 1; i < length; i <<= 1){
            ListNode cur = dummy.next;
            ListNode tail = dummy;
            while(cur != null){
                ListNode left = cur;
                ListNode right = cut(left, i);
                cur = cut(right, i);

                tail.next = merge(left, right);
                while(tail.next != null) tail = tail.next;
            }
        }
        return dummy.next;
    }

    public ListNode cut(ListNode head, int n){
        ListNode p = head;
        while(n-- > 1 && p != null) p = p.next;
        if(p == null) return null;
        ListNode res = p.next;
        p.next = null;
        return res;
    }

    public ListNode merge(ListNode left, ListNode right){
        ListNode dummy = new ListNode(0), cur = dummy;
        while(left != null && right != null){
            if(left.val < right.val){
                cur.next = left;
                left = left.next;
            }
            else{
                cur.next = right;
                right = right.next;   
            }
            cur = cur.next;
        }
        if(left != null) cur.next = left;
        if(right != null) cur.next = right;
        return dummy.next;
    }
}
```