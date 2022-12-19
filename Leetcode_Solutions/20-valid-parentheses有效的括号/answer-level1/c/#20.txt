
看了题解才做出来的，不过刚开始没有考虑到输入为')'，']'，'}'的情况，没有在入栈里加入top==-1的条件。
```c
bool isValid(char * s){
char* stack=(char*)calloc(strlen(s)+1,sizeof(char));
int top=-1;

for(int i=0;s[i]!='\0';i++){
    if(s[i]=='('||s[i]=='['||s[i]=='{'||top==-1){
        stack[++top]=s[i];
    }
    else if(s[i]==stack[top]+1||s[i]==stack[top]+2){
        --top;
    }
    else {return false;}
}
return top==-1?true:false;
}
```