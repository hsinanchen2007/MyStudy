

![temp.PNG](https://pic.leetcode-cn.com/ded35d3c7e5e2ade0d14207f594a03274a6cc67f9ec1d2b9e14ade0e27e1c8f4-temp.PNG)


```
typedef struct {
    char word;
    int wordCnt;
} WordSta;

int CreatWordsArr(char *str, WordSta *wordArr)
{
    int i = 0;
    int indexCnt = 0;

    wordArr[0].word = str[0];
    wordArr[0].wordCnt++;
    i++;
    while (str[i] != '\0') {
        if (str[i] != str[i - 1]) {
            indexCnt++;
            wordArr[indexCnt].wordCnt++;
            wordArr[indexCnt].word = str[i];
        } else {
            wordArr[indexCnt].wordCnt++;
        }
        i++;
    }

    return indexCnt + 1;
}

int CmpStr(WordSta *wordArr, int index, WordSta *wordArrCmp, int indexCmp)
{
    int i;

    if (index != indexCmp) {
        return 0;
    }

    for (i = 0; i < index; i++) {
        if (wordArr[i].word != wordArrCmp[i].word) {
            return 0;
        } else {
            if ((wordArr[i].wordCnt < 3) && (wordArr[i].wordCnt != wordArrCmp[i].wordCnt)) {
                return 0;
            }

            if ((wordArr[i].wordCnt >= 3) && (wordArr[i].wordCnt < wordArrCmp[i].wordCnt)) {
                return 0;
            }
        }
    }

    return 1;
}

int expressiveWords(char * S, char ** words, int wordsSize){

    if ((S == NULL) || (words == NULL) || strlen(S) == 0) {
        return 0;
    }

    int i = 0;
    char wordTemp;
    int index;
    int indexCmp;
    int ret = 0;
    WordSta *wordArr = (WordSta *)malloc(sizeof(WordSta) * 100);
    WordSta *wordArrCmp = (WordSta *)malloc(sizeof(WordSta) * 100);
   
    memset(wordArr, 0, sizeof(WordSta) * 100);
    memset(wordArrCmp, 0, sizeof(WordSta) * 100);

    index = CreatWordsArr(S, wordArr);

    for (i = 0; i <wordsSize; i++) {
        indexCmp = CreatWordsArr(words[i], wordArrCmp);
        if (CmpStr(wordArr, index, wordArrCmp, indexCmp) == 1) {
            ret++;
        }
        memset(wordArrCmp, 0, sizeof(WordSta) * 100);
    }
    return ret;
}
```


