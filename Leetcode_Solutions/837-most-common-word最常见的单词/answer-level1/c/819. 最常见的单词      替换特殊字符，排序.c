### 解题思路
给定一个段落 (paragraph) 和一个禁用单词列表 (banned)。返回出现次数最多，同时不在禁用列表中的单词。题目保证至少有一个词不在禁用列表中，而且答案唯一。

禁用列表中的单词用小写字母表示，不含标点符号。段落中的单词不区分大小写。答案都是小写字母。

 

示例：

输入: 
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
输出: "ball"
解释: 
"hit" 出现了3次，但它是一个禁用的单词。
"ball" 出现了2次 (同时没有其他单词出现2次)，所以它是段落里出现次数最多的，且不在禁用列表中的单词。 
注意，所有这些单词在段落里不区分大小写，标点符号需要忽略（即使是紧挨着单词也忽略， 比如 "ball,"）， 
"hit"不是最终的答案，虽然它出现次数更多，但它在禁用单词列表中。



### 代码

```c
void uptolow(char * str){
    int len = strlen(str);
    int i;
    //单引号不好直接表示，　就直接判断ASCII值　39了
    for(i=0;i<len;i++){
        if(str[i] == '!' || str[i]=='?'|| str[i]==','
            || str[i]==';' || str[i]=='.' || str[i]==39)
            str[i] = ' ';
        else if(str[i]>=65 && str[i] <=90)
            str[i] += 32;
    }
}
int cmp(void * a, void * b){
    return strcmp((char *)a,(char*)b);
}

bool exist(char* str, char**banned,int bannedSize){
    int i=0;
    for(i=0;i<bannedSize;i++){
        if(!strcmp(str,banned[i]))
            return true;
    }
    return false;
}

char * mostCommonWord(char * paragraph, char ** banned, int bannedSize){
    int i,len,j=0,k,max=0;
    char str_arr[1000][16] = {0};
    char * para = paragraph;
    char * temp;
    char *res = malloc(32);

    memset(res,0,32);
    len = strlen(paragraph);
    uptolow(paragraph);
    for(i=0;i<bannedSize;i++)
        uptolow(banned[i]);

    i=0;
    while(i<len){
        k=0;
        while(paragraph[i]>=97 && paragraph[i]<=122){
            str_arr[j][k++] = paragraph[i];
            i++;
        }
        str_arr[j++][k++] = '\0';
        while(paragraph[i]==' ')
            i++;
    }
    k=1;
    qsort(str_arr,j,16,cmp);
    for(i=0;i<j;i++){
        if(!strcmp(str_arr[i],str_arr[i+1]))
            k++;
        else{
            if(k > max && !exist(str_arr[i],banned,bannedSize)){
                max = k;
                strcpy(res,str_arr[i]);
            }
            k=1;
        }
    }
    return res;
}
```