### 解题思路
/*
1、先找出人中编号最大值，申请数组存储每个人获取投票数和最后获取投票的时间，人编号从0开始；
2、累计计数，每个时间索引点当前得票最多的人胜利，得票一样后面一个胜利，记录获胜人编号和顺次时间；
3、应用二分查找找到t时间获取投票数最多的人，注意t在有效时间外的特殊情况处理；
*/

### 代码

```c
#if 0
#define MY_DEBUG(index) printf("%d, pos: %d\n", __LINE__, index)
#else
#define MY_DEBUG(index)
#endif

typedef struct {
    int time;
    int cnt;

    int currentTime;
    int win;
} TopVotedCandidate;

static int FindMaxNum(int* persons, int personsSize)
{
    int num = 0;

    for(int i = 0; i < personsSize; i++) {
        if (persons[i] > num) 
            num = persons[i];
    }
    return num;
}

int FindMaxCand(TopVotedCandidate *persons, int size)
{
    int target = 0;

    for(int i = 0; i <= size; i++){
        if (persons[i].cnt > persons[target].cnt || (persons[i].cnt == persons[target].cnt && persons[i].time > persons[target].time))
            target = i;
    }
    return target;
}


static int g_maxTimeIndex = 0;
TopVotedCandidate* topVotedCandidateCreate(int* persons, int personsSize, int* times, int timesSize) {
    int maxNum = FindMaxNum(persons, personsSize);
    TopVotedCandidate *personsList = (TopVotedCandidate *)malloc(sizeof(TopVotedCandidate) * (maxNum + 1));
    TopVotedCandidate *obj = (TopVotedCandidate *)malloc(sizeof(TopVotedCandidate) * timesSize);
    int i = 0;

    MY_DEBUG(maxNum);
    g_maxTimeIndex = timesSize;
    MY_DEBUG(timesSize);
    memset(personsList, 0, sizeof(TopVotedCandidate) * (maxNum + 1));
    memset(obj, 0, sizeof(TopVotedCandidate) * timesSize);
    MY_DEBUG(0);
    for (i = 0; i < timesSize; i++) {
        int personNum = persons[i];

        personsList[personNum].cnt++;
        personsList[personNum].time = times[i];

        int maxIndex = FindMaxCand(personsList, maxNum);
        MY_DEBUG(maxIndex);
        obj[i].currentTime = times[i];
        obj[i].win = maxIndex;
    }
    return obj;
}

int topVotedCandidateQ(TopVotedCandidate* obj, int t) {
  int left = 0;
  int right = g_maxTimeIndex - 1;

  MY_DEBUG(left);
  MY_DEBUG(right);
  if (t >= obj[right].currentTime)
    return obj[right].win;
  if (t <= obj[left].currentTime)
    return obj[left].win;
  while(right - left > 1) {
      MY_DEBUG(left);
      MY_DEBUG(right);
      int mid = (left + right)/2;
      if (obj[mid].currentTime > t)
        right = mid;
      else
        left = mid;
  }
  return obj[left].win;
}

void topVotedCandidateFree(TopVotedCandidate* obj) {
    free(obj);
    g_maxTimeIndex = 0;
}

/**
 * Your TopVotedCandidate struct will be instantiated and called as such:
 * TopVotedCandidate* obj = topVotedCandidateCreate(persons, personsSize, times, timesSize);
 * int param_1 = topVotedCandidateQ(obj, t);
 
 * topVotedCandidateFree(obj);
*/
```