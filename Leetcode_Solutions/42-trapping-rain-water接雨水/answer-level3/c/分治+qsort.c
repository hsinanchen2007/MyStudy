### 解题思路
找出最高的两个点，分成三份即左中右，本函数算中间区域的水量。然后分治其他两个区域。

### 代码

```c
typedef struct {
	int val;
	int pos;
}hNode;
int cmpTrap(const void *a, const void *b){
	hNode *ap, *bp;
	ap = (hNode *)a;
	bp = (hNode *)b;
	if (ap->val == bp->val) {
		return ap->pos - bp->pos;
	}
	return bp->val - ap->val;
}
int trapFZ(int* height, int start, int end){
	hNode *range;
	int i, j, ret, len;
	int HFirst, HSecond, level, tmp;
	
	len = end - start + 1;
	if (len <= 2) {
		return 0;
	}
	
    range = (hNode *)calloc(len, sizeof(hNode));

	
	for (j = 0, i = start; i <= end; i++, j++) {
		range[j].val = height[i];
		range[j].pos = i;
	}
	qsort(range, len, sizeof(hNode), cmpTrap);
	HFirst = range[0].pos;
	HSecond = range[1].pos;
	level = range[1].val;
	if (HFirst > HSecond) {
		tmp = HFirst;
		HFirst = HSecond;
		HSecond = tmp;
	}

	for (i = HFirst, ret = 0; i < HSecond; i++) {
        tmp = level - height[i];
        if (tmp > 0) {
            ret += tmp;
        }
	}
	ret+= trapFZ(height, start, HFirst);
	ret+= trapFZ(height, HSecond, end);

	return ret;
}

int trap(int* height, int heightSize){
    return trapFZ(height, 0, heightSize - 1);
}
```