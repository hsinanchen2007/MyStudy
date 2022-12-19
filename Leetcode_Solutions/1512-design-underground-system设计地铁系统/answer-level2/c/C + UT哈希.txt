### 解题思路
C + UT哈希

### 代码

```c
typedef struct {
    int id;
    char sStationName[20];
    char eStationName[20];
    int inTime;
    int outTime;
} UndergroundSystem;

typedef struct {
    char Name[40];
    double time;
    int cnt;
    UT_hash_handle hh;
} stationnode;
UndergroundSystem* undergroundSystemCreate() {
    UndergroundSystem* ptr = (UndergroundSystem*) malloc(sizeof(UndergroundSystem)*1000001);
    memset(ptr,0,1000001*sizeof(UndergroundSystem));
    return ptr;
}
void undergroundSystemCheckIn(UndergroundSystem* obj, int id, char * stationName, int t) { 

   obj[id].id = id;
   strcpy(obj[id].sStationName,stationName);
   obj[id].inTime = t; 
}
stationnode* headchar = NULL;
void undergroundSystemCheckOut(UndergroundSystem* obj, int id, char * stationName, int t) {
    stationnode* ptrNode = NULL;
    char Name[40];
    stationnode ptrtmp;
    memset(Name,0,40*sizeof(char));
    strcpy(Name, obj[id].sStationName);
    strcat(Name,stationName);  
    HASH_FIND_STR(headchar, Name, ptrNode);
    if (ptrNode == NULL) {       
        ptrNode = (stationnode*)malloc(sizeof(stationnode));
        memset(ptrNode,0,sizeof(stationnode));
        ptrNode->time = t - obj[id].inTime;   
        ptrNode->cnt++; 
        strcpy(ptrNode->Name, obj[id].sStationName);
        strcat(ptrNode->Name,stationName);  
        HASH_ADD_STR(headchar, Name, ptrNode);
    } else {
        ptrNode->time += t - obj[id].inTime; 
        ptrNode->cnt++;
    }
}
double undergroundSystemGetAverageTime(UndergroundSystem* obj, char * startStation, char * endStation) {
    int cnt = 0;
    double sum = 0;
    char Name[40];
    stationnode* ptrNode;
    strcpy(Name, startStation);
    strcat(Name, endStation);
    HASH_FIND_STR(headchar, Name, ptrNode);
    sum = ptrNode->time / ptrNode->cnt;
    return sum;
}

void undergroundSystemFree(UndergroundSystem* obj) {
    free(obj);
}

/**
 * Your UndergroundSystem struct will be instantiated and called as such:
 * UndergroundSystem* obj = undergroundSystemCreate();
 * undergroundSystemCheckIn(obj, id, stationName, t);
 
 * undergroundSystemCheckOut(obj, id, stationName, t);
 
 * double param_3 = undergroundSystemGetAverageTime(obj, startStation, endStation);
 
 * undergroundSystemFree(obj);
*/
```