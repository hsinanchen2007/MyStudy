执行结果：
通过显示详情执行用时 :1 ms, 在所有 Java 提交中击败了96.46%的用户
内存消耗 :39.5 MB, 在所有 Java 提交中击败了5.17%的用户

是看了B站绵羊教授的视频改成的Java，他还有一个递归版的，视频是英文的没听懂就没写。
指路：https://www.bilibili.com/video/av86218140
https://github.com/jzysheep/LeetCode/blob/master/82.%20Remove%20Duplicates%20from%20Sorted%20List%20II%20Solution1.cpp

```
    public ListNode deleteDuplicates(ListNode head) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode prev = dummy;

        while(prev.next != null){
            ListNode n = prev.next;
            while (n.next != null && n.val == n.next.val)
            {
                n = n.next;
            }
            if(n == prev.next){
                prev = prev.next;
            }else{
                prev.next = n.next;
            }
        }
        return dummy.next;
    }
```
