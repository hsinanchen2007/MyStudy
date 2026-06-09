```
class Solution {
    public Node copyRandomList(Node head) {
        Map<Node, Node> map;
        Node cursor, copy;
        
        if(head == null)
            return null;
        map = new HashMap<>();
        cursor = head;
        while(cursor != null){
            map.put(cursor, new Node(cursor.val, null, null));
            cursor = cursor.next;
        }
        for(Map.Entry<Node, Node> entry : map.entrySet()){
            cursor = entry.getKey();
            copy = entry.getValue();
            copy.next = map.get(cursor.next);
            copy.random = map.get(cursor.random);
        }
        return map.get(head);
    }
}

```
