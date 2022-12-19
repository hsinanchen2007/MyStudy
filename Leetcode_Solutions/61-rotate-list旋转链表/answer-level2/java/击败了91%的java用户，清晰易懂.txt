# 解析
这道题的思路还是很清晰的。
1.求出链表的长度len
2.k = k%len取余就是我们要右移的距离。
3.找到倒数第k个位置。可以使用双指针法。
4.记录慢指针的next节点，这就是最后要返回的节点。
后边的过程看图解
![图片.png](https://pic.leetcode-cn.com/08afd991d5aa8171c3daa0edf0c4e3dd46094d94e34e114f47f01b6b01d50f38-%E5%9B%BE%E7%89%87.png)
# 代码
```
public ListNode rotateRight(ListNode head, int k) {

        if (head == null || k == 0) {
            return head;
        }
        ListNode tmp = head;
        int len = 0;
        //求出链表的长度
        while (tmp != null) {
            tmp = tmp.next;
            len++;
        }
        k = k % len;  //以len为一个周期
        if (k == 0) {
            return head;
        }
        //保存一下头节点
        ListNode node = head;
        //快慢指针
        tmp = head;
        while (k > 0) {
            k--;
            tmp = tmp.next;
        }
        while (tmp.next != null) {
            head = head.next;
            tmp = tmp.next;
        }
        //记录next的位置，也就是返回值的头结点
        ListNode res = head.next;
        //断开连接
        head.next = null;
        //后一段的末尾指向前一段的开头
        tmp.next = node;
        return res;

    }
```
本人建了个公众号用于刷题交流，欢迎关注：
![qrcode_for_gh_8eedbc428c9a_258(1).jpg](https://pic.leetcode-cn.com/e5f794b173fbe256a541447fc7ff8e6eb031774890bdfdb48ca3c7866dc81dc2-qrcode_for_gh_8eedbc428c9a_258\(1\).jpg)