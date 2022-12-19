### 解题思路
1. 首先创建一个大小为`n-m+1`的`ListNode`数组;
2. 遍历`head`，每当当前位置大于`m`，记录进数组中;
3. 位置到达`n`时，利用存储的数组，修改原链表中的`val`值就可以了。
### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    private void swap(ListNode left,ListNode right)
    {
        int temp=left.val;
        left.val=right.val;
        right.val=temp;
    }
    private void reserver(ListNode[] lists)
    {
        int left=0,right=lists.length-1;
        while(left<right)
        {
            swap(lists[left],lists[right]);
            left++;right--;
        }
    }
    public ListNode reverseBetween(ListNode head, int m, int n)         {
        int count=1;
        ListNode iter=head;
        ListNode[] lists=new ListNode[n-m+1];
        while(iter!=null)
        {
            if(count>=m)lists[count-m]=iter;
            if(count==n){
                reserver(lists);
                break;
            }
            iter=iter.next;
            count++;    
        }
        return head;
    }
}
```
### 复杂度
时间复杂度o(n),最坏为o(k),k为链表长度;
空间复杂度o(m-n+1)
