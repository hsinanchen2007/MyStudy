```
class Solution {
    //保存链表头
    ListNode head;
    Random rdm;
    //链表长度
    int size;

    public Solution(ListNode head) {
        this.head = head;
        this.rdm = new Random();
        ListNode cur = head;
        while(cur != null){
            size++;
            cur = cur.next;
        }
    }
    
    /** Returns a random node's value. */
    public int getRandom() {
        ListNode cur = this.head;
        int index = rdm.nextInt(this.size);
        while(index-->0){
            cur = cur.next;
        }
        return cur.val;
    }
}
```
Random类的nextInt方法可以传入一个bound参数，返回[0, bound-1]中的任意整数