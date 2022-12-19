```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        return new MyLink(head).findAndRemove(val);
        
    }

    class MyLink  implements  Iterator{
        private ListNode link;
        private ListNode current;
        private ListNode prior;
        public MyLink(ListNode head){
              this.link = head;
              this.current = head;
        }
        public boolean hasNext(){
             if(current != null && current.next != null) 
                 return true;
             return false;
        } 

        public ListNode next(){
            if(this.hasNext()){
               this.prior = current;
               this.current = current.next;
            }
            return this.current;
            
        }

        public void remove(){
              if(this.prior != null){
                   this.prior.next = this.current.next;
                   this.current = this.prior;
              }else {
                  link = current.next;
                  current = current.next;
              }
        }

        public void removeHead(){
            this.link = this.current.next;
            this.current = this.link;
            this.prior = null;
        }
        
        public ListNode findAndRemove(int target){
            while(this.link != null && this.link.val == target){
                this.removeHead();
            }
            if(this.link == null) return null;

             while(this.hasNext()){
                  if(this.next().val == target){
                      this.remove();
                  }
             }
             if(!this.hasNext() && this.current != null && this.current.val == target){
                 this.link = null;
             }
             return this.link;
        }
        
    }
}
```
