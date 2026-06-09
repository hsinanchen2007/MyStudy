![1.bmp](https://pic.leetcode-cn.com/53c4e09708423f97a8693f81a12356ba5aabbf363bd146a9ac54ce445995cc3c-1.bmp)

```
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists == null || lists.length == 0){
            return null;
        }
        int len = lists.length;
        return mergeKListsHelper(lists,0,len-1);
    }

    public ListNode mergeKListsHelper(ListNode[] lists,int begin,int end){
        if(end == begin){
            return lists[begin];
        }
        ListNode left = mergeKListsHelper(lists,begin,(end+begin)/2);
        ListNode right = mergeKListsHelper(lists,(end+begin)/2+1,end);
        //合并
        ListNode tmp = new ListNode(-1);
        ListNode res = tmp;
        while(left!=null && right != null){
            if(left.val<right.val){
                res.next = left;
                left = left.next;
            }else{
                res.next = right;
                right = right.next;
            }
            res = res.next;
        }
        res.next = left==null?right:left;
        return tmp.next;
    }
```
