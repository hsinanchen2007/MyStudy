### 解题思路
此题可以取出值，然后进行判断，当然一个比较好的例子就是，官方题解走一半，然后利用回文性质，把链表后半给反转对比，反转链表就是206题。

最初想的是，取出来，当回文整数对待，这个还行，但是到21/26出现[-126,-126]???直接挂掉。
```python []
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        LinkSum = 0  # 存每个结点值转为回文数字判断
        while head:
            LinkSum = LinkSum * 10 + head.val
            head = head.next
        half = 0
        while half < LinkSum:  # 缩小至half<=LinkSum
            half = half * 10 + LinkSum % 10  # 取linksum余数
            LinkSum //= 10  # 不断缩小
        return LinkSum == half or half // 10 == LinkSum
```

### 1.链表取出值
还是不太行，时间即使O(n)，但是不行，被90%打败。
```c []
typedef struct StackNode{
	int data;
	struct StackNode *next;
} LinkStack, *stack_ptr;

void push(stack_ptr *stack, int value) {
	stack_ptr node = (stack_ptr)malloc(sizeof(LinkStack));
	node->data = value;
	node->next = *stack;  // 交换头结点
	*stack = node;  // 改变头结点
}

void pop(stack_ptr *stack, int *value) {
	stack_ptr q = *stack;  // q暂存删除结点
	*value = q->data;  // 赋值返回
	*stack = (*stack)->next;
	free(q);  // 删除结点
}

bool isPalindrome(struct ListNode* head){
	stack_ptr stack = NULL;
	struct ListNode *p = head;
	/* 1.遍历链表，整个入栈 */
	while (p) {
		push(&stack, p->val);
		p = p->next;
	}
	/* 2.逐个对比 */
	int value = 0;
	while (stack) {
		pop(&stack, &value);  // 保证非空pop元素
		if (value != head->val) return false;
		head = head->next;
	}
	return true;
}
```
```python []
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        data = []
        while head:
            data.append(head.val)
            head = head.next
        return data == data[::-1]
```

### 2.反转后半部分
1. 得到全长
2. 得到len/2指针(这里涉及到后面奇偶)
3. 反转后半部分链表
4. 对比两半链表(不需要考虑奇偶！)
```c []
bool isPalindrome(struct ListNode* head){
    struct ListNode *curr = head, *p = NULL, *q = NULL;
    int len = 0;
    while (curr) {
        len++;
        curr = curr->next;
    }
    int half_len = len >> 1;  // 实际多1，索引因head刚好
    curr = head;  // 重新置head
    while (half_len) {
        curr = curr->next;  // 向后到half_len
        half_len--;
    }  // curr指向一半结点

    /* 2.反转后半部分链表 */
    while (curr) {
        q = curr->next;  // q暂存curr->next
        curr->next = p;  // 首节点NULL,其余指向前结点
        p = curr;  // p就是上个结点信息
        curr = q;  // curr继续遍历
    }  // p就是后半反转的链表(可能多一个)

    /* 3.遍历查值half_len遍即可，多一个无所谓 */
    for (half_len = len >> 1;
        half_len && head->val == p->val;
        half_len--,head = head->next,p = p->next) {}
    return !half_len;  // 0:回文，1不是回文
}
```

