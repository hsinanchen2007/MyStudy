利用双指针，直接在原字符串上进行操作。
```c
char * removeDuplicates(char * S){
    int i=1,stackIndex=0;
    while(S[i]){
        if(S[i++]==S[stackIndex]){
            if(stackIndex) stackIndex--;
            else S[stackIndex]=0;//这样处理以后向栈中加入元素时判断语句会比较方便。
        }
        else{
            if(S[stackIndex]) stackIndex++;
            S[stackIndex]=S[i-1];//i-1是因为判断语句里面的i++。
        }
    }
    S[stackIndex+1]=0;
    return S;
}
```