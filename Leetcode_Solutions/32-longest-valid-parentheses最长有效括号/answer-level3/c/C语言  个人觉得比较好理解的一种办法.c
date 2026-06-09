    也可以说是动态规划的一种把。
    首先从头开始遍历字符串。然后每检索到一个字符，到这个字符为止的最长有效括号长度其实就是max{不包含该字符的之前的字符串中最长有效括号长度，以该字符结尾的有效有效括号长度}，这样就很容易写了，虽然效率不算高，但是比较容易理解。
```
int get(char *s,int t){
    char line[100000];
    int head=-1;
     int i=0;
     int max=0;
     int num=0;
     for(i=t;i>=0;i--){
         if(s[i]==')'){
             head++;num++;
             line[head]=s[i];
         }
         else{
             if(head>=0){
                 head--;num++;
             }
             else{
                  return max;
             }
         }
         if(head==-1){
            if(max<num)
                 max=num;
         }
     }
     return max;
}

int longestValidParentheses(char * s){
     
     int max=0;
     int i;
     for(i=0;i<strlen(s);i++){
         int t=get(s,i);
         if(max<t){
             max=t;
         }
     }
     return max;
}
```
