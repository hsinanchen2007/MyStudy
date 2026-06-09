```
class Palindrome{
    public  boolean isPalindrome(ListNode head){
        int length = 0;
        ListNode p = head;
        while (p!=null){
            length++;
            p = p.next;
        }
        //建立一个数组保存链表值进行比较
        int [] c = new int[length];
        for (int i=0;i<c.length;i++){
            if (head!=null)
            {
                c[i] = head.val;
                head = head.next;
            }

        }
        for (int j=0,k=c.length-1;j<k;j++,k--){
            if (c[j] != c[k])
                return false;
        }
        return  true;
    }
}
```
