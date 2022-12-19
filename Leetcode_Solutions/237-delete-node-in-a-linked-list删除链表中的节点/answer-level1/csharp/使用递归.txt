
public void DeleteNode(ListNode node) {
    node.val = node.next.val;
    if(node.next.next != null){
        DeleteNode(node.next);
    }else{
        //这里要注意将倒数第二个节点设为为节点
        node.next = null;
    }
}

想问一下大佬，有没有在内存消耗上更简洁的代码？还有我这个有哪些可以改进的地方？