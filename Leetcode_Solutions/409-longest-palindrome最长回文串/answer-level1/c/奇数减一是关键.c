### 解题思路
此处撰写解题思路
打卡打卡
### 代码

```c
#define MAX_CH_COUNT 30 

#define BIGGER(a,b) ((a)>(b))?(a):(b)  
/* 要想最长 双数的都留下 单数减一 */
int longestPalindrome(char * s){
    int lowercase[MAX_CH_COUNT]; //小写字母
    int capital[MAX_CH_COUNT]; //大写字母 
    memset(lowercase, 0, sizeof(int)* MAX_CH_COUNT);
    memset(capital, 0, sizeof(int)* MAX_CH_COUNT);
    int len = strlen(s);
    char tempch;
    int index;
    for (int i=0;i< len; i++) {
        tempch = s[i];
        if(tempch>='a' && tempch<='z') {
            index = tempch-'a';
            lowercase[index]+=1;        
        }
        if(tempch>='A' && tempch<='Z') {
            index = tempch-'A';
            capital[index]+=1;
           
        }
    }
    int maxlen =0;
    int maxOdd = 0;
    for (int k=0;k< MAX_CH_COUNT; k++) {
        if(lowercase[k]%2 != 0){
            maxlen+=(lowercase[k]-1);
        }else{
            maxlen+=lowercase[k];
        }
        if(capital[k]%2 != 0){
            maxlen+=(capital[k]-1);
        }else{
            
             maxlen+=capital[k];
        }
        //printf("k=%d letter=%d capital=%d\n",k,lowercase[k],capital[k]);
    }
    if(maxlen !=len){
        maxlen++;
    }
    return maxlen;

}
```