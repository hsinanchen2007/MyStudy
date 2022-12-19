```
#define MAX_ANIMAL 20000

typedef struct{
  int index;
  int timeStamp;
}Animal;

typedef struct {
  Animal animalBuf[MAX_ANIMAL];
  Animal *head;
  Animal *tail;
} AnimalQueue;

typedef struct {
  AnimalQueue queue[2];
} AnimalShelf;

void initQueue(AnimalQueue *queue)
{
  queue->head = queue->animalBuf;
  queue->tail = queue->animalBuf;
}

bool empty(AnimalQueue *queue)
{
  return queue->head == queue->tail;
}

void enQueue(AnimalQueue *queue, int index)
{
  static int currentStamp = 0;

  if(queue->tail >= queue->animalBuf + MAX_ANIMAL)
    queue->tail = queue->animalBuf;

  queue->tail->index = index;
  queue->tail->timeStamp = currentStamp++;

  (queue->tail)++;
}

int deQueue(AnimalQueue *queue)
{
  int index = queue->head->index;

  (queue->head)++;

  if(queue->head >= queue->animalBuf + MAX_ANIMAL)
    queue->head = queue->animalBuf;

  return index;
}

int peekTime(AnimalQueue *queue)
{
  return empty(queue) ? INT_MAX : queue->head->timeStamp;
}

AnimalShelf* animalShelfCreate() {
  AnimalShelf *obj = malloc(sizeof(AnimalShelf));
  initQueue(obj->queue);
  initQueue(obj->queue + 1);

  return obj;
}

void animalShelfEnqueue(AnimalShelf* obj, int* animal, int animalSize) {
  enQueue(obj->queue + animal[1], animal[0]);
}

int *animalShelfDequeue(AnimalShelf* obj, int type, int* retSize)
{
  int *ret = malloc(sizeof(int) * 2);
  *retSize = 2;
  ret[0] = -1;
  ret[1] = -1;

  AnimalQueue *queue = obj->queue + type;

  if(!empty(queue))
  {
    ret[0] = deQueue(queue);
    ret[1] = type;
  }

  return ret;
}

int* animalShelfDequeueAny(AnimalShelf* obj, int* retSize) 
{
  int type = peekTime(obj->queue) < peekTime(obj->queue + 1) ? 0 : 1;

  return animalShelfDequeue(obj, type, retSize);
}

int* animalShelfDequeueDog(AnimalShelf* obj, int* retSize) 
{
  return animalShelfDequeue(obj, 1, retSize);
}

int* animalShelfDequeueCat(AnimalShelf* obj, int* retSize) 
{
  return animalShelfDequeue(obj, 0, retSize);
}

void animalShelfFree(AnimalShelf* obj) 
{
  free(obj);
}
```
