JAVA 的简单实现

class Solution {
    public void deleteNode(ListNode node) {
        while(node.next.next!=null){
            node.val=node.next.val;
            node=node.next;
        }
        node.val=node.next.val;
        node.next=null;
    }
}