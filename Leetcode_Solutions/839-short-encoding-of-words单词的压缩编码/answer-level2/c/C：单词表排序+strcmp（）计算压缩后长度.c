### 解题思路
提供一个简单思路。
当某个单词A存在于单词B的后缀时，压缩后可以将A的长度省略。而且B词长度一定大于等于A词。所以先将单词表排序，然后从短词开始，逐个与其他长词的后缀对比，若相同则删去其长度。
1. 单词排序：由于1 <= words[i].length <= 7，所以只需6次遍历，每次寻找长度为i（=1~6）的单词排在count位置，并将count自增；
2. 将排序后的单词长度存储在wordsLen数组中；
3. 设置压缩长度minLen，其初值设置为未压缩时单词的长度，即所以单词长度和+单词数（#）；
4. 从左到右每次选中一个单词A，从A的下一个词B开始，用strcmp函数对比A与B+B.len-A.len，若相同则从minLen中减去A.len+1，并开始选中下一个词，直到结束。剩余的minLen即为压缩长度。

### 代码

```c
#include<string.h>

void sortWords(char** words, int wordsSize) {
    int count = 0;
    char* temp;
    for (int i = 1; i < 7; ++i) {
        for (int j = 0; j < wordsSize; ++j) {
            if (strlen(*(words + j)) == i) {
                temp = *(words + count);
                *(words + count) = *(words + j);
                *(words + j) = temp;
                count++;
                if (count >= wordsSize) return;
            }
        }
    }
}

int minimumLengthEncoding(char ** words, int wordsSize){
    int* wordsLen = (int*)malloc(sizeof(int) * wordsSize);
    int minLen = 0;

    sortWords(words, wordsSize);
    for (int i = 0; i < wordsSize; ++i) {
        *(wordsLen + i) = strlen(*(words + i));
        minLen += *(wordsLen + i);
    }
    minLen += wordsSize;
    for (int i = 0; i < wordsSize - 1; ++i) {
        for (int j = i + 1; j < wordsSize; ++j) {
            if (strcmp(words[i], words[j] + (*(wordsLen + j) - *(wordsLen + i))) == 0) {
                minLen -= *(wordsLen + i) + 1;
                break;
            }
        }
    }
    return minLen;
}
```