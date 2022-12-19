主要的思路其实就是采用了双指针的方法，挨个比较元素的大小。把l1当成目标链表，把l2插入到l1.
当时l2>l1的时候，l2一直向后扫，当l2<l1的时候，将l2插入到l1中，因为要在l1前面插入，所以每次必须保留l1的前一个指针，这样才能插入，不然找不到位置。
考虑的临界点：1.当pre=null，也就是l1当前是head指针的时候，需要把l2插入到l1前面，并且更新l1的head
2. 当l2为null，直接返回l1，当l1为null，这里要判断l1本身为null还是扫描之后得到的null


怎么说呢，有点麻烦，考虑的情况有点多，不过用了一个双指针，就当熟练一下了



    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode pre = null;
        ListNode cur = l1;
        while(cur!=null&&l2!=null){
            if(cur.val <= l2.val){
                pre = cur;
                cur=cur.next;
            }
            else{
                if(pre!=null){
                    ListNode p = l2;
                    l2 = l2.next;
                    pre.next = p;
                    p.next = cur;
                    pre = pre.next;
                    
                }
                else{
                    ListNode p = l2;
                    l2 = l2.next;
                    p.next = cur;
                    cur = p;
                    l1 = cur;
                    pre = cur;
                    cur = cur.next;
                    
                }
            }
        }
        if(l2==null){
            return l1;
        }
        else if(cur ==null){
            if(pre==null){
                return l2;
            }
            
            pre.next = l2;
        }
        
        return l1;
