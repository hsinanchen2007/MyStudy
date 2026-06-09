/**
 * 类比LeetCode 767 重构字符串
 * 其实这道题，就是要求(N + 1)个字符不相连。
 * 想到这层，那么，这道题就简单了。
 * 优先，26个字母hash，然后根据出现次数排序（这块注意一下，最好除了个数外，再加一个字母的顺序，不然容易乱序）。
 * 然后，将TopN的hash count --，当已经为0时，说明已经无法做到任务调度自调节了，我们就要往里面加进去剩余的时间（n + 1 - i）
 * 这里需要注意的一个事儿是，当最后一个task调度出去后，就不需要再加调度时间（n + 1 - i）了，所以要有一个计数。
 **/

```

typedef struct {	
    char key;	
    int count;
} Node;	
    
int MyCompStruct(const void *a, const void *b)	
{	
    const Node *nodeA = (const Node *)a;	
    const Node *nodeB = (const Node *)b;	
        
    if (nodeA->count == nodeB->count) {
        return nodeA->key - nodeB->key;
    } else {
        return nodeB->count - nodeA->count;
    }
    
}	

#define MAX_KEY    26

int leastInterval(char* tasks, int tasksSize, int n){

    Node hashList[MAX_KEY] = {0};
    int result = 0;
    int tasksSizeNow = tasksSize;

    if (tasks == NULL) {
        return 0;
    }

    for (int i = 0; i < MAX_KEY; i++) {
        hashList[i].key = 'A' + i;
    }

    for (int i = 0; i < tasksSize; i++) {
        hashList[tasks[i] - 'A'].count++;
    }

    while (1) {
        qsort(hashList, MAX_KEY, sizeof(Node), MyCompStruct);

        if (hashList[0].count == 0) {
            break;
        }

        for (int i = 0; i < n + 1; i++) {
             if (hashList[i].count != 0) {
                 hashList[i].count--;
                 result++;

                 tasksSizeNow--;
                 if (tasksSizeNow == 0) {
                     break;
                 }
             } else {
                 result += (n + 1 - i);
                 break;
             }
        }
    }

    return result;

}
```
