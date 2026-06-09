### 解题思路
时间复杂度基本上没优化，空间复杂度还行，编程时设置边界条件太多出了很多差错

### 代码

```c
//插入排序
void insertSort(int * arr, int size){
    int i,j;
    if(size<=1)
        return;
    for(i=1;i<size;i++){
        int value = arr[i];
        int j = i-1;
        for(;j>=0;--j){
            if(arr[j] < value){
                arr[j+1] = arr[j];
            }else{
                break;
            }
        }
        arr[j+1] = value;
    }
}

int leastInterval(char* tasks, int tasksSize, int n){
    int taskRepeat[26]={};
    int i,j,taskTypes=0,timeCost=0,queueSize=0;;

    for(i=0;i<tasksSize;i++){//不同任务个数统计
        taskRepeat[tasks[i]-'A']++;
    }


    for(i=0,j=0;i<26;i++){//去掉多余占位字符，得出任务种类数
        if(taskRepeat[j]!=0){
            taskRepeat[taskTypes++]=taskRepeat[j++];
        }
    }

    insertSort(taskRepeat, taskTypes);//插入排序，实现不同类型任务个数的从大到小排列

    while(taskRepeat[0]>1){//选取组合长度小于（n+1）的尽量长任务队列
        for(j=0,queueSize=0;j<taskTypes;j++){
            if(taskRepeat[j]>0){
                if(queueSize<(n+1)){
                    queueSize++;
                    taskRepeat[j]--;
                }else{
                    break;
                }
            }
        }
        insertSort(taskRepeat,taskTypes);
        timeCost += queueSize>(n+1)?queueSize:(n+1);

    }

    for(j=0;j<taskTypes;j++){//最后不需要考虑冷却时间的队列
        if(taskRepeat[j]>0)
            timeCost++;
    }
     
    return timeCost;
}
```