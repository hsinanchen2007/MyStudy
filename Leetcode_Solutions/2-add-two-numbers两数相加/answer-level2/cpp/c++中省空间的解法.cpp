执行用时 :24 ms, 在所有 C++ 提交中击败了98.09%的用户
内存消耗 :9.8 MB, 在所有 C++ 提交中击败了98.75%的用户
思路：本题可以不用再创建一个新的链表，可以直接在链表表l1和l2上进行操作。
首先创建一个newList指针指向l1链表，把每一位相加的结果保存在l1的val中。
若11比l2短，接着让l1的尾指针指向l2比l1长的那部分。然后让l2中的每一位分别与flag进位标志相加即可。


注意点：要考虑一种特殊的情况，当l1长度和l2的长度一致且进位标志为1时，说明它们相加的结果要多一位。
(如 555+620=1175)此时要申请一个新的空间，用来保存结果的最高位，其值为1。

```
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
		ListNode *newList = l1, *pre ;  //newList指向返回的链表，pre记录保存链表的当前指针的的前一个位置。
		int flag = 0;  //进位标志
		while (l1||l2)
		{
			int value;  //两个链表的每一位相加的和
			(l1) ? (pre = l1,l1 = l1->next, value = pre->val + flag) : (pre->next=l2, pre = l2, value= flag);
			(l2) ? (value += l2->val, l2 = l2->next) : (pre->next=l1);
			pre->val = value % 10;
			(value > 9) ? (flag = 1) : (flag = 0);
		}
		if (l1 == NULL && l2 == NULL && flag == 1)
			pre->next = new ListNode(1);
		return newList;
        
    }
};
```
