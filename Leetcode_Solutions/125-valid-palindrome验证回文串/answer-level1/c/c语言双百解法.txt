```
bool isEqual(char s1,char s2){ //判断两个字符是否相等的函数
    if(s1==s2)
        return 1;
    if(s1<='z'&&s1>='a'){
        if(s1-32==s2)
            return 1;
    }
    if(s2<='z'&&s2>='a'){
        if(s2-32==s1)
            return 1;
    }
    return 0;

}
bool isPalindrome(char * s){
    if(strcmp(s,"")==0) //空串
        return 1;
    int strLen=strlen(s);
    int i=0,j=strLen-1;
    while(i<j){
        while(!(s[i]<='9'&&s[i]>='0'||s[i]<='z'&&s[i]>='a'||s[i]<='Z'&&s[i]>='A')){ //选择前面待比较的下一项位置
            i++;
            if(i==j)
                return 1;
        }
        while(!(s[j]<='9'&&s[j]>='0'||s[j]<='z'&&s[j]>='a'||s[j]<='Z'&&s[j]>='A')){//选择后面待比较的下一项位置
            j--;
            if(i==j)
                return 1;
        }
        if(isEqual(s[i],s[j])){ //符合回文规则继续比较
            i++;j--;
        }else{
            return 0;
        }
    }
    
    return 1;
}
```
