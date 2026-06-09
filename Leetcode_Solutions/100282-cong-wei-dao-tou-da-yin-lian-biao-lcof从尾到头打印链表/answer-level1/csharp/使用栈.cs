### 解题思路
利用栈后入先出的特性
先写入栈中
再从栈中弹出

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
    public int[] ReversePrint(ListNode head) {
        Stack<ListNode> st = new Stack<ListNode>();           
        while(head!=null){
            st.Push(head);
            head = head.next;
        }
        var num = st.Count;
        int [] arr = new int[num];
        for(int i=0;i<num;i++){
            arr[i]=st.Pop().val;
        }
        return arr;
    }
}
```