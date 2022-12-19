# 构建回文串检测

## 解法1

这道题恕我无能，第一想法直接超时，不过过了29个用力，所以还是可以把思路提供一下。
首先分析一下此题，我们能够得到的信息如下：

1. 我们要对字符串的子串求是否是回文串
2. 如果不是回文串，那么给你最大操作步骤，并且允许你重排序，问你能否在规定步数间替换成回文串
   所以，应对操作如下：
3. 对于k = 0的情况，直接判断是否是回文串，这个用双指针往中间搜索即可。
4. 对于k != 0的情况，操作会比较麻烦，这个也是我超时的根因。
   思路如下：

- 统计子串中所有字符并且%2，这样我们就可以得到所有无处安放灵魂的字符（也就是没对象啊，只能自己将就咯。）
- 因为我们能够重排序，所以偶数对一定可以排序到回文串正确位置，所以偶数对直接去掉了
- 因为我们能够操作k次，那我们就利用这个k次给他们找对象啊，如果k的大小大于所有无对象的字符串个数的一半，那不就匹配成功咯？
- 这里有一个特殊情况，如果子串总大小是奇数，那么我们的无对象字符串数量可以减一（你只能把它放中间，那么这个人就自己跟自己过一辈吧，毕竟环境有限）
  综上，就完成了一个会超时的算法。代码如下（公司只让用c语言刷题，哎 hash表都没有一个，烦死了）

