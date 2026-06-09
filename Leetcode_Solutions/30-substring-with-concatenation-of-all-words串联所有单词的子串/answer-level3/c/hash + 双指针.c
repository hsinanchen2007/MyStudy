### 解题思路
这道题做了要吐血了，核心思想就是通过构造hash表，将单词出现的频次记录好，然后使用双指针滑动进行有效字符的遍历；
1.构造hash表，包含字符串内容和出现的频次；
2.由于可能从第0~wordlen之前作为开始位，需要做开始点的遍历；
3.使用双指针，每次遍历一个单词长度，如果hash表中有单词的计数大于0 ，头指针继续往前跳；
4.如果出现了不在word中的单词，那么尾指针一个个的退出，直接到头指针的位置；
5.如果当前位置所有的单词刚好，那么就是答案点，记录下来。
代码写的不太好，不想整了，

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <string.h>

// #define MAX_WORDS 10000
struct words{
    char *word;
    int cnt;
};
// int g_match[MAX_WORDS] = {0};
// int g_ret[MAX_WORDS] = {0};
int numCount(struct words *hash, int hashNum) {
    int i;
    int count = 0;
    int allzeros = 0;
    for (i = 0; i < hashNum; i++) {
        if (hash[i].cnt > 0)
            return 1;
        if (hash[i].cnt < 0)
            allzeros = -1; 
    }
//    printf("numcount is %d\n",allzeros);
    return allzeros;
}
int updateHash(struct words *hash,int hashNum,char *c,int word_len,int flag) {
    int i;
    int findflag = 0;
    for (i = 0; i < hashNum; i++) {
  //      
        if (strncmp(hash[i].word, c, word_len) == 0) {
            if (flag == 1)
                hash[i].cnt--;
            else    
                hash[i].cnt++;
            findflag = 1;
            break;
        }
    }
  //  printf("updateHash strcmp %s %s %d\n",hash[i].word, c,strncmp(hash[i].word, c, word_len));
    if (findflag == 1)
        return 0;
    return -1;
    
}
int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize){
    if (s == NULL || wordsSize == 0  || *words == NULL) {
        *returnSize = 0;
        return NULL;
    }
        
    int i = 0;
    int j = 0;
    int s_len = strlen(s);
    int word_len = strlen(words[0]);
   // printf("word 1 is %s\n",words[0]);
  //  printf("str len is %d word len is %d\n",s_len,word_len);
   struct words *hash = (struct words*)malloc(sizeof(struct words) * wordsSize);
   memset(hash, 0, sizeof(struct words) * wordsSize);

   int hashNum = 0;

   for (i = 0; i < wordsSize; i++) {
       for (j = 0; j < hashNum; j++) {
           if (hash[j].word && (strncmp(words[i], hash[j].word, word_len) == 0)) {
               hash[j].cnt++;
       //        printf("add cnt word %s hashnum %d cnt %d\n",hash[j].word,hashNum,hash[j].cnt);
               break;
           }
       }
        if (j == hashNum) {
            char *tmp = (char *)malloc(sizeof(char) * word_len);
            memcpy(tmp, words[i],word_len);
            hash[hashNum].word = tmp;
            hash[hashNum].cnt = 1;
            hashNum++;
   //         printf("add word %s hashnum %d\n",hash[hashNum - 1].word,hashNum);
        }
   }

   int count = 0;
   int *ret = (int *)malloc(sizeof(int) * s_len);
   int tail = 0;
   int hand = 0;
   for (i = 0; i < word_len; i++) {
       hand = i;
       tail = i;
        for (; hand < s_len || tail < s_len;) {
         //   printf("numCount is %d\n",numCount(hash, hashNum));
            if (hand <= s_len && numCount(hash, hashNum) == 0) {
                
                ret[count++] = tail;
                //   printf("####hand %d tail %d count %d \n",hand, tail,count);

                    updateHash(hash,hashNum,&s[tail],word_len,0);
                    tail += word_len;
            } else if(hand < s_len && numCount(hash, hashNum) > 0) { 
                if (updateHash(hash,hashNum,&s[hand],word_len,1) == -1) {

                    while (tail < s_len && tail <= hand) {
                    //    printf("hand %d tail %d\n",hand,tail);
                        updateHash(hash,hashNum,&s[tail],word_len,0);
                        tail += word_len;
                    }
                } 
                hand += word_len;

            } else {
                    updateHash(hash,hashNum,&s[tail],word_len,0);
                    tail += word_len;
                    
            }
    //        printf("hand %d tail %d  count %d\n",hand,tail,count);
        }
   }

    *returnSize = count;
    return ret;
}
```