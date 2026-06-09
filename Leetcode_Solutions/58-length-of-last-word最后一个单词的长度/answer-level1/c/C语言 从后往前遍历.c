C语言 从后往前遍历
```
int lengthOfLastWord(char * s){
    int lenth=0;
    int count=0;
    //求字符串长度
    while (*(s+lenth)!='\0') {
        lenth++;
    }
    if (lenth==0) {
        return 0;
    }
    
    int i;
    int flag=0;
    //从后往前遍历第一个字母
    for (i=lenth-1;i>=0;i--) {
        if (*(s+i)==' ' && flag==0) {
            
        } else if (('a'<=*(s+i)  &&  *(s+i)<='z') || ('A'<=*(s+i) && *(s+i)<='Z')) {
            count++;
            flag=1;
        } else if (*(s+i)==' ' && flag==1) {
            return count;
        }
    }
    return count;
}
```
