### 解题思路
单调栈，注意题意是连续的天数

### 代码

```c
#include <stdio.h>
typedef struct {
    int n;    
} StockSpanner;

#define MAX_N 10050
static int g_nums[MAX_N];
static int g_numsIndex;
static int g_stack[MAX_N];
static int g_top;
StockSpanner* stockSpannerCreate() {
    memset(g_stack, 0, sizeof(g_stack));
    memset(g_nums, 0, sizeof(g_nums));
    g_top = 0;
    g_numsIndex = 0;
    return (StockSpanner *)calloc(1, sizeof(StockSpanner));
}

int stockSpannerNext(StockSpanner* obj, int price) {
    int topIndex, ans;

    while (g_top != 0) {
        topIndex = g_stack[g_top - 1];
        if (price < g_nums[topIndex]) {
            break;
        }
        g_top--;
    }

	if (g_top == 0) {
		topIndex = -1;
	} else {
		topIndex = g_stack[g_top - 1];
	}
	ans = g_numsIndex - topIndex;
    g_stack[g_top++] = g_numsIndex;
	g_nums[g_numsIndex++] = price;
    return ans;
}

void stockSpannerFree(StockSpanner* obj) {
    if (obj != NULL) {
        free(obj);
    }
}
```