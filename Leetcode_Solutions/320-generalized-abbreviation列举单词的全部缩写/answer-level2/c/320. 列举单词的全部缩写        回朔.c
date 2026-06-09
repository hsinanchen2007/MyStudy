### 解题思路
请你写出一个能够举单词全部缩写的函数。

注意：输出的顺序并不重要。

示例：

输入: "word"
输出:
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]




1. 从第一个字符往后遍历，   每个字符可以缩写也可以不缩写
2. 缩写时讲计数k++， 只到遇到下一个不缩写时就将K apend 临时字符串里
3. 不缩写时直接将当前字符append 到临时字符串里

性能不太好。。。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define LEN  16
int j;
char **res;

void helper(char * temp_cur, char * word,int i, int k, int n){
    //每个递归里入参的cur内容都不一样，所以这里用一个栈局部变量
    char cur[LEN] = {0};
    char kstr[4] = {0};
  
    strcpy(cur,temp_cur);
    if(i == n){
        int curlen;
        if(k > 0){
            sprintf(kstr,"%d",k);   //当k>10 时，k+48 转换不好使
            strcat(cur,kstr);
        }

        curlen = strlen(cur);
        res[j] = (char *)malloc(curlen + 1);
        memset(res[j],0,curlen + 1);
        strncpy(res[j++],cur,curlen);
        return;
    }

    //1.缩写
    helper(cur,word,i+1,k+1,n);
    
    //2.不缩写
    if(k > 0){
            sprintf(kstr,"%d",k);
            strcat(cur,kstr);
    }
    cur[strlen(cur)] = word[i];
    helper(cur,word,i+1,0,n);
}


char ** generateAbbreviations(char * word, int* returnSize){
    char cur[LEN] = {0};
    int i = 0;

    if(word == NULL){
        *returnSize = 0;
        return NULL;
    }

    res = (char *)malloc(20000*sizeof(char *));

    j=0;
    helper(cur,word,0,0,strlen(word));
    
    *returnSize = j;
    return res;
}
```