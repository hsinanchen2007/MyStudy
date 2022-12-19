```
typedef struct
{
	int Capacity;
	int Size;
	int* table;
}PriorityQueue;

void swapElement(int*table, int i, int j);
PriorityQueue* priority_queue_initialize(int capacity);
void queue_free(PriorityQueue* q);
int priority_queue_top(PriorityQueue* q);
int priority_queue_dequeue(PriorityQueue* q);
void priority_queue_enqueue(PriorityQueue* q, int key);
void priority_queue_adjust(PriorityQueue* q);
int cmp(const void* a, const void* b)
{
    int* ptrA = *(int** )a;
    int* ptrB = *(int** )b;

    if (ptrA[1] == ptrB[1]) {
        return (ptrA[0] - ptrB[0]);
    }
    return (ptrA[1] - ptrB[1]);
}

static void priority_queue_realloc(PriorityQueue* q);
void swapElement(int* table, int i, int j) {
	int temp = table[i];
	table[i] = table[j];
	table[j] = temp;
}
PriorityQueue* priority_queue_initialize(int capacity) {
	PriorityQueue* q = malloc(sizeof(*q));
	if (q != NULL) {
		q->Capacity = capacity;
		q->Size = 0;
		q->table =malloc(sizeof(int) * q->Capacity);
	}
	return q;
}
void queue_free(PriorityQueue* q) {
	free(q->table);
	free(q);
}
int priority_queue_top(PriorityQueue* q) {
	if (q->Size > 0)return q->table[0];
	return 0;
}
int priority_queue_dequeue(PriorityQueue* q) {
    int en=0;
	if (q->Size > 0) {
		en = q->table[0];
		q->table[0] = q->table[q->Size - 1];
		q->Size--;
		//priority_queue_adjust(q);
	}
	return en;
}
void priority_queue_enqueue(PriorityQueue* q,int key) {
		q->table[q->Size] = key;
		q->Size++;
		//priority_queue_adjust(q);     //入队出队各做一次调整会超时
	
}
void priority_queue_adjust(PriorityQueue* q) {
	for (int i = q->Size - 1; i > 0; i--) {
		if (q->table[i] > q->table[i / 2])
			swapElement(q->table, i, i/2);
	}
}

int scheduleCourse(int** courses, int coursesSize, int* coursesColSize){
    qsort(courses, coursesSize, sizeof(courses[0]), cmp);
    PriorityQueue*q= priority_queue_initialize(10000);
    int time=0;
    for(int i=0;i<coursesSize;i++){
        if(time+courses[i][0]<=courses[i][1]){
            priority_queue_enqueue(q,courses[i][0]);
            time+=courses[i][0];
        }else{ 
            priority_queue_enqueue(q,courses[i][0]);
            priority_queue_adjust(q);
            int duration=priority_queue_top(q);
            priority_queue_dequeue(q);
            time+=courses[i][0]-duration;
        }
    }
    return q->Size;
}
```
