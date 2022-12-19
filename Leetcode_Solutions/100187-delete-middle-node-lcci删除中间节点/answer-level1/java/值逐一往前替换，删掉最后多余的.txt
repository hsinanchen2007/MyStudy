![1585643756(1).jpg](https://pic.leetcode-cn.com/4a4b52817816f58104e84cd0135bc5fd65fe477ef507d11dce51afe031ab6bab-1585643756\(1\).jpg)



public  void deleteNode(ListNode node) {
        //将下一个节点的值往前替换
        ListNode next=node.next;
        node.val=next.val;
        //如果下节点的下节点是null 链表末端的两个应该删掉
        if(next.next==null){
            node.next=null;
        }else {
            //重复下个节点
            deleteNode(next);
        }

    }
