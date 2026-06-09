/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
typedef struct {
    int rear;
    int front;
    int len;
    int *pqueue;
} QUEUE;

void init_queue(QUEUE *queue, int size) {
     queue->rear = 0;
     queue->front = 0;
     queue->len = size;
     queue->pqueue = (int *)malloc(size * sizeof(int));

     return;
} 

void add_rear_value(QUEUE *queue, int value) {
    queue->pqueue[queue->rear++] = value;
}

int pop_rear_value(QUEUE *queue) {
    return queue->pqueue[--queue->rear];
}

int pop_front_value(QUEUE *queue) {
    return queue->pqueue[queue->front++];
}

bool isempty(QUEUE *queue) {
    return queue->rear == queue->front;
}

int get_rear_value(QUEUE *queue) {
    return queue->pqueue[queue->rear - 1];
}

int get_front_value(QUEUE *queue) {
    return queue->pqueue[queue->front];
}

void printf_queue(QUEUE *queue) {
    for (int i = queue->front; i < queue->rear; i++) {
        printf("%d ", queue->pqueue[i]);
    }
    printf("\n");
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    if ((nums == NULL) || (numsSize == 0)) {
        *returnSize = 0;
        return NULL;
    }
    
    QUEUE queue;
    init_queue(&queue, numsSize);
    *returnSize = 0;
    int *result = (int *)malloc((numsSize - k + 1) * sizeof(int));

    for (int j = 0; j < numsSize; j++) {
        while (!isempty(&queue) && (nums[j] > nums[get_rear_value(&queue)])) {
            pop_rear_value(&queue);  
        }
        
        add_rear_value(&queue, j);

        if (get_front_value(&queue) == j - k) {
            pop_front_value(&queue);
        }
        
        if (j >= k - 1) {
            result[*returnSize] = nums[get_front_value(&queue)];
            *returnSize += 1;
        }
    }

    return result;
}


