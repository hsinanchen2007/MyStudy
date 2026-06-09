### 解题思路
prenum记录前一个单词长度，num记录遇到空格后的下一个单词长度
' '的情况，prenum==0,num==0;return num;
'*** a'的情况,num == 1,prenum !=0;return num;
'abc'的情况,num == 3,prenum == 0;return num;
'abc '的情况，num == 0,prenum == 3;return prenum;
'abc   '的情况,prenum == 3;num==0;return prenum;
'dfa dsa dfds'的情况,num==4,prenum==3;return num;

### 代码

```c
int lengthOfLastWord(char * s){
    if( strlen(s) == 0 ) return 0;
    int i, num=0,prenum=0;
    for( i=0;s[i] != '\0';i++ ){
        if( (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') ){
            num +=1;
        }
        if( s[i] == ' ' && num != 0 ){
            prenum = num;
            num = 0;
        }
     }
    if( prenum == 0 || num !=0 ){
        return num;
    }else{
        return prenum;
    }
}
```