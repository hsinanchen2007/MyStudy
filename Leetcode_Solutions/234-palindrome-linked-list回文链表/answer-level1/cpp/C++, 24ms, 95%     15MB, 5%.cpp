```C++ []
/*
1. dfs的思想：利用一个指针一直往下搜索，直到找到最后一个节点，然后再返回与head进行比较，
2. 每次比较之后 都要令head = head->next，并且head要用指针的引用，否则递归返回上一层时
3. head并没有被改变，因为如果不用引用， 我们只是改变了形参head并没有改变实参。
*/
bool flag = true;
void helper(ListNode*& head, ListNode* p)
{
	if (p->next)
		helper(head, p->next);
	if (flag && head->val != p->val)
		flag = false;
	head = head->next;
}

bool isPalindrome(ListNode* head)
{
	if (head)
		helper(head, head);
	return flag;
}
```
```python []
print('Hello world!')
```
```ruby []
puts 'Hello world!'
```

