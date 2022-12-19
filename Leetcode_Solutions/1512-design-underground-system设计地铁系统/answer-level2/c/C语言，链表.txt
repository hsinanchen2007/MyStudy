![result.png](https://pic.leetcode-cn.com/7a3b8f3f4fb0b9e188fcb232226ccfedf91073375357c8c1f10124627a38bcd0-result.png)
```
typedef struct info PASSENGER_INFO;
struct info {
    int id;
    char check_in_station[12];
    char check_out_station[12];
    int check_in_t;
    int check_out_t;
    PASSENGER_INFO *next;
} ;

typedef struct {
    PASSENGER_INFO *info_head;
} UndergroundSystem;


UndergroundSystem* undergroundSystemCreate() {
    UndergroundSystem *sys = (UndergroundSystem*)malloc(sizeof(UndergroundSystem));
    sys->info_head = NULL;
    return sys;
}

void undergroundSystemCheckIn(UndergroundSystem* obj, int id, char * stationName, int t) {
    PASSENGER_INFO *info = (PASSENGER_INFO*)malloc(sizeof(PASSENGER_INFO));
    info->id = id;
    info->check_in_t = t;
    strcpy(info->check_in_station, stationName);
    //头插法
    info->next = obj->info_head;
    obj->info_head = info;
}

void undergroundSystemCheckOut(UndergroundSystem* obj, int id, char * stationName, int t) {
    PASSENGER_INFO *p = obj->info_head;
    while(p != NULL) {
        //因为链表是头插法，所以不用担心重复ID的问题
        if(p->id == id){
            p->check_out_t = t;
            strcpy(p->check_out_station, stationName);
            break;
        }
        p = p->next;
    }
}

double undergroundSystemGetAverageTime(UndergroundSystem* obj, char * startStation, char * endStation) {
    PASSENGER_INFO * p = obj->info_head;
    int time = 0;
    int count = 0;
    while(p != NULL) {
        if((strcmp(p->check_in_station, startStation) == 0) && (strcmp(p->check_out_station, endStation) == 0)){
            time += p->check_out_t - p->check_in_t;
            count ++;
        }
        p = p->next;
    }
    if(count > 0 ){
        return (double)time / count;
    }
    return 0;
}

void undergroundSystemFree(UndergroundSystem* obj) {
    PASSENGER_INFO * p = obj->info_head, *p_next = NULL;
    if(p == NULL) return;
    do{
        p_next = p->next;
        free(p);
        p = p_next;
    }while(p_next != NULL);
    free(obj);
}
```
