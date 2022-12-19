#define TEST 3000

typedef struct _item {
	int val;
	struct _item *next;
} Item;
typedef struct {
	int size;
	Item *header;
	Item *tail;  
} RecentCounter;
int IsEmpty(const RecentCounter *q)
{
	if (q->size == 0) {
		return 1;
	}
	return 0;
}

void EnQueue(RecentCounter *q, int val)
{
	Item *each = (Item *)calloc(1, sizeof(Item));
	if (each == NULL) {
		exit(-1);
	}
	each->val = val;
	if (IsEmpty(q)) {
		q->header = q->tail = each;
		q->size = 1;
		return;
	}
	q->tail->next = each;
	q->tail = each;
	q->size += 1;

}

void DeQueue(RecentCounter *q)
{
	if (IsEmpty(q)) {
		return;
	}
	Item *each = q->header;
	q->header = q->header->next;
	q->size -= 1;
	if (IsEmpty(q)) {
		q->header = q->tail = NULL;
	}
	free(each);
}

int PeekQueue(const RecentCounter *q)
{
	if (IsEmpty(q)) {
		return -1;
	}
	return q->header->val;
}
RecentCounter* recentCounterCreate() {
    RecentCounter *ret = (RecentCounter *)calloc(1, sizeof(RecentCounter));
	if (ret == NULL) {
		exit(-1);
	}
	return ret; 
}

int recentCounterPing(RecentCounter* obj, int t) {
	if (IsEmpty(obj)) {
		EnQueue(obj, t);
		return 1;
	}
	EnQueue(obj, t);
	int ret = -1;
	while ((ret = PeekQueue(obj)) != -1) {
		if (t - ret > TEST) {
			DeQueue(obj);
			continue;
		}
		break;
	}
	return obj->size;
}

void recentCounterFree(RecentCounter* obj) {
	if (IsEmpty(obj)) {
		free(obj);
		return;
	}
	Item *each = NULL;
	while ((each = obj->header) != NULL) {
		obj->header = obj->header->next;
		free(each);
	}
	free(obj); 
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/