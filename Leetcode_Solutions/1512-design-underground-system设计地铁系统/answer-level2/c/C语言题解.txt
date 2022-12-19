```
typedef struct {
    int id;
    char inStationName[12];
    char outStationName[12];
    int inTime;
    int outTime;
}Passenger;

typedef struct railway{
    Passenger passenerInfo;
    struct railway *next;
} UndergroundSystem;


UndergroundSystem* undergroundSystemCreate() {
    UndergroundSystem *obj = NULL;
    obj = (UndergroundSystem*)malloc(sizeof(UndergroundSystem));
    if (obj == NULL) {
        return NULL;
    }
    (void)memset(obj, 0, sizeof(UndergroundSystem));

    return obj;
}

void undergroundSystemCheckIn(UndergroundSystem* obj, int id, char * stationName, int t) {
    UndergroundSystem *temp = NULL;
    UndergroundSystem *tail = NULL;
    temp = obj;
    while (temp != NULL) {
        if (temp->passenerInfo.id == 0) {
            temp->passenerInfo.id = id;
            strncpy(temp->passenerInfo.inStationName, stationName, strlen(stationName));
            temp->passenerInfo.inTime = t;
            return;
        }

        tail = temp;
        temp = temp->next;
    }

    temp = (UndergroundSystem *)malloc(sizeof(UndergroundSystem));
    if (temp == NULL) {
        return;
    }
    (void)memset(temp, 0, sizeof(UndergroundSystem));

    temp->passenerInfo.id = id;
    strncpy(temp->passenerInfo.inStationName, stationName, strlen(stationName));
    temp->passenerInfo.inTime = t;

    tail->next = temp;
    
    return;
}

void undergroundSystemCheckOut(UndergroundSystem* obj, int id, char * stationName, int t) {
    UndergroundSystem *temp = NULL;
    temp = obj;

    char outStationName[12];
    (void)memset(outStationName, 0, sizeof(outStationName));

    while (temp != NULL) {
        if (temp->passenerInfo.id == id) {
            /* 这个是用来判断同一个乘客在中途乘坐多次车 */
            if (strcmp(temp->passenerInfo.outStationName, outStationName) != 0) {
                temp = temp->next;
                continue;
            }
            strncpy(temp->passenerInfo.outStationName, stationName, strlen(stationName));
            temp->passenerInfo.outTime = t;
            return;
        }

        temp = temp->next;
    }

    return;
}

double undergroundSystemGetAverageTime(UndergroundSystem* obj, char * startStation, char * endStation) {
    UndergroundSystem *temp = NULL;
    double timeTotal;
    double count;
    temp = obj;
    timeTotal = 0;
    count = 0;
    while (temp != NULL) {
        if (strcmp(temp->passenerInfo.outStationName, endStation) == 0 &&
            strcmp(temp->passenerInfo.inStationName, startStation) == 0) {
            timeTotal += ((double)temp->passenerInfo.outTime - (double)temp->passenerInfo.inTime);
            count++;
        }
        temp = temp->next;
    }

    if (count == 0) {
        return 0;
    }

    return timeTotal / count;
}

void undergroundSystemFree(UndergroundSystem* obj) {
    UndergroundSystem *temp = NULL;
    UndergroundSystem *tempFree = NULL;
    temp = obj;
    while (temp != NULL) {
        tempFree = temp;
        temp = temp->next;
        free(tempFree);
    }
}
```
