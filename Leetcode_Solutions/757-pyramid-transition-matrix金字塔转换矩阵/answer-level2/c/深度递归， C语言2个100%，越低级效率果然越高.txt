### 解题思路
深度递归， C语言2个100%，越低级效率果然越高

开始理解错了，以为1个字符块只能砌一次，原来是可以重复使用的，导致我代码加了记忆过程反而复杂了。
既然可以重复，那么就轻松了很多。

看注释即可。

### 代码

```c
//#define __DEBUG
#ifdef __DEBUG
#define DEBUG(format, ...) printf (format, ##__VA_ARGS__)
#else
#define DEBUG(format, ...)
#endif

// 最多8个字符，放10个进行可用字符块的信息记录
#define MAX_BOTTOM_MATCH_BLOCK_NUM 10

// 最多200个字符块
#define MAX_ALLOW_NUM 200

// 找到可用的集合
void findMatchBlockInfo(int bottomIndx,const char *bottom,const char **allowed, int allowedSize,
    int *matchSize, int (*set)[MAX_ALLOW_NUM], int matchBlockSize) 
{
    int i;
    for (i = 0; i < allowedSize; i++) {

        if ((bottom[bottomIndx] == allowed[i][0]) && (bottom[bottomIndx + 1] == allowed[i][1])) {
            
            set[bottomIndx][matchSize[bottomIndx]] = i;
            matchSize[bottomIndx]++;
            DEBUG("matchsize:%d, index:%d\n", matchSize[bottomIndx], i);
        }
    }
}


bool pyramidBuildProc(char * bottom, char ** allowed, int allowedSize)
{
    int bottomLen = strlen(bottom);

    // 记录待回复的字符块的个数
    char nextBottom[MAX_BOTTOM_MATCH_BLOCK_NUM];

    // 记录底部对应可用的集合
    int matchSize[MAX_BOTTOM_MATCH_BLOCK_NUM];
    int matchAllowSet[MAX_BOTTOM_MATCH_BLOCK_NUM][MAX_ALLOW_NUM];

    if (bottomLen == 1) {
        return true;
    }

    memset(matchSize, 0, sizeof(matchSize));
    memset(matchAllowSet, 0, sizeof(matchAllowSet));

    int i, j, k;
    for (i = 0; i < (bottomLen - 1); i++) {
        findMatchBlockInfo(i, bottom, allowed, allowedSize, matchSize, matchAllowSet, MAX_BOTTOM_MATCH_BLOCK_NUM);
        DEBUG("matchsize: %d\n", matchSize[i]);
        // 没用可用的三角块，返回结果
        if (matchSize[i] == 0) {
            return false;
        }
    }

    int temp;

    // 遍历组合
    // 第一层遍历所有的bottom组合
    for (i = 0; i < (bottomLen - 1); i++) {
        //第二层遍历各组合对应的可用的字符块
        for (j = 0; j < matchSize[i]; j++) {
            memset(nextBottom, 0 ,sizeof(nextBottom));
            // 记录使用的字符块索引
            temp = matchAllowSet[i][j];
            //对应字符位置填充
            nextBottom[i] = allowed[temp][2];
            DEBUG("pos i char: %c\n", nextBottom[i]);

            // 第三层搜索其他的可用字符块组合新的nextBottom
            for (k = 0; k < (bottomLen - 1); k++) {
                if (k == i) {
                    continue;
                }
                temp = matchAllowSet[k][0];

                //对应字符位置填充,始终取第一个
                nextBottom[k] = allowed[temp][2];
                DEBUG("pos k char: %c\n", nextBottom[k]);
            }
            if(pyramidBuildProc(nextBottom, allowed, allowedSize) == true) {
                return true;
            }
        }
    }

    return false;
}

bool pyramidTransition(char * bottom, char ** allowed, int allowedSize){
    if (allowedSize == 0) {
        return false;
    }

    return pyramidBuildProc(bottom, allowed, allowedSize);
}
```