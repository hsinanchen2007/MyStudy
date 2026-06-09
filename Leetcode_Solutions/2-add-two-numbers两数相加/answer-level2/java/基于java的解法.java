### 解题思路
l1和l2节点顺序累加进位，后续节点为空时,将非空节点拼接到l1尾部，并从该节点继续执行进位操作
执行用时 :
2 ms
, 在所有 Java 提交中击败了
99.96%
的用户
内存消耗 :
39.4 MB
, 在所有 Java 提交中击败了
96.75%
的用户

### 代码

```java
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode start=l1;//记录头部节点
        int mark=0;//记录进位值
        ListNode temp1=null;//缓存回归节点
        while(l1!=null&&l2!=null){//l1和l2均不为空时候累加进位
            l1.val=l1.val+l2.val+mark;
            if(l1.val>9){
                l1.val=l1.val%10;
                mark=1;
            }else{
                mark=0;
            }
            temp1=l1;
            l1=l1.next;
            l2=l2.next;
            
        }
        if(l2!=null){//l2不为空时候将后续节点拼接到l1
            temp1.next=l2;
            l1=l2;
        }
        while(l1!=null){//l1逐个节点进行累加
            l1.val=l1.val+mark;
            if(l1.val>9){
                l1.val=l1.val%10;
                mark=1;
            }else{
                mark=0;//无法进位时候跳出循环
                break;
            }
            temp1=l1;
            l1=l1.next;  
        }
        if(mark==1){
            temp1.next=new ListNode(1);//如果还能进位添加尾节点
        }
        return start;
    }
}
```