```c
void hash(int* arr, char* s) {
    int index = 0;
    for (int i = 0; i < 4; ++i) {
        index = index * 10 + s[i] - '0';
    }
    arr[index] = 1;
    return;
}

bool inHash(int* arr, char* s) {
    int index = 0;
    for (int i = 0; i < 4; ++i) {
        index = index * 10 + s[i] - '0';
    }
    if (arr[index] == 1) {
        return true;
    }
    return false;
}

int openLock(char ** deadends, int deadendsSize, char * target){
    
    char queue[10000][5]; // 记录可能的移动序列（不重复）
    memset(queue[0], '0', 4 * sizeof(char)); // queue[0] = "0000"
    queue[0][4] = '\0';

    int dead[10000]; // 已被搜索或是deadend的序列经哈希索引的值为1
    memset(dead, 0, 10000 * sizeof (int)); // 将dead的值全部置为0
    for (int i = 0; i < deadendsSize; ++i) {
        hash(dead, deadends[i]);
    }
    if (inHash(dead, queue[0]) == true) { // 如果"0000"是其中一个deadend
        return -1;
    }

    // 判断是否永远无法旋转到目标
    bool isSurrounded = false; 
    int count = 0;
    char temp[5];

    for (int i = 0; i < 4; ++i) {
        for (int j = -1; j < 2; j += 2) {
            strcpy(temp, target);
            temp[i] = (temp[i] - '0' + j + 10) % 10 + '0';
            if (inHash(dead, temp) == true) {
                count++;
            }           
        }
    }
    if (count == 8) {
        isSurrounded = true;
    }
    if (isSurrounded == true) {
        return -1;
    }

    int numOfSeq = 0; // 记录当前深度下序列的个数
    int depth = 0;
    count = 1; // 记录下个深度中可能序列的个数

    hash(dead, queue[0]);
    
    int head = 0, tail = 0;
    while (head <= tail) {
        depth++;
        numOfSeq = count;
        count = 0;
        for (int n = 0; n < numOfSeq; n++) {
            char* s = queue[head];
            head++;
            for (int i = 0; i < 4; ++i) {
                for (int j = -1; j < 2; j += 2) {
                    strcpy(temp, s);
                    temp[i] = (temp[i] - '0' + j + 10) % 10 + '0';

                    if (strcmp(temp, target) == 0) {
                        return depth;
                    }
                    
                    // 判断新生成的序列是否是一个deadend,或已被搜索过
                    bool isDeadendOrDuplicate = false;
                    if (inHash(dead, temp) == true) {
                        isDeadendOrDuplicate = true;
                    }  

                    if (isDeadendOrDuplicate == false) { // 既不是deadend，也没有被搜索过
                        tail++;
                        strcpy(queue[tail], temp); // 加入队列
                        hash(dead, queue[tail]);
                        count++;
                    }
                }
            }
        }
    }
    return -1;
}
```
