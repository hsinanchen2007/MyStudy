一看这个题目，就是个单纯的队列，没有什么特别的，下面是代码
```
#define RET_OK	0
#define RET_ERR	1
#define QUEUE_MAX	3001
typedef struct {
	int buf[QUEUE_MAX];
	int size;
	int cnt;
	int head;
	int tail;
} RecentCounter;

int rcIsEmpty(RecentCounter *rc)
{
	if (rc->cnt == 0) {
		return RET_OK;
	} else {
		return RET_ERR;
	}
}
int rcPeekHead(RecentCounter *rc, int *item)
{
	if (rc->cnt == 0) {
		return RET_ERR;
	}
	*item = rc->buf[rc->head];
	return RET_OK;
}
int rcPollHead(RecentCounter *rc, int *item)
{
	if (rc->cnt == 0) {
		return RET_ERR;
	}
	*item = rc->buf[rc->head];
	rc->head = (rc->head + 1) % rc->size;
	rc->cnt--;
	return RET_OK;
}
int rcInTail(RecentCounter *rc, int item)
{
	if (rc->cnt == QUEUE_MAX) {
		return RET_ERR;
	}
	rc->buf[rc->tail] = item;
	rc->tail = (rc->tail + 1) % rc->size;
	rc->cnt++;
	return RET_OK;
}
RecentCounter* recentCounterCreate() {
    RecentCounter* rc = (RecentCounter*) calloc (1, sizeof(RecentCounter));
	if (rc == NULL) {
		return NULL;
	}
	rc->size = QUEUE_MAX;
	rc->cnt = 0;
	rc->head = 0;
	rc->tail = 0;
	return rc;
}
int recentCounterPing(RecentCounter* obj, int t) {
	int ret;
	int item = INT_MIN;
	int cnt = 0;
	
	while(rcIsEmpty(obj) != RET_OK) {
		if (rcPeekHead(obj, &item) != RET_OK) {
			break;
		}
		if ((item + 3000 )< t) {
			rcPollHead(obj, &item);
		} else {
			break;
		}
	} 
	rcInTail(obj, t);
	cnt = obj->cnt;
	return cnt;	
}

void recentCounterFree(RecentCounter* obj) {
    if (obj != NULL) {
		free(obj);
	}
}
```
