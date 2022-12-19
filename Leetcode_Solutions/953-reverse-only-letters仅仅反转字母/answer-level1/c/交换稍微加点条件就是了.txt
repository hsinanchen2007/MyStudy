### 解题思路
子函数是真的好用

### 代码

```c
bool is_string(char a){
    if(a>='a'&&a<='z'||a>='A'&&a<='Z'){
        return true;
   }
   return false;
}
char * reverseOnlyLetters(char * S){
    int len=0;
    char temp;
    int front,rear;
    if(S==NULL){
        return NULL;
    }
    len=strlen(S);
    if(len==1){
        return S;
    }
    front=0;
    rear=len-1;
    while(front<rear){
        while(front<rear&&!is_string(S[front])){
            front++;
        }
        while(front<rear&&!is_string(S[rear])){
            rear--;
        }
        if(front<rear){
            temp=S[front];
            S[front]=S[rear];
            S[rear]=temp;
            front++;
            rear--;
        }
    }
    return S;
}
```