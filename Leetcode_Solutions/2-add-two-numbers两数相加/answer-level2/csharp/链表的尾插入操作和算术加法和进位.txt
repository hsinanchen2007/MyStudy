### 解题思路
这个题主要考察链表的基本操作。单纯链表的知识点并不难，基本上就是尾插入操作。需要注意的是怎么处理进位的问题。在链表结点数目不相同的情况下，也得考虑进位的情况。

### 代码

```csharp
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        ListNode currentNode1 = l1, currentNode2=l2, resultHeadNode=null, resultCurrentNode=null;
        bool carry=false;
        int sum=0;

        while(currentNode1!=null&&currentNode2!=null){
            sum = currentNode1.val+currentNode2.val;
            
            if(carry==true){
                sum+=1;
                carry = false;
            }

            if(sum>=10)
            {
                sum-=10;
                carry=true;
            }

            if(resultHeadNode==null){
                resultHeadNode = new ListNode(sum);
                resultCurrentNode= resultHeadNode;
            }
            else{
                var resultNode = new ListNode(sum);
                resultCurrentNode.next=resultNode;
                resultCurrentNode=resultNode;
            }
            
            currentNode1=currentNode1.next;
            currentNode2=currentNode2.next;
        }

        while(currentNode1!=null){
            sum = currentNode1.val;
            if(carry==true){
                sum+=1;
                carry = false;
            }

            if(sum>=10)
            {
                sum-=10;
                carry=true;
            }

            var resultNode = new ListNode(sum);
            resultCurrentNode.next=resultNode;
            resultCurrentNode=resultNode;

            currentNode1=currentNode1.next;
        }

        while(currentNode2!=null){
            sum = currentNode2.val;
            if(carry==true){
                sum+=1;
                carry = false;
            }

            if(sum>=10)
            {
                sum-=10;
                carry=true;
            }

            var resultNode = new ListNode(sum);
            resultCurrentNode.next=resultNode;
            resultCurrentNode=resultNode;

            currentNode2=currentNode2.next;
        }

        if(carry==true)
        {
            var resultNode = new ListNode(1);
            resultCurrentNode.next=resultNode;
            resultCurrentNode=resultNode;
        }

        return resultHeadNode;
    }
}
```