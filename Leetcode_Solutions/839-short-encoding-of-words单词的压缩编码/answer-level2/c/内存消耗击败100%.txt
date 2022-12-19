### 解题思路
本题，此处用到了C语言字符串的strstr函数，qsort函数和strcmp函数，如有不熟悉，可上网查询，本处不做赘述。

### 代码

```c
int cmp(char **a,char **b){
    return (strlen(*a)-strlen(*b));
}
int minimumLengthEncoding(char ** words, int wordsSize){
    int i,j;
    int flag;
    int cnt=0;//记录长度
    char *p=NULL;
    qsort(words,wordsSize,sizeof(words[0]),cmp);//通过快排，把长度短的放在前面，长度大的放在后面
    for(i=0;i<wordsSize;i++){
        flag=1;
        for(j=i+1;j<wordsSize;j++){//只能从前往后找  因为前面字符串长度小，后面字符串长度较大
            p=strstr(words[j],words[i]);//比较words[i]是否在其他字符串中出现
            if(p!=NULL){
                if(strcmp(p,words[i])==0){//words[i]是另外一个字符串的后缀（如me是lime的后缀），退出循环，但不作处理
                    flag=0;
                    break;
                }
                else if(strcmp(p,words[j])==0){//words[i]与另外一个字符串完全相同 如“teachar”,“teacher”
                    flag=2;
                    break;
                }
            }
        }
        if(flag==1||flag==2){//字符串相同时 和 words[i]不是另外一个字符串的后缀时 执行下面的操作
            cnt++;
            cnt+=strlen(words[i]);
        }
        
    }
    return cnt;
    
}
```