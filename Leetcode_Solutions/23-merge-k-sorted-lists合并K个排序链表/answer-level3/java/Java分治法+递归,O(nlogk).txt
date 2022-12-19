- 执行用时 :6 ms, 在所有 Java 提交中击败了84.45%的用户
- 内存消耗 :42.4 MB, 在所有 Java 提交中击败了74.44%的用户

思想就是list两两合并(递归实现)需要O(logk),合并时需要排序等操作需要O(n),总的时间复杂度为O(nlogk),我的代码比较好理解：
```Java []
class Solution {
    
    /**
     * 合并 k 个排序链表，返回合并后的排序链表。
     * 两两合并,分治法,O(nlogk)
     * @param lists
     * @return
     */
    public ListNode mergeKLists(ListNode[] lists) {
        int len=lists.length;
        if(len<1) return null;
        if (len==1) return lists[0];
        //分解list1
        ListNode[] ps11 = new ListNode[len/2],ps12 = new ListNode[len/2];
        System.arraycopy(lists,0,ps11,0,len/2);
        System.arraycopy(lists,len/2,ps12,0,len/2);
        //判断lists[]长度为奇数还是偶数
        return len%2==0?mergeList(ps11,ps12):mergeListNode(lists[len-1],mergeList(ps11,ps12));
    }

    /**
     * 分治法,递归,O(nlogk)
     * @param list1
     * @param list2
     */
    private static ListNode mergeList(ListNode[] list1,ListNode[] list2){
        int len1=list1.length,len2=list2.length;
        if (len1<=1&&len2<=1) {
            return mergeListNode(list1[0],list2[0]);
        }else {
            //分解list1
            ListNode[] ps11 = new ListNode[len1/2],ps12 = new ListNode[len1/2];
            System.arraycopy(list1,0,ps11,0,len1/2);
            System.arraycopy(list1,len1/2,ps12,0,len1/2);
            //分解list2
            ListNode[] ps21 = new ListNode[len2/2],ps22 = new ListNode[len2/2];
            System.arraycopy(list2,0,ps21,0,len2/2);
            System.arraycopy(list2,len2/2,ps22,0,len2/2);
            //如果两个list[]长度均为奇数
            if (len1%2!=0&&len2%2!=0){
                return mergeListNode(
                        mergeListNode(list1[len1-1],list2[len2-1]),
                        mergeListNode(mergeList(ps11,ps12),mergeList(ps21,ps22))
                );
            }else if (len1%2!=0){
                //如果list1[]长度为奇数
                return mergeListNode(
                        list1[len1-1],
                        mergeListNode(mergeList(ps11,ps12),mergeList(ps21,ps22))
                        );
            }else if(len2%2!=0) {
                //如果list2[]长度为奇数
                return mergeListNode(
                        mergeListNode(mergeList(ps11,ps12),mergeList(ps21,ps22)),
                        list2[len2-1]
                        );
            }else {
                //如果均为偶数
                return mergeListNode(mergeList(ps11,ps12),mergeList(ps21,ps22));
            }
        }
    }

    /**
     * 合并两个链表
     * @param l1
     * @param l2
     * @return
     */
    private static ListNode mergeListNode(ListNode l1, ListNode l2){
        ListNode dummyhead=new ListNode(0);
        merge(dummyhead,l1,l2);
        return dummyhead.next;
    }

    /**
     * 递归合并
     * @param head
     * @param l1
     * @param l2
     * @return
     */
    private static void merge(ListNode head, ListNode l1, ListNode l2) {
        if (l1 != null && l2 != null) {
            //把head.next和l1.next放到下一轮递归
            if (l1.val <= l2.val) {
                head.next = l1;
                ListNode p = l1.next;
                l1.next = null;
                merge(head.next, p, l2);
            } else {
                //把head.next和l2.next放到下一轮递归
                head.next = l2;
                ListNode p = l2.next;
                l2.next = null;
                merge(head.next, l1, p);
            }
        }
        if (l1 == null && l2 == null) ;
        if (l1 == null && l2 != null) {
            //把head.next和l2.next放到下一轮递归
            head.next = l2;
            ListNode p = l2.next;
            l2.next = null;
            merge(head.next, l1, p);

        }
        if (l1 != null && l2 == null) {
            //把head.next和l1.next放到下一轮递归
            head.next = l1;
            ListNode p = l1.next;
            l1.next = null;
            merge(head.next, p, l2);
        }
    }
}
```