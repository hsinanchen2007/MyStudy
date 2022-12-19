```
class Solution {
    public Node copyRandomList(Node head) {
        if(head == null) {
            return head;
        }
        HashMap<Node, Node> map = new HashMap<>();
        Node dummy = new Node(0);
        Node newHead = new Node(head.val);
        map.put(head, newHead);
        dummy.next = newHead;
        while(head != null) {
            Node myHead = map.get(head);
            if(!map.containsKey(head.random) && head.random != null) {
                Node newRandom = new Node(head.random.val);
                map.put(head.random, newRandom);
            }
            myHead.random = map.get(head.random);
                
            if(head.next != null && !map.containsKey(head.next)) {
                map.put(head.next, new Node(head.next.val));
            }
            myHead.next = map.get(head.next);
            head = head.next;
        }

        return dummy.next;
    }
}
```
