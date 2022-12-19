```
bool subFucAllTrue(int roomsSize, int *flag) {
    int i;
    for (i = 0; i < roomsSize; i++) {
        if (flag[i] == 0) {
            return false;
        }
    }
    return true;
}

bool subFunc(int** rooms, int roomsSize, int* roomsColSize, int index, int *flag) {
    int i;
    int j;
    int indexCpy;

    bool returnValue = false;

    if (subFucAllTrue(roomsSize, flag) == true) {
        return true;
    }
    if (rooms[index] == NULL) {
        return false;
    }

    //printf("roomsColSize[%u]: %u\n", index, roomsColSize[index]);
    for (i = 0; i < roomsColSize[index]; i++) {
        indexCpy = rooms[index][i];
        if (flag[indexCpy] == 0) {
            flag[indexCpy] = 1;
            //printf("i: %u, flag[indexCpy]: %u, indexCpy: %u\n", i, flag[indexCpy], indexCpy);
            returnValue = subFunc(rooms, roomsSize, roomsColSize, indexCpy, flag);
            
            /*
            if (returnValue == false) {
                flag[indexCpy] = 0;
            } 
            */
        }
        //printf("pre    index: %u, returnValue: %u, true: %u\n", index, returnValue, true);
        if (returnValue == true) {
            return true;
        }
    }

    //printf("index: %u, returnValue: %u, true: %u\n", index, returnValue, true);
    return returnValue;
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize){
    int i;
    bool returnValue;
    int *flag = (int *)malloc(roomsSize * sizeof(int));
    memset(flag, 0, roomsSize * sizeof(int));

    flag[0] = 1;
    returnValue = subFunc(rooms, roomsSize, roomsColSize, 0, flag);

    return returnValue;
}
```