```c
#include <stdio.h>
#include <stdbool.h>

#define WORDS_SIZE 26

bool isBackToText(char *s, int low, int high) {

    while (low < high) {
        if (s[low] != s[high]) {
            return false;
        }

        ++low;
        --high;
    }

    return true;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool chargeText(char *s, int low, int high, int times) {
    int wordsCount[WORDS_SIZE] = {0};

    int index;
    int wordsLen = high - low + 1;
    int realDefer = 0;

    if (times * 2 >= wordsLen) {
        return true;
    }

    for (int i = low; i <= high; ++i) {
        index = s[i] - 'a';

        wordsCount[index] = (wordsCount[index] + 1) % 2;
        if (!wordsCount[index]) {
            --realDefer;
        } else {
            ++realDefer;
        }
    }

    if (wordsLen % 2 == 1) {
        --realDefer;
    }

    if (times < realDefer / 2) {
        return false;
    }

    return true;
}

bool *canMakePaliQueries(char *s, int **queries, int queriesSize, int *queriesColSize, int *returnSize) {
    int low, high, cgTimes;
    bool *result = (bool *) malloc(sizeof(bool) * queriesSize);
    for (int i = 0; i < queriesSize; ++i) {
        low = queries[i][0];
        high = queries[i][1];
        cgTimes = queries[i][2];
        if (cgTimes == 0) {
            result[i] = isBackToText(s, low, high);
            continue;
        }

        result[i] = chargeText(s, low, high, cgTimes);
    }

    *returnSize = queriesSize;

    return result;
}

int main() {

    char *s = "abcda";
    int queries[5][3] = {{3, 3, 0},
                         {1, 2, 0},
                         {0, 3, 1},
                         {0, 3, 2},
                         {0, 4, 1}};
    int queriesSize = 5;
    int returnSize;

    int **temp = (int **) malloc(sizeof(int) * queriesSize);
    for (int i = 0; i < queriesSize; ++i) {
        temp[i] = queries[i];
    }
    bool *result = canMakePaliQueries(s, temp, queriesSize, NULL, &returnSize);
    for (int j = 0; j < returnSize; ++j) {
        printf("%d ", result[j]);
    }
    printf("\n");
    return 0;
}

```
![截图2.PNG](https://pic.leetcode-cn.com/3776bd2968638e2dc030a283af659b6da9f0b952e0d18503ad56a4c4b2add1f4-%E6%88%AA%E5%9B%BE2.PNG)

## 解法2

那好，既然我这个超时了，并且本人比较笨，想不好的方法，那么要怎么改进呢？典型方法，空间换时间呗。脑洞后的想法如下：

1. 总体算法参考解法1的第二点
2. 把字符串从0 ~ len - 1的串对应的defer都给保存下来。
   这么做有什么好处呢？可以这么想：
   对于一个要求[i, j, k]的子串，我们知道了其[0, i - 1]中的无对象字符个数以及j中无对象字符个数，那么我们只要让[0, j]中所有无对象字符减去i - 1中所有无对象字符（a - a），然后mod 2，这样我就得到了真正[i, j]中无对象的字符个数。OK，那么套用解法1的思路即可。而且代码更加简化，不用单独判断回文串了。
   这个解法2可以通过用例，不过时间性能不是很好，只超过了50% c语言提交，给大佬Orz。

```c

#include <stdio.h>
#include <stdbool.h>

#define WORDS_SIZE 26
#define MAX_WORDS_LIST 100000

struct words_data {
    int wordsDefer[WORDS_SIZE];
} gWordsData[MAX_WORDS_LIST];

unsigned int wordsSize;


void parseWords(char *s) {
    int memorySize = sizeof(int) * WORDS_SIZE;
    memset(gWordsData[0].wordsDefer, 0, memorySize);
    gWordsData[0].wordsDefer[s[0] - 'a'] = 1;
    int index;
    for (int i = 1; i < wordsSize; ++i) {
        memcpy(gWordsData[i].wordsDefer, gWordsData[i - 1].wordsDefer, memorySize);
        index = s[i] - 'a';
        gWordsData[i].wordsDefer[index] = (gWordsData[i].wordsDefer[index] + 1) % 2;
    }
}

bool parseResult(int *beginList, int *endList, int wordsCount, int size) {
    int realDefer = 0;
    for (int i = 0; i < WORDS_SIZE; ++i) {
        realDefer += (endList[i] - beginList[i] + 2) % 2;
    }

    if (size % 2 == 1) {
        --realDefer;
    }

    if (wordsCount < realDefer / 2) {
        return false;
    }


    return true;
}

bool *canMakePaliQueries(char *s, int **queries, int queriesSize, int *queriesColSize, int *returnSize) {
    wordsSize = strlen(s);
    bool *result = (bool *) malloc(sizeof(bool) * queriesSize);

    parseWords(s);
    int *endDerferList, *beginDeferList;
    int beginIndex, endIndex, size;
    int tempList[WORDS_SIZE] = {0};

    for (int i = 0; i < queriesSize; ++i) {
        beginIndex = queries[i][0];
        endIndex = queries[i][1];
        size = endIndex - beginIndex + 1;
        if (beginIndex == 0) {
            beginDeferList = tempList;
        } else {
            beginDeferList = gWordsData[beginIndex - 1].wordsDefer;
        }
        endDerferList = gWordsData[endIndex].wordsDefer;
        result[i] = parseResult(beginDeferList, endDerferList, queries[i][2], size);
    }

    *returnSize = queriesSize;

    return result;
}

int main() {

    char *s = "abcda";
    int queries[5][3] = {{3, 3, 0},
                         {1, 2, 0},
                         {0, 3, 1},
                         {0, 3, 2},
                         {0, 4, 1}};
    int queriesSize = 5;
    int returnSize;

    int **temp = (int **) malloc(sizeof(int) * queriesSize);
    for (int i = 0; i < queriesSize; ++i) {
        temp[i] = queries[i];
    }
    bool *result = canMakePaliQueries(s, temp, queriesSize, NULL, &returnSize);
    for (int j = 0; j < returnSize; ++j) {
        printf("%d ", result[j]);
    }
    printf("\n");
    return 0;
}

```
![截图.PNG](https://pic.leetcode-cn.com/d70f7f01dbd4f285ff1fcd88401497af54b0b33391c662979fa6fb0e1c8bc59f-%E6%88%AA%E5%9B%BE.PNG)
