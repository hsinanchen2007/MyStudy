### 解题思路
双指针，left <= right

### 代码

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	int data;
	int index;
};

#define ARRAY_SIZE(x)     ((sizeof(x) / sizeof((x)[0])))

static int *ans;
static struct node *first;
static struct node *second;

static int compare(const void *p1, const void *p2)
{
	struct node *node1 = (struct node *)p1;
	struct node *node2 = (struct node *)p2;
	return node1->data - node2->data;
}

int *advantageCount(int *A, int ASize, int *B, int BSize, int *returnSize)
{
	int i;
	int l;
	int r;
	int loop = 0;

	if (!A || !B || ASize == 0 || BSize == 0 || ASize != BSize) {
		return NULL;
	}

	ans = malloc(ASize * 2 * sizeof(int));
	first = malloc(ASize * sizeof(struct node));
	second = malloc(ASize * sizeof(struct node));
	for (loop = 0; loop < ASize; loop++) {
		first[loop].data = A[loop];
		second[loop].data = B[loop];
		first[loop].index = loop;
		second[loop].index = loop;
	}
	qsort(first, ASize, sizeof(struct node), compare);
	qsort(second, ASize, sizeof(struct node), compare);
	l = 0;
	i = 0;
	r = BSize - 1;
	while(l <= r) {
		if (first[i].data > second[l].data) {
			ans[second[l].index] = first[i].data;
			//printf("%d -> %d\n", second[l].index, first[i].data);
			l++;
		} else {
			ans[second[r].index] = first[i].data;
			//printf("%d -> %d\n", second[r].index, first[i].data);
			r--;
		}
		i++;
	}
	*returnSize = ASize;
	return ans;
}
```