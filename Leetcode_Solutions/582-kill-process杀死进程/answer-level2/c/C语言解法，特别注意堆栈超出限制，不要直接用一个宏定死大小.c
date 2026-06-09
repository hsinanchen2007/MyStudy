#define MAX(a, b) (a>b?a:b)

typedef struct {
    int pid;
    int sonCnt;
    int* sonPids;//按需分配数组大小，而不是用静态数组定死大小
} Node;

/*递归查找进程kill的子进程数量*/
void CalPid(Node* nodeArray, int kill, int* outPid, int* returnSize, int pidNum)
{
    int i = 0;
    int temp = 0;

    if (kill == 0) {
        return;
    }

    outPid[*returnSize] = kill;
    (*returnSize)++;

    if (kill > pidNum) {
        return;
    }

    for (i = 0; i < nodeArray[kill].sonCnt; i++) {
        temp = (nodeArray[kill].sonPids)[i];
        CalPid(nodeArray, temp, outPid, returnSize, pidNum);
    }

}

int* killProcess(int* pid, int pidSize, int* ppid, int ppidSize, int kill, int* returnSize){
    int i = 0;
    int index = 0;
    int ppidIndex = 0;
    int pidNum = 0;
    *returnSize = 0;

    int* outPid = malloc(sizeof(int) * pidSize);

    for (i = 0; i < ppidSize; i++) {
        pidNum = MAX(pidNum, ppid[i]);
        pidNum = MAX(pidNum, pid[i]);
    }
    pidNum++;

    Node* nodeArray = malloc(sizeof(Node) * pidNum);
    for (i = 0; i < pidNum; i++) {
        nodeArray[i].pid = i;
        nodeArray[i].sonCnt = 0;
    }

    for (i = 0; i < ppidSize; i++) {
        ppidIndex = ppid[i];
        nodeArray[ppidIndex].sonCnt++;
    }
    for (i = 0; i < pidNum; i++) {
        nodeArray[i].sonPids = malloc(sizeof(int) * nodeArray[i].sonCnt);//按需分配
        nodeArray[i].sonCnt = 0;
    }
    for (i = 0; i < ppidSize; i++) {
        ppidIndex = ppid[i];
        index = nodeArray[ppidIndex].sonCnt;
        (nodeArray[ppidIndex].sonPids)[index] = pid[i];
        nodeArray[ppidIndex].sonCnt++;
    }

    CalPid(nodeArray, kill, outPid, returnSize, pidNum);

    return outPid;
}