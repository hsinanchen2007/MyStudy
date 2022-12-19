  public void deleteNode(ListNode node) {
<!-- 若不考虑头尾可以去掉第一个判断 -->
        if(node.next == null){
            node = null;
        }else{
            node.val = node.next.val;
            node.next = node.next.next;
        }
        
    }