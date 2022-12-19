// author by : zhangyunmei 20200409
#define MAX_USER 400
#define ARR_LENGTH 30
typedef struct {
    int id;
    char* timestamp;
} Log;
typedef struct {
    Log userLog[MAX_USER];
    int size;
} LogSystem;


LogSystem* logSystemCreate() {
    LogSystem* mySystem = (LogSystem*)malloc(sizeof(LogSystem));
    mySystem->size = 0;
    return mySystem;
}

void logSystemPut(LogSystem* obj, int id, char * timestamp) {
    if(obj == NULL || timestamp == NULL) {
        return;
    }
    (obj->userLog[obj->size]).id = id;
    (obj->userLog[obj->size]).timestamp = timestamp;
    obj->size++;
    return;
}

int* logSystemRetrieve(LogSystem* obj, char * s, char * e, char * gra, int* retSize) {
    if(obj == NULL || (s == NULL) || (e == NULL) || (gra == NULL) || (retSize == NULL)) {
        return NULL;
    }
    int i;
    char left[ARR_LENGTH] = {""};
    char right[ARR_LENGTH] = {""};
    char target[ARR_LENGTH] = {""};
    int count = 0;
    int* res = (int*)malloc(sizeof(int) * MAX_USER);

    memset(res, 0, sizeof(int) * MAX_USER);
    for(i = 0; i < obj->size; i++) {
        if(strcmp(gra, "Year") == 0) {
            strncpy(left, s, 4);
            strncpy(right, e, 4);
            strncpy(target, obj->userLog[i].timestamp, 4);
            if(strcmp(left, target) > 0 || strcmp(right, target) < 0){
            }else {
                res[count] = obj->userLog[i].id;
                count++;
            }
        }
        if(strcmp(gra, "Month") == 0) {
            strncpy(left, s, 7);
            strncpy(right, e, 7);
            strncpy(target, obj->userLog[i].timestamp, 7);
            if(strcmp(left, target) > 0 || strcmp(right, target) < 0){
            }else {
                res[count] = obj->userLog[i].id;
                count++;
            }
        }
        if(strcmp(gra, "Day") == 0) {
            strncpy(left, s, 10);
            strncpy(right, e, 10);
            strncpy(target, obj->userLog[i].timestamp, 10);
            if(strcmp(left, target) > 0 || strcmp(right, target) < 0){
            }else {
                res[count] = obj->userLog[i].id;
                count++;
            }
            
        }
        if(strcmp(gra, "Hour") == 0) {
            strncpy(left, s, 13);
            strncpy(right, e, 13);
            strncpy(target, obj->userLog[i].timestamp, 13);
            if(strcmp(left, target) > 0 || strcmp(right, target) < 0){
            }else {
                res[count] = obj->userLog[i].id;
                count++;
            }
            
        }
        if(strcmp(gra, "Minute") == 0) {
            strncpy(left, s, 16);
            strncpy(right, e, 16);
            strncpy(target, obj->userLog[i].timestamp, 16);
            if(strcmp(left, target) > 0 || strcmp(right, target) < 0){
            }else {
                res[count] = obj->userLog[i].id;
                count++;
            }
            
        }
        if(strcmp(gra, "Second") == 0) {
            strncpy(left, s, 19);
            strncpy(right, e, 19);
            strncpy(target, obj->userLog[i].timestamp, 19); // 这个函数需要掌握，主要是从字符串中取出若干连续字符
            if(strcmp(left, target) > 0 || strcmp(right, target) < 0){
            }else {
                res[count] = obj->userLog[i].id;
                count++;
            }
            
        }
    }
    int* resFinal = (int*)malloc(sizeof(int) * count);
    for(i = 0; i < count; i++) {
        resFinal[i] = res[i];
    }
    *retSize = count;
    return resFinal;
}

void logSystemFree(LogSystem* obj) {
    if(obj != NULL) {
        free(obj);
    }
}

/**
 * Your LogSystem struct will be instantiated and called as such:
 * LogSystem* obj = logSystemCreate();
 * logSystemPut(obj, id, timestamp);
 
 * int* param_2 = logSystemRetrieve(obj, s, e, gra, retSize);
 
 * logSystemFree(obj);
*/