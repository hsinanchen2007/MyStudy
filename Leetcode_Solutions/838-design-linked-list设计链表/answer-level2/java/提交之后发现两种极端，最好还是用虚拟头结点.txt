![image.png](https://pic.leetcode-cn.com/b886b1e67fce71edfce0dd3323e4e5367d6992724c60d708edeba3203c2244c2-image.png)

```
class MyLinkedList {
    
    public Node head;
    public int size;
    //结点类
   private class Node{
        int val;
        Node next;
       public Node(){}
       public Node(int val){
            this.val = val;
            this.next = null;
        }
    }
    public MyLinkedList() {
        head = new Node();
        size = 0;
    }
    
    
    public int get(int index) {
        if(index >= size || index < 0)return -1;
        Node p = head;
        int i = -1;
        while(i < index){
            p = p.next;
            i++;
        }
        return p.val;
    }
    
    public void addAtHead(int val) {
        addAtIndex(0,val);
    }
    
    public void addAtTail(int val) {
        addAtIndex(size,val);
    }
    
    public void addAtIndex(int index, int val) {
        Node p = head;
        int i = -1;
        if(index >= 0 && index <= size){
            Node node = new Node(val);
            if(index == 0){
                node.next = head.next;
                head.next = node;
            }else{
                while(i < index-1){
                    p = p.next;
                    i++;
                }
                node.next = p.next;
                p.next = node;
            }
            size++;
        }
    }
    
    public void deleteAtIndex(int index) {
        if(index >= 0 && index < size){
            if(index == 0){
                head.next = head.next.next;
            }else{
                Node p = head;
                int i = -1;
                while(i < index - 1){
                    p = p.next;
                    i++;
                }
                p.next = p.next.next;
            }
            size--;
        }
    }
}
```
