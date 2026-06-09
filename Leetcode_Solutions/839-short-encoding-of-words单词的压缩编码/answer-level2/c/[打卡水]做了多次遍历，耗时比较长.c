### 解题思路
1.统计第i个字符串的长度，记入queue[i];
2.如果单词a是单词b的尾巴，那么单词a的长度置位0；
3.统计非零长度的单词长度之和，再加上这些单词（queue中不为零）个数（即，#符号的个数）

### 代码

```c
bool sub(char *a,int al,char *b,int bl);
int len(char *a){
    int i;
    for(i=0;a[i];i++);
    return i;
}

int minimumLengthEncoding(char ** words, int wordsSize){
int i,j,num=wordsSize;
int *queue=(int *)malloc(sizeof(int)*wordsSize);
for(i=0;i<wordsSize;i++){
    queue[i]=len(words[i]);
}
for(i=0;i<wordsSize;i++){
    for(j=0;j<wordsSize;j++){
        // printf("%d,%d\n",queue[i],queue[j]);
        if((queue[i])&&(j!=i)&&(queue[j]>=queue[i])&&sub(words[i],queue[i],words[j],queue[j])){
            queue[i]=0;
            num--;
            break;
        }
    }
}
for(i=0,j=0;i<wordsSize;i++){
    j+=queue[i];
}
return j+num;
}

// a在不在b的尾部
bool sub(char *a,int al,char *b,int bl){
    int i,j;
    if(al>bl) return false;
    for(i=al-1,j=bl-1;i>=0&&j>=0;i--,j--){
        if(a[i]!=b[j]) return false;
    }
    return true;
}

```