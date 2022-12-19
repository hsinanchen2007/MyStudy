/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct richer {
    int personNo;
    struct richer* next;
};

struct person {
    int quiet;
    struct richer* head;
};

extern int dfs(struct person* people, int node, int* quiet, int* result);
extern void dfsFreeMem(struct richer* richOne);

int* loudAndRich(int** richer, int richerSize, int* richerColSize, int* quiet, int quietSize, int* returnSize){
    struct person *people = (struct person* )malloc(sizeof(struct person) * quietSize);
    memset(people, 0, sizeof(struct person) * quietSize);

    int* result = (int* )malloc(sizeof(int)*quietSize);
    memset(result, -1, sizeof(int)*quietSize);

    //1.初始化每个人的quiet值和next，next 将是一个链表，标识比他富有的所有的人。
    for (int j = 0; j < quietSize; j++) {
        people[j].quiet = quiet[j];
        people[j].head = NULL;
    }
    
    //2.先根据有钱人的关系建立一个图。
    for (int i = 0; i < richerSize; i++) {
        int left = richer[i][0];
        int right = richer[i][1];

        struct richer * richone = (struct richer*)malloc(sizeof(struct richer));
        richone->personNo = left;
        richone->next = NULL;

        if (people[right].head == NULL) {
            people[right].head = richone; 
        } else {
            richone->next = people[right].head;
            people[right].head = richone;
        }
    }

    //3.根据图的关系遍历所有人，寻找他有钱还比他安静的人
    for(int i = 0; i <quietSize; i++) {
        if (result[i] == -1) {
            dfs(people, i, quiet, result); 
        }
    }

    //4.释放内存
    for (int k = 0; k < quietSize; k++) {
        dfsFreeMem(people[k].head);
    }

    free(people);

    //5.返回结果
    *returnSize = quietSize;
    return result;
}

int dfs(struct person* people, int node, int* quiet, int* result) {
    if (result[node] == -1) {
        result[node] = node;
    } else {
        //已经算出来的节点，就不要再算了，否则会有用例超时
        return result[node];
    }

    //后续遍历，先纵向遍历一直到叶子节点，再在回溯的过程中横向遍历所有的兄弟节点
    struct richer* childNode = people[node].head;
    while (childNode != NULL) {
        int tempNode = dfs(people, childNode->personNo, quiet, result);
        result[node] = quiet[result[node]] > quiet[tempNode] ? tempNode : result[node];
        childNode = childNode->next;
    }

    return result[node];
}

//递归释放内存
void dfsFreeMem(struct richer* richOne) {
    if (richOne == NULL) {
        return;
    }

    dfsFreeMem(richOne->next);

    free(richOne);
}
