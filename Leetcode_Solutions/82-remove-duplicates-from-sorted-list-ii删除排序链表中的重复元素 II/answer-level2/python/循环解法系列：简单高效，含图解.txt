**效果：**
执行用时 :52 ms, 在所有 Python3 提交中击败了92.57%的用户
内存消耗 :13.9 MB, 在所有 Python3 提交中击败了5.26%的用户

直接按照规律循环解题。
但避免开头就出现重复数字，因此还是先加空头
图解：
![IMG_20191006_222542.jpg](https://pic.leetcode-cn.com/c10b4b3a0333de9d112bdfc042083f6d748b1d6133e934b17dd1996a6cda4884-IMG_20191006_222542.jpg)
实现代码：
```C++ []
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
		ListNode thead=ListNode(-1);
		thead.next=head;
		ListNode *pre,*cur;
		int t;
		cur=&thead;
		while (cur){
			pre = cur;
			cur = cur->next;
			while (cur && cur->next && 
					cur->next->val==cur->val){
				t=cur->val;
				while (cur && cur->val==t)
					cur=cur->next;		
			}
			pre->next=cur;
		}
		return thead.next;
    }
};
```
```python []
class Solution:#感谢各位的更好思路或改进办法
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        thead = ListNode('a')
        thead.next = head
        pre,cur = None,thead
        while cur:
            pre=cur
            cur=cur.next
            while cur and cur.next and cur.next.val == cur.val:
                t=cur.val
                while cur and cur.val==t:
                    cur=cur.next
            pre.next=cur
        return thead.next
```




