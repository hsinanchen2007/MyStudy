### 解题思路
典型的DFS+记忆化的问题。

1.遍历词典，找到句子匹配位置

2.记录匹配位置前方剩余字符

3.生成子问题，并得到子问题的子句子剩余字符

4.将两部分字符求和，得到当前划分方式的最小剩余字符

5.遍历所有可能方式，返回最小值。

使用memo记录已经求得的子问题结果，用于加速。

![image.png](https://pic.leetcode-cn.com/7f5d16897222d643b10c34fc714b97c0c900b860cfcb095a15635e893ca268c3-image.png)


### 代码

```c
#define MMIN(a, b)        ((a) < (b)? (a) : (b))

int *memo;

char *sen;
int ssize;
char **dict;
int dsize;

int helper(int sid)
{
    if(memo[sid] != 0) {
        return memo[sid] - 1;
    }

    //printf("%s\n", &sen[sid]);

    int min = strlen(&sen[sid]);

    for(int i = 0; i < dsize; i++) {
        char *tmps = strstr(&sen[sid], dict[i]);

        if(tmps == NULL) {
            continue;
        }
        //匹配位置
        int tid = (tmps - sen) / sizeof(char);
        //开始产生的剩余字符
        int rem = tid - sid;
        //下次搜索开始的位置
        int nid = tid + strlen(dict[i]);

        if(nid >= ssize) {
            min = MMIN(min, rem);
            continue;
        }
        //printf("dict[%d] %s, nid = %d\n", i, dict[i], nid);

        //补充后面的剩余字符
        rem += helper(nid);
        min = MMIN(min, rem);
    }

    memo[sid] = min + 1;

    return min;
}

//【算法思路】DFS+memo。每次查找，都遍历字典中可能词，然后将单词向前推进。
int respace(char** dictionary, int dictionarySize, char* sentence){
    ssize = strlen(sentence);
    if(ssize == 0) {
        return 0;
    }

    if(dictionarySize == 0) {
        return ssize;
    }

    dict = dictionary;
    dsize = dictionarySize;
    sen = sentence;

    memo = (int *)calloc(ssize, sizeof(int));

    int ret = helper(0);

    return ret;
}
```