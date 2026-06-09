```
#include <uthash.h>
#include <stdlib.h>
#include <string.h>

struct pidStruct {
    int pid;
    struct pidStruct *next;
};

struct hash_entry {
    int key;            // key
    struct pidStruct *pids;
    UT_hash_handle hh; 
};

struct hash_entry *gUser = NULL;

// hash 表添加元素
void addUser(int key, struct hash_entry *user) {
    HASH_ADD_INT(gUser, key, user);
}

// 在哈希表中查找一个对象
struct hash_entry *findUser(int pid) {
    struct hash_entry *s;
    HASH_FIND_INT(gUser, &pid, s);

    return s;
}

// 从哈希表中删除一个对象
void deleteUser(struct hash_entry *user) {
    HASH_DEL(gUser, user);  
    free(user);
}

struct pidStruct *createPidNode(int pid, struct pidStruct *next) {
    
    struct pidStruct *child = (struct pidStruct *)malloc(sizeof(struct pidStruct));
    child->pid = pid;
    child->next = next;

    return child;
}

void deletePidNode(struct pidStruct *pids) {  
    struct pidStruct *iter;
    iter = pids;

    while (iter) {
        pids = iter->next;
        free(iter);
        iter = pids;
    }
}

void distroyHash() {
    struct hash_entry *iter;
    struct hash_entry *s;
    struct pidStruct *pids;

    HASH_ITER(hh, gUser, s, iter) {
        struct pidStruct *pids = s->pids; 
        deletePidNode(pids); 
        deleteUser(s); 
    }
}

struct hash_entry * createHash(int key) {
    struct hash_entry *s = (struct hash_entry *)malloc(sizeof(struct hash_entry));
    s->key = key;
    s->pids = NULL;

    return s;
}

void findChild(struct pidStruct *pids, int *result, int *processNum) {
    struct pidStruct *iter;
    struct hash_entry *s;

    for (iter = pids; iter != NULL; iter = iter->next) {
        result[(*processNum)++] = iter->pid;
        s = findUser(iter->pid);
        findChild(s ? s->pids : NULL, result, processNum);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* killProcess(int* pid, int pidSize, int* ppid, int ppidSize, int kill, int* returnSize){
    int i;
    struct hash_entry *hash, *s;
 
    // 记录结果
    int *result = (int *)malloc((pidSize + 1) * sizeof(int));
    memset(result, 0, (pidSize + 1) * sizeof(int));
    result[0] = kill;
    *returnSize = 1;

    // 创建 hash 表
    for (i = 0; i < ppidSize; i++) {
        hash = findUser(ppid[i]);
        if (hash ==  NULL) {
            hash = createHash(ppid[i]);
            // 子进程添加到父进程的链表中
            hash->pids = createPidNode(pid[i], NULL);
            addUser(ppid[i], hash);
        } else {
            // 子进程添加到父进程的链表中
            hash->pids = createPidNode(pid[i], hash->pids);

            //  子进程也创建hash项，子进程的子进程为NULL
            hash = findUser(pid[i]);  
            if (hash == NULL) {
                hash = createHash(pid[i]);
                addUser(pid[i], hash);
            }
        }
    }

    s = findUser(kill);
    findChild(s ? s->pids : NULL, result, returnSize);

    distroyHash();

    return result;
}

```
