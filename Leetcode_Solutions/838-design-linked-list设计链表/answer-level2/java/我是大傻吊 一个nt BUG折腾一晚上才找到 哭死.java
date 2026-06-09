### 解题思路
双链表实现，这个题我真的是把每一个点都折腾了一个多小时，折腾了一晚上，超级容易不注意就写错，也许是我太笨了，写代码的时候第一遍一定要注意，不然事后麻烦死了。 

### 代码
找bug的时候顺便把show方法写了下

```java
public class ListNode{
    int val;
    ListNode next;
    ListNode prev;
    public ListNode(int x){
        val=x;
    }
}
class MyLinkedList {
    int size;
    /** Initialize your data structure here. */
    //构造方法，初始化头结点
    ListNode head,tail;
    public MyLinkedList() {
        size=0;
        //头尾不计入size
        head = new ListNode(0);
        tail = new ListNode(0);
        head.next = tail;
        tail.prev = head;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    public int get(int index) {
        //索引小于0或者超出链表范围
        if(index<0 || index>=size){
            return -1;
        }
        ListNode p = head;
        for(int i = 0;i <=index;i++){//这里一直漏个等号 找死我了 
            p=p.next;
        }
        return p.val;

    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    public void addAtHead(int val) {
        //创建新的节点
        ListNode newListNode = new ListNode(val);
        //双链表添加节点
        //防止断链 
        ListNode p = head.next;
        //添加
        head.next = newListNode;
        newListNode.prev = head;
        newListNode.next = p;
        p.prev = newListNode;
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    public void addAtTail(int val) {
        ListNode newListNode = new ListNode(val);
        ListNode p = tail.prev;
        p.next = newListNode;
        newListNode.prev = p;
        tail.prev = newListNode;
        newListNode.next = tail;
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    public void addAtIndex(int index, int val) {
        ListNode newListNode = new ListNode(val);
        //特殊情况插入
        if(index==size){
            addAtTail(val);//这里调用方法size会加一 我一直没发现 找了一晚上 哭死
        }
        else if(index>size){
            return;
        }else if(index<0){
            addAtHead(val);
        }else { //一般情况插入
            //设置辅助指针，找到插入位置
            ListNode p = head;
            for(int i = 0;i<index;i++){
                p=p.next;
            }
            //防止断链
            ListNode q = p.next;
            p.next = newListNode;
            newListNode.prev = p;
            newListNode.next = q;
            q.prev = newListNode;
            size++;
            }
        
       
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    public void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        if(index>=0 && index<size){
        //设置辅助指针，找到删除位置
        ListNode p = head;
        for(int i = 0;i<=index;i++){
            p=p.next;
        } 
        ListNode q = p.next;
        p.prev.next = p.next;
        p.next.prev = p.prev;
        size--;
        }
    }
    public void show() {
    	ListNode p = head;
    	while(p.next!=tail) {
    		p = p.next;
    		System.out.println(p);
    	}
    }

	@Override
	public String toString() {
		return "MyLinkedList [size=" + size + ", head=" + head + ", tail=" + tail + "]";
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