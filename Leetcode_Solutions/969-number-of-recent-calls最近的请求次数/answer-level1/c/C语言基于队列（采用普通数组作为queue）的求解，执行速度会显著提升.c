#define TEST 3000
#define MAX 10000
typedef struct {
	int arr[MAX];
	int header;
	int tail;
	int size; 
} RecentCounter;

inline void EnQueue(RecentCounter *q, int val)
{
	q->arr[q->tail] = val;
	q->tail += 1;
	q->size += 1;
}

inline void DeQueue(RecentCounter *q)
{
	q->header += 1;
	q->size -= 1;
}

inline int PeekQueue(RecentCounter *q)
{
	return q->arr[q->header];
}

RecentCounter* recentCounterCreate() {
	RecentCounter *ret = (RecentCounter *)calloc(1, sizeof(RecentCounter));
	if (ret == NULL) {
		exit(-1);
	}
	return ret; 
}

int recentCounterPing(RecentCounter* obj, int t) {
	EnQueue(obj, t);
	while (t - PeekQueue(obj) > TEST) {
		DeQueue(obj);
	}
	return obj->size; 
}

void recentCounterFree(RecentCounter* obj) {
	if (obj != NULL) {
		free(obj);
	}  
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/