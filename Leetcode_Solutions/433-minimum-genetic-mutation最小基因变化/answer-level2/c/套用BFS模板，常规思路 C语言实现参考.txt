### 解题思路
套用BFS模板，常规思路
       1) BFS bank 相当于是搜索路径
       2）节点扩展条件，目标节点与源节点只存在一个字符的差异
       3）目标节点必须要在bank中

### 代码

```c
#define MAX_SIZE 10000
typedef struct tagMyQueue
{
    char * que[MAX_SIZE];
    int rear;
    int front;
} MyQueue;

MyQueue * CreateMyQue()
{
    MyQueue * que = malloc(sizeof(MyQueue));
    que->rear = 0;
    que->front = 0;
    return que;
} 
void DelMyQue(MyQueue *que)
{
    free(que);
}
void EnMyQue(MyQueue *que,char *bank){
    que->que[que->rear] = bank;
    que->rear++;
}
void DeMyQue(MyQueue * que, char **bank)
{
    *bank = que->que[que->front];
    que->front++;
}
int IsMyQueEmpty(MyQueue * que)
{
    return que->rear == que->front;
}
int GetMyQueSize(MyQueue * que)
{
    return que->rear - que->front;
}
int CheckInBank(char * end, char ** bank, int bankSize)
{
    for(int i =0; i < bankSize;i++){
        if(strcmp(end,bank[i]) == 0){
            return 1;
        }
    }
    return 0;
}
int IsBankCanChange(char * start, char * end)
{
    int lenS = strlen(start);
    int lenE = strlen(end);
    if(lenE != lenS) {
        return  0;
    }
    int diff =0 ;
    for(int i=0;i< lenS;i++)
    {
        if(start[i] != end[i]){
            diff++;
        }
    }
    return diff == 1 ? 1 : 0;
}
/*******************************************************************************
  函 数 名		:  minMutation
  功能描述		:  
       1) BFS bank 相当于是搜索路径
       2）节点扩展条件，目标节点与源节点只存在一个字符的差异
       3）目标节点必须要在bank中
  输入参数		:  None
  输出参数		:  None
  返 回 值		:  None
*******************************************************************************/
int minMutation(char * start, char * end, char ** bank, int bankSize)
{
    int ans = 0;
    if(CheckInBank(end,bank,bankSize) == 0){
        return -1;
    }
    MyQueue * que = CreateMyQue();
    char * curBank;
    char * used = malloc(bankSize*sizeof(char));
    memset(used,0,bankSize*sizeof(char));
    EnMyQue(que,start);
    while (!IsMyQueEmpty(que))
    {
        int queSize = GetMyQueSize(que);
        for(int i =0;i< queSize;i++)
        {
             DeMyQue(que,&curBank);
             if(strcmp(curBank,end) == 0){
                 return ans;
             }
             for(int j= 0;j<bankSize;j++){
                 if(used[j] == 0 && IsBankCanChange(curBank,bank[j])){
                     EnMyQue(que,bank[j]);
                     used[j] = 1;
                 }
             }
        }
        ans++;
    }
    DelMyQue(que);
    return -1;
}
```