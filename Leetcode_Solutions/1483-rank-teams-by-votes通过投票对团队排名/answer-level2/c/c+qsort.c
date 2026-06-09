1. 主要是理清几个维度：
1）投票人数
2）队伍，队伍总数为每一票的长度，并且<=26
3）名次，名次的范围为队伍总数。

2. 遍历输入，转换成team的维度保存，定义一个voteinfo[26][strlen(votes[0])+1];
1）第一维是队伍编号例如'A'对应索引0；
2）第二维[0]是队伍编号例如'A',方便最后输入
3）第二维[i] (i!=0) 是每个名次所出现的次数

2. 使用qsort进行排序后输出
1）先按名次排，某一个名次分出胜负则结果确定
2）名次完全一样，按字母顺序排teama[0] - teamb[0];
```c
int cmpfunc(const void* a, const void* b) {
    const int *teama = (const int*)a;
    const int *teamb = (const int*)b;
    
    int i;
    for (i=1; i<=votenum; i++) {
        if (teama[i] > teamb[i]) return -1;
        if (teama[i] < teamb[i]) return 1;
    }
    return teama[0] - teamb[0];
}
```

