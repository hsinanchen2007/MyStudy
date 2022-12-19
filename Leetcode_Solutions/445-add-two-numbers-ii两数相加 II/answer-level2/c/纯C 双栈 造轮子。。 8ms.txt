```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


#define STACK_INIT_SIZE 1000
#define STACK_INCREASE 1000

struct Stack {
	int * base;
	int * top;
	int stacksize;
};

struct Stack * InitStack() {
	struct Stack * s = (struct Stack *)malloc(sizeof(struct Stack));
	s->base = (int *)malloc(sizeof(int) * STACK_INIT_SIZE);
	if (!s->base) {
		return NULL;
	}
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	return s;
}

int PopStack(struct Stack * s, int * e) {
	if (s->top == s->base) {
		return 0;
	}
	--(s->top);
	*e = *(s->top);
	return 1;
}

int PushStack(struct Stack * s, int e) {
	if (s->top - s->base == s->stacksize) {
		s->base == (int *)realloc(s->base, (s->stacksize + STACK_INCREASE) * sizeof(int));
		if (!s->base) {
			return 0;
		}
		s->top = s->base + s->stacksize;
		s->stacksize += STACK_INCREASE;
	}
	*(s->top) = e;
	++(s->top);
	return 1;
}

int isEmptyStack(struct Stack * s) {
	return (s->top == s->base) ? 0 : 1;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	//双栈
	struct Stack * s1 = InitStack();
	struct Stack * s2 = InitStack();

	struct ListNode * p1 = l1;
	struct ListNode * p2 = l2;

	struct ListNode * r = NULL;

	int error_flag = 1;

	while (p1) {
		error_flag = PushStack(s1, p1->val);
		p1 = p1->next;
	}

	while (p2) {
		error_flag = PushStack(s2, p2->val);
		p2 = p2->next;
	}

	int flag = 0;

	while (isEmptyStack(s1) && isEmptyStack(s2)) {
		struct ListNode * tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
		tmp->next = r;
		r = tmp;

		int tmp1 = 0;
		int tmp2 = 0;

		error_flag = PopStack(s1, &tmp1);
		error_flag = PopStack(s2, &tmp2);

		int val = tmp1 + tmp2 + flag;

		if (val > 9) {
			flag = 1;
			tmp->val = val - 10;
		}
		else {
			flag = 0;
			tmp->val = val;
		}
	}
	if (isEmptyStack(s1) == 0 && isEmptyStack(s2) == 0 && flag == 1) {
		struct ListNode * tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
		tmp->val = 1;
		tmp->next = r;
		r = tmp;
	}

	if (isEmptyStack(s1) == 0 && isEmptyStack(s2) != 0) {
		while (isEmptyStack(s2)) {
			int tmp2 = 0;
			error_flag = PopStack(s2, &tmp2);

			int val = tmp2 + flag;

			struct ListNode * tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
			tmp->next = r;
			r = tmp;

			if (val > 9) {
				flag = 1;
				tmp->val = val - 10;
			}
			else {
				flag = 0;
				tmp->val = val;
			}
		}
		if (flag == 1) {
			struct ListNode * tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
			tmp->next = r;
			tmp->val = 1;

			r = tmp;
		}
	}

	if (isEmptyStack(s1) != 0 && isEmptyStack(s2) == 0) {
		while (isEmptyStack(s1)) {
			int tmp1 = 0;
			error_flag = PopStack(s1, &tmp1);

			int val = tmp1 + flag;

			struct ListNode * tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
			tmp->next = r;
			r = tmp;

			if (val > 9) {
				flag = 1;
				tmp->val = val - 10;
			}
			else {
				flag = 0;
				tmp->val = val;
			}
		}
		if (flag == 1) {
			struct ListNode * tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
			tmp->next = r;
			tmp->val = 1;

			r = tmp;
		}
	}

	return r;
}
```
