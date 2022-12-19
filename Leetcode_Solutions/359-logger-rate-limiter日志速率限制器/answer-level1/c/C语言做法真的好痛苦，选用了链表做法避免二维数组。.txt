### 解题思路
此处撰写解题思路

### 代码

```c
typedef struct {
    char *msg;
    int stamp;
    struct Logger* next;
} Logger;
#define MAXSIZE 1000
/** Initialize your data structure here. */

Logger* loggerCreate() {
    Logger* Log = (Logger*)malloc(sizeof(Logger));
    if (!Log) {
        return NULL;
    }
    Log->msg = (char*)malloc(sizeof(char) * MAXSIZE);
    Log->stamp = 0;
    Log->next = 0;
    return Log;
}

void StackPush(Logger* obj, int timestamp, char * message){
     Logger* T = (Logger*)malloc(sizeof(Logger));
    if (!T) {
        return ;
    }
    T->msg = (char*)malloc(sizeof(char) * MAXSIZE);     
    strcpy(T->msg, message);
    T->stamp = timestamp;
    T->next = obj->next;
    obj->next = T;
    return;
}


bool HasSameChar(Logger* obj,  char* message, int *stamp) {
    if (!message) return false;
    while (obj != NULL) { 
        if (0 == strcmp(obj->msg, message)) {
            *stamp = obj->stamp;
            return true;
        }
        obj = obj->next;
    }
    return false;
}
/** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
bool loggerShouldPrintMessage(Logger* obj, int timestamp, char * message) {
    int val;
    if(HasSameChar(obj, message, &val)) {
        if (timestamp - val >= 10) {
            StackPush(obj, timestamp, message);
            return true;
        } else {
            return false;
        }
    } else {
        StackPush(obj, timestamp, message);
        return true;
    }
    return true;
}

void loggerFree(Logger* obj) {
    free(obj->msg);
    free(obj);
    return;
}

/**
 * Your Logger struct will be instantiated and called as such:
 * Logger* obj = loggerCreate();
 * bool param_1 = loggerShouldPrintMessage(obj, timestamp, message);
 
 * loggerFree(obj);
*/
```