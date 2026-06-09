1.统计砖的宽度和的方法，找到最多有多少块砖没有穿过，然后算出最少穿过几块砖；
2.这个题目主要l了解哈希表思想和简单的哈希表设计
根据题意，最多有10000块砖，砖的宽度不超过INT_MAX;那么可以设计一个头节点为10000的数组；
数组中记录sum值，和sum值出现的次数；由于最多只能存放10000个数值，sum值最大为0x7fffffff,这里用sum值对10000取余做下标；
如果砖的宽度超过10000，比如1，和100001将放在同一个位置（本题测试用例不涉及），为了加以区分，所以需要用一个链表来存放；
1放在g_map[1]->next位置；
10001放在g_map[1]->next->next位置；
以此类推；


#define MOD_SIZE    10000

#define GetMapIdx(sum)  (sum%MOD_SIZE)
struct MAP{
    int sum;
    int count;
    struct MAP *next;
};

struct MAP g_map[MOD_SIZE] = {0};


void Save(int sum)
{
    int idxMap;
    struct MAP *p, *temp;

    idxMap = GetMapIdx(sum);
    temp = &g_map[idxMap];

    while(temp->next != NULL){
        temp = temp->next;
        //存在重复值，count+1
        if (temp->sum == sum){
            temp->count++;
            return;
        }
    }

    //哈希表中不存在重复值，重新申请空间存放
    p = (struct MAP*)malloc(sizeof(struct MAP));
    p->sum = sum;
    p->count = 1;
    p->next = NULL;
    temp->next = p;    
    return;
}
int leastBricks(int** wall, int wallSize, int* wallColSize)
{
    int i, j;
    int sum, max;
    struct MAP *p, *temp;
    
    //初始化
    memset(&g_map[0], 0, sizeof(struct MAP)*MOD_SIZE);

    //记录哈希表
    for(i=0;i<wallSize;i++){
        sum = 0;
        for(j=0;j<wallColSize[i]-1;j++){
            sum += wall[i][j];
            Save(sum);
        }
    }

    //查找哈希表
    max = 0;
    for(i=0;i<MOD_SIZE;i++){
        temp = g_map[i].next;
        while(temp != NULL){
            if (max<temp->count){
                max = temp->count;
            }
            p = temp;
            temp = temp->next;
            free(p);
        }
    }

    return (wallSize-max);
}
