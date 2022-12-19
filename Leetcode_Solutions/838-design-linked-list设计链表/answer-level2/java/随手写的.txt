### 解题思路
直接在MyLinkedList里面定义了val，next。还有一个size，还设定了一个头。
设定了一个无参构造，一个int参数构造，
调用无参会自动调用int构造，传入0，并且初始化size为0，直接调用有参构造则只会直接给val赋值。
调用无参构造会自动调用
最后还写了一个show方法，来显示链表的数据。

### 代码

```java
class MyLinkedList {
int val;
    MyLinkedList next;
    private int size;
    private MyLinkedList head;

    
    /** Initialize your data structure here. */
    public MyLinkedList() {
        head=new MyLinkedList(0);
        size=0;
    }
    public MyLinkedList(int i) {
        this.val=i;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    public int get(int index) {
        if (index<0||index>=size){
            return -1;
        }
        MyLinkedList temp= head.next;
        int n=0;
        while (true){
            if (n==index){
                return temp.val;
            }
            n++;
            temp=temp.next;
        }
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    public void addAtHead(int val) {
        MyLinkedList temp=head.next;
        MyLinkedList v = new MyLinkedList(val);
        v.next=temp;
        head.next=v;
        size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    public void addAtTail(int val) {
        MyLinkedList temp =head;
        while (true){
            if (temp.next==null){
                temp.next=new MyLinkedList(val);
                size++;
                return;
            }
            temp=temp.next;
        }
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    public void addAtIndex(int index, int val) {
        if (index<0){
            addAtHead(val);
            return;
        }
        int n =-1;
        MyLinkedList temp = head;
        while (true){
            if (index==(n+1)||temp.next==null){
                MyLinkedList myLinkedList = new MyLinkedList(val);
                myLinkedList.next=temp.next;
                temp.next=myLinkedList;
                size++;
                return;
            }
            n++;
            temp=temp.next;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    public void deleteAtIndex(int index) {
        if (index<0||index>=size){
            return ;
        }
        int n =-1;
        MyLinkedList temp = head;
        while (true){
            if (temp.next==null){
                temp=null;
                size--;
                return;
            }
            if (index==(n+1)){
                temp.next=temp.next.next;
                size--;
                return;
            }
            n++;
            temp=temp.next;
        }
    }

    public void show(){
        MyLinkedList t = head.next;
        while (t!=null){
            System.out.print(t.val);
            if (t.next!=null){
                System.out.print("->");
            }
            t=t.next;
        }
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
```