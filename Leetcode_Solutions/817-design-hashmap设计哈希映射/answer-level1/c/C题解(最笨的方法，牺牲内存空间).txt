```
执行用时 :180 ms, 在所有 C 提交中击败了38.89%的用户
内存消耗 :317.7 MB, 在所有 C 提交中击败了5.55%的用户
```
***虽然牺牲了内存，但是时间还是减不下去***
```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 1000000
#define NULLVALUE -1
#define VISITED 1
#define NOTVISITED 0
typedef struct {
    int *hashmap;
    int *visited;
} MyHashMap;
typedef enum my_bool{
  my_false=0,my_true
}my_bool;
int hash(int key);
/** Initialize your data structure here. */
my_bool myHashMapSearch(MyHashMap *obj,int key,int *addr){
  *addr=hash(key);
  if(obj->visited[*addr]==VISITED){
    return my_true;
  }
  return my_false;
}
MyHashMap* myHashMapCreate() {
    MyHashMap *H=(MyHashMap *)malloc(sizeof(MyHashMap));
    H->hashmap=(int *)malloc(SIZE*sizeof(int));
    H->visited=(int *)malloc(SIZE*sizeof(int));
    memset(H->hashmap,NULLVALUE,SIZE*sizeof(int));
    memset(H->visited,NOTVISITED,SIZE*sizeof(int));
    return H;
}
int hash(int key){
  int addr=key%SIZE;
  return addr;
}
/** value will always be non-negative. */
void myHashMapPut(MyHashMap* obj, int key, int value) {
  int addr;
  if(myHashMapSearch(obj,key,&addr)){
    obj->hashmap[addr]=value;
  }else{
    obj->hashmap[addr]=value;
    obj->visited[addr]=VISITED;
  }
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
int myHashMapGet(MyHashMap* obj, int key) {
  int addr;
  if(myHashMapSearch(obj,key,&addr)){
    return obj->hashmap[addr];
  }
  return -1;
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void myHashMapRemove(MyHashMap* obj, int key) {
   int addr;
  if(myHashMapSearch(obj,key,&addr)){
    obj->hashmap[addr]=NULLVALUE;
    obj->visited[addr]=NOTVISITED;
  }
}

void myHashMapFree(MyHashMap* obj) {
    free(obj->hashmap);
    obj->hashmap=NULL;
    free(obj->visited);
    obj->visited=NULL;
    free(obj);
    obj=NULL;
}
void myHashMapPrintf(MyHashMap *obj){
  printf("\n");
  for(int i=0;i<SIZE;i++){
    printf("%4d",obj->hashmap[i]);
  }
  printf("\n");
  for(int i=0;i<SIZE;i++){
    printf("%4d",obj->visited[i]);
  }
  printf("\n");
}
int main(){
  printf("start\n");
  MyHashMap *H=myHashMapCreate();
  myHashMapPrintf(H);
  myHashMapPut(H,1,1);
  myHashMapPut(H,2,2);
  myHashMapPrintf(H);
  printf("%d\n",myHashMapGet(H,1));
  printf("%d\n",myHashMapGet(H,3));
  myHashMapPut(H,2,1);
  printf("%d\n",myHashMapGet(H,2));
  myHashMapRemove(H,2);
  printf("%d\n",myHashMapGet(H,2));
  myHashMapFree(H);
  return 0;
}
```
