### 解题思路
穷举，中间使用了curSum进行快速排出不可能解
![image.png](https://pic.leetcode-cn.com/ef1dd1ebe521cc7e59b15eadba97a6822335c31e66320bca788ffa1ceeb0ca5d-image.png)

### 代码

```c

#define MY_OK 0
#define MY_FAIL (-1)

struct MyRlt {
	char **rlt;
	int rltCnt;
	int rltSize;
	int rltLen;
};

struct MyStatus {
	int *cur;
	int curCnt;
	int curSum;
	int size;
};
void rltFree(struct MyRlt *r)
{
	int i;
	if (r == NULL) {
		return;
	}
	if (r->rlt != NULL) {
		for (i = 0; i < r->rltCnt; i++) {
			if (r->rlt[i] != NULL) {
				free(r->rlt[i]);
				r->rlt[i] = NULL;
			}
		}
		free(r->rlt);
		r->rlt = NULL;
	}
	return;
}
int rltInit(struct MyRlt *r, int n)
{
	r->rltSize = pow(2, 2 * n);
	r->rltLen = (2 * n) + 1;
	r->rltCnt = 0;
	
	r->rlt = (char**)calloc(r->rltSize, sizeof(char*));
	if (r->rlt == NULL) {
		return MY_FAIL;
	}
	return MY_OK;
}
void statusTrace(struct MyStatus *s)
{
	int i;
	for (i = 0; i < s->curCnt; i++) {
		printf("%d", s->cur[i]);
	}
	printf("\n");
}
int rltAdd(struct MyRlt *r, struct MyStatus *s)
{
	int i;
	char *buf = NULL;
	//statusTrace(s);
	buf = (char*)calloc(r->rltLen, sizeof(char));
	if (buf == NULL) {
		return MY_FAIL;
	}
	for (i = 0; i < s->curCnt; i++) {
		buf[i] = (s->cur[i] == 1) ? '(' : ')';
	}
	r->rlt[r->rltCnt++] = buf;
	return MY_OK;
}

void statusFree(struct MyStatus *s)
{
	if (s->cur != NULL) {
		free(s->cur);
		s->cur = NULL;
	}
	return;
}
int statusInit(struct MyStatus *s, int n)
{
	s->curSum = 0;
	s->size = 2 * n;
	s->curCnt = 0;
	s->cur = (int*)calloc(s->size, sizeof(int));
	if (s->cur == NULL) {
		return MY_FAIL;
	}
	return MY_OK;
}
int generateRlt(struct MyRlt *r, struct MyStatus *s, int leftPosCnt)
{
	int ret;
	if (s->curSum < 0 || s->curSum > (r->rltLen / 2)) {
		return MY_OK;
	}
	if (leftPosCnt == 0) {
		if (s->curSum != 0) {
			return MY_OK;
		}
		return rltAdd(r, s);
	}
	s->cur[s->curCnt++] = 1;
	s->curSum += 1;
	ret = generateRlt(r, s, leftPosCnt - 1);
	s->curSum -= 1;
	s->curCnt--;
	
	s->cur[s->curCnt++] = -1;
	s->curSum -= 1;
	ret |= generateRlt(r, s, leftPosCnt - 1);
	s->curSum += 1;
	s->curCnt--;

	if (ret != MY_OK) {
		return ret;
	}
	return MY_OK;
}
char ** generateParenthesis(int n, int* returnSize){
	int ret;
	struct MyStatus s;
	struct MyRlt r;
	ret = rltInit(&r, n);
	ret |= statusInit(&s, n);
	if (ret != MY_OK) {
		*returnSize = 0;
		return NULL;
	}
	
	ret = generateRlt(&r, &s, 2 * n);
	if (ret != MY_OK) {
		rltFree(&r);
		statusFree(&s);
		return NULL;
	}
	statusFree(&s);
	*returnSize = r.rltCnt;
	return r.rlt;
}
```