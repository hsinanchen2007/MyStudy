别人的题解思路：图的概念。定义信任别人是出度，被人信任是入度。 就是在图上找入度为N-1的人。

题外话： 心思再深入一点，如果假设 A信任B， B信任C，那么潜台词是A也信任C的话，这题就不是简单难度了。

```c
int findJudge(int N, int** trust, int trustSize, int* trustColSize){
    int *ret_val = (int *)calloc(N+1, sizeof(int));
    for (int i = 0; i < N+1; ++i)
        ret_val[i] = 0; 

    for (int i = 0; i < trustSize; ++i)
        ++ret_val[trust[i][1]];  //记录被相信的次数

    for (int i = 0; i < trustSize; ++i)
        ret_val[trust[i][0]] = 0;//如果他相信别人，就对被相信的次数清零

    int num = 0;
    int top = -1;
    for (int i = 1; i <= N; ++i) {
        if (ret_val[i] == N-1) {  //查找相信次数为N-1的人
            ++num;
            top = i;//记录下标
        }
    }
    free(ret_val);    
    return (num > 1 ? -1 : top);//如果有大于1个法官，就为-1，否则就为该下标
}
```
