用调用子函数的方法模拟哈希表的作用，节省了内存空间，但每次写表和查表都需要调用一次子函数，比较费时。
```
void hashwords_func(char **words,int wordsSize,int *hashwords){
    for(int i=0;i<wordsSize;i++){
        for(int j=i;j<wordsSize;j++){               //将后面的重复的单词的个数全都加到前面相同的那个
            if(strcmp(words[j],words[i])==0){       //单词所在的hash标位置去
                hashwords[i]++;
            }
        }
    }
}

int hashs_func(char **words,char *left,int *hashs,int wordsSize){ 
    for(int i=0;i<wordsSize;i++){
        if(strncmp(left,words[i],strlen(words[0]))==0){      //相同的word都放在了前面的这个单词中
            hashs[i]++;                                     //所以从前往后比就行了，只要匹配上了
            return i;                                       //就返回该索引没匹配上的话返回-1
        }  
    }
    return -1;    
}

int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize){
    if(strlen(s)==0||wordsSize==0||strlen(s)<wordsSize*strlen(words[0])){
        *returnSize=0;
        return NULL;
    }
    int *hashwords=(int *)calloc(wordsSize,sizeof(int));
    int *hashs=(int *)calloc(wordsSize,sizeof(int));
    int *ret=(int *)malloc(sizeof(int)*strlen(s));
    int left, right;
    int count=0,temp;
    *returnSize=0;
    hashwords_func(words,wordsSize,hashwords);
    for(int i=0;i<strlen(words[0]);i++){
        //重置变量    
        memset(hashs,0,sizeof(int)*wordsSize);
        count=0;
        left=i;right=i;
        temp=0;
        while (right<=strlen(s)-strlen(words[0])){        //这里是<=
            temp=hashs_func(words,&s[right],hashs,wordsSize);
            right+=strlen(words[0]);
            count++;             
            if(temp==-1){
                //重置相关变量
                left=right;
                count=0;
                memset(hashs,0,sizeof(int)*wordsSize); 
                continue;                
            }
            else{
                if(hashs[temp]>hashwords[temp]){
                    while(hashs[temp]>hashwords[temp]){
                        int temp0=hashs_func(words,&s[left],hashs,wordsSize);
                        hashs[temp0]-=2;    //这里要减2，因为取temp0的时候hashs[temp0]又被加了1
                        left=left+strlen(words[0]);
                        count--;
                    }
                }
                else{
                    if(count==wordsSize){
                        ret[*returnSize]=left;
                        (*returnSize)++;
                        //left右移寻找下一个
                        int temp0=hashs_func(words,&s[left],hashs,wordsSize);
                        hashs[temp0]-=2;    //这里要减2，因为取temp0的时候hashs[temp0]又被加了1
                        left=left+strlen(words[0]);
                        count--;
                    }
                }
            }
       }
    }
    return ret;
}
```
耗时都在200ms左右。
![image.png](https://pic.leetcode-cn.com/9f613c1c7914a84c86fdc79fcaae900a1952228e98a88303fe32028dc51ba8a8-image.png)