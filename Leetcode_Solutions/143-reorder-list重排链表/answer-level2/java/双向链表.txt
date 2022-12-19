思路很简单，直接上代码
```
    public void reorderList(ListNode head) {
        if(head==null){
            return;
        }
        LinkedList<ListNode> list=new LinkedList<>();
        while (head!=null){
            list.addLast(head);
            head=head.next;
        }
        head=list.getFirst();
        list.removeFirst();
        boolean getLast=true;
        while (list.size()!=0){
            if(getLast){
                head.next=list.getLast();
                head=head.next;
                list.removeLast();
                getLast=false;
                if(list.size()==0){
                    head.next=null;
                }
            }else {
                head.next=list.getFirst();
                head=head.next;
                list.removeFirst();
                getLast=true;
                if(list.size()==0){
                    head.next=null;
                }
            }

        }
    }
```
