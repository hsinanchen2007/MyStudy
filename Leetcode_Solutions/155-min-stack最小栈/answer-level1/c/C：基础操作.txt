思路：
定义：结构体stack（定长数组+top标记）
初始化：malloc申请结构体和结构体的数组内存，top默认-1表示空栈
入栈：检查是否满栈（留一个空位），top加1，赋值
出栈：检查是否空栈（top == -1），top减1
找最小值：检查是否空栈，遍历输出最小值
释放：先释放结构体里的数组内存，指针置NULL，再释放结构体内存，指针置NULL
```
#define MAXSIZE 1000

typedef struct {
    int *data;
    int top;
} MinStack;

MinStack* minStackCreate() {
    MinStack *obj = malloc(sizeof(MinStack));
    obj->data = malloc(MAXSIZE*sizeof(int));
    obj->top = -1;
    return obj;
}

void minStackPush(MinStack* obj, int x) {
  if(obj->top == MAXSIZE-1){
      return;
  } else {
      obj->top++;
      obj->data[obj->top] = x;
  }
}

void minStackPop(MinStack* obj) {
  if(obj->top == -1){
      return;
  }else{
      obj->top--;
  }
}

int minStackTop(MinStack* obj) {
  if(obj->top == -1){
      return;
  }
  return obj->data[obj->top];
}

int minStackGetMin(MinStack* obj) {
  if(obj->top == -1) {
      return;
  }
  int min = obj->data[0];
  for(int i = 0;i <= obj->top; i++){
      if(obj->data[i] < min){
          min = obj->data[i];
      }
  }
  return min;
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    obj->data = NULL;
    free(obj);
    obj = NULL;
}
```