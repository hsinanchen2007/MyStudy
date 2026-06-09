```
#define MAXSIZE 2000
typedef struct {
    int *data;
    int top;
} MinStack;


/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *obj;
    obj=malloc(sizeof( MinStack));
    obj->data=malloc(sizeof(int)*MAXSIZE);
    obj->top=0;
    return obj;
}

void minStackPush(MinStack* obj, int x) {
  if((obj->top)==0)
  {
       obj->data[(obj->top)++]=x;
       obj->data[(obj->top)++]=x;
  }
  else if(obj->top==MAXSIZE-2)
  {

  }

  else 
  {
      int temp=obj->data[obj->top-1];//注意
      obj->data[(obj->top)++]=x;

      if(temp<x)
          obj->data[(obj->top)++]=temp;
      else
          obj->data[(obj->top)++]=x;

  }  

}

void minStackPop(MinStack* obj) {
  if(obj->top<0)
    return;
   obj->top--;
   obj->top--;
}

int minStackTop(MinStack* obj) {
    if(obj->top==0)
      return;
    return obj->data[(obj->top)-2];
}

int minStackGetMin(MinStack* obj) {

    return obj->data[(obj->top)-1];
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    obj->data=NULL;
    free(obj);

}


```
//利用min解决最小值问题，引用INT_MAX值

```
#define maxSize 2000

typedef struct {
    int *data;
    int min;
    int tos;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate() {
    MinStack *obj = malloc(sizeof(MinStack));
    obj->data = malloc(maxSize * sizeof(int));
    obj->tos = -1;
    obj->min = INT_MAX;
    return obj;
}

void minStackPush(MinStack* obj, int x) {
    if(obj->tos==maxSize-1)
    {

    }
   else
   {
    obj->tos++;
    obj->data[obj->tos] = x;
    if (x < obj->min)
        obj->min = x;
   }

}

void minStackPop(MinStack* obj) {
   
   if(obj->tos==-1)
   {

   }
   else
   {
      obj->tos--;
      obj->min = INT_MAX;
      for (int i = 0; i <= obj->tos; i++)
      {
        if (obj->min > obj->data[i])
        {
            obj->min = obj->data[i];
        }
      }
   }
}

int minStackTop(MinStack* obj) {
    if(obj->tos==-1)
      return;
    return (obj->data[obj->tos]);
}

int minStackGetMin(MinStack* obj) {
    return (obj->min);
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    obj->data=NULL;
    free(obj);
}
```
