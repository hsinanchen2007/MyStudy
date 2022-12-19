采用C语言，利用将原字符串倒叙遍历，将每个单词暂存，再存进结果字符串，去掉多余空格，
算法很简单，也易懂
轻松双百
```
char * reverseWords(char * s){
    // 简单，从后向前遍历字符串，将遇到的每个单词记录，倒转后存进结果字符串
    char* result = (char*)malloc(sizeof(char)*(strlen(s)+1));
    char word[1000]={};
    int i,j,count=0,p;
    if(strlen(s)==0){//字符串为空
        return s;
    }
    for(i=strlen(s)-1,j=0;i>=0;i--){  //倒转操作
        if(s[i]!=' '){
            word[count] = s[i];
            count++;
        }
        if(i>0 && (s[i]!=' ') && (s[i-1]==' ')){
            for(p=count-1;p>=0;p--){
                result[j++] = word[p];
            }
            result[j++] = ' ';
            count = 0;
        }
    }
    if(j==0 && count == 0){   //全为空格时
        result[0] = '\0';
        return result;
    }
    if(count == 0){   //补齐最后一个单词，如果存在的话
        result[j-1] = '\0';
    }
    else{
        for(p=count-1;p>=0;p--){
            result[j++] = word[p];
            } 
        result[j] = '\0';
        }
    return result;
}
```



