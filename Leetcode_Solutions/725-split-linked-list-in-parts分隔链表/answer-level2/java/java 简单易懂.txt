### 解题思路
1.计算链表总长度
2.通过链表长度sum和拆分个数k，计算出拆分后链表的长度num
3.对分链表进行赋值，分链表走过num后添加null进行截断
4.返回链表数组

### 代码

```java
class Solution {
    public ListNode[] splitListToParts(ListNode root, int k) {
        ListNode[] l1 = new ListNode[k];
        int sum = 0;
        ListNode head = root;
        while (head != null){
            sum++;
            head = head.next;
        }

        head = root;//用head拆分链表
        int num=0;  //用num来计量每个长度的数字

        for(int i=0;i<k;i++){
            if(sum/k!=0 && (i>sum%k-1))
                num = sum/k;
            else 
                num = sum/k+1;
            l1[i]=head;

            if(head!=null){
                while(num>1){
                    head = head.next;
                    num--;
                }
                ListNode temp = head.next;
                head.next = null;
                head = temp;
            }
        }
        return l1;
    }
}
```