```
class Solution {
    public ListNode insertionSortList(ListNode head) {
        ListNode dummy = new ListNode(Integer.MIN_VALUE);
        ListNode p = dummy;
        p.next = head;
        while (p!=null){
            if(p.next == null){
                break;
            }
            if(p.next.val < p.val){
                ListNode temp = p.next;
                removeNextNodeAndReturn(p);
                ListNode posToInsert = findPostToInsert(dummy, temp);
                insertAfter(posToInsert, temp);
            }else{
                p = p.next;
            }
        }
        return dummy.next;
    }
    private ListNode findPostToInsert(ListNode dummyHeadNode, ListNode nodeToBeSearch){
        ListNode p = dummyHeadNode;
        while (p!=null){
            if(p.next.val > nodeToBeSearch.val){
                return p;
            }
            p = p.next;
        }
        return null;
    }

    private void insertAfter(ListNode head, ListNode toBeInserted) {
        toBeInserted.next = head.next;
        head.next = toBeInserted;
    }
    private void removeNextNodeAndReturn(ListNode head) {
        ListNode temp = head.next;
        head.next = temp.next;
        temp.next = null;
    }
}
```
从头到尾用p遍历。如果发现p.next比p小，就把p.next(记为temp)移出链表，从头开始找temp合适的位置，插入。否则p后移一个。
时间复杂度同插入排序，最坏O(n2)

其他问题：
1. 有个叫removeNextNodeAndReturn的函数，他的返回值是void（- -），因为发现ListNode temp = p.next;removeNextNodeAndReturn(p);比ListNode temp = removeNextNodeAndReturn(p)快。
2. findPostToInsert(dummy, temp)这个是和if(p.next.val < p.val)有关系的，如果if不满足，返回null的。所以代码结构很有问题的，但是这样可以减少搜索长度。
                


