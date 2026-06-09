### 解题思路
1. 找到第一个柱子、最高的柱子、最后一个柱子。
2. 第一个柱子作为当前起始柱子，遍历到最高的柱子。
- 如果遇到了比当前起始柱子矮，则入栈；
- 否则说明能接水，计算当前起始柱子到当前索引的面积，并把栈出空，减去障碍面积
- 更新当前索引为当前起始柱子
3. 返回来遍历最后一个柱子到max，同2
4. 有一些特殊情况，没有柱子、只有一个柱子....
### 代码

```c
typedef struct {
    int *stk;
    int stkSize;
    int curSize;
} STK;

int popStk(STK *s) {
    if (s->curSize == 0) return -1;
    int val = s->stk[s->curSize - 1];
    s->curSize--;
    return val;
}

int pushStk(STK* s, int val) {
    if (s->curSize >= s->stkSize) return -1;
    s->stk[s->curSize] = val;
    s->curSize++;
    return 0;
}

int calcTrap(STK* s, int* height, int size, int begin, int end) {
    int area = fmin(height[begin], height[end]) * (end - begin - 1);
    int h = popStk(s);
    while (h != -1) {
        area -= h;
        h = popStk(s);
    }
    return area;
}

int trap(int* height, int heightSize){
    if (!height || heightSize <= 1) return 0;

    int first = -1;
    int end = -1;
    int max = 0;
    for (int i = 0; i < heightSize; i++) {
        if (height[i] && first == -1) first = i;
        if (height[i] && height[i] > height[max]) max = i;
        if (height[i]) end = i;
    }

    if (first == end) return 0;

    STK s = {0};
    s.stk = (int*)malloc(sizeof(int) * heightSize);
    s.stkSize = heightSize;
    (void)memset(s.stk, 0, sizeof(int) * heightSize);

    int ans = 0;
    int last = first;
    for (int i = last+1; i <= max; i++) {
        if (height[i] >= height[last]) {
            ans += calcTrap(&s, height, heightSize, last, i);
            last = i;
        } else if (height[i] != 0) {
            pushStk(&s, height[i]);
        }
    }

    last = end;
    for (int i = last - 1; i >= max; i--) {
        if (height[i] >= height[last]) {
            ans += calcTrap(&s, height, heightSize, i, last);
            last = i;
        } else if (height[i] != 0) {
            pushStk(&s, height[i]);
        }
    }

    free(s.stk);
    return ans;
}
```