### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
        var l3=new ListNode(null);
       
             var current=l3;
             var rest=0;
             while(l1!=null||l2!=null||rest){
                let x= l1 ? l1.val : 0; 
                let y=l2 ? l2.val :0;
                if((x+y+rest)>=10){//如果溢出
                    current.val=x+y+rest-10;
                      rest=1;
                }else{//没有溢出
                    current.val=x+y+rest;
                    rest=0;
                }  
                 if(l1 != null) l1 = l1.next
                if(l2 != null) l2 = l2.next
                
                if(l1!=null || l2!=null||rest){
                    current.next=new ListNode(null);
                    current=current.next;
                }        
            }
            return l3;
        
      

};
```