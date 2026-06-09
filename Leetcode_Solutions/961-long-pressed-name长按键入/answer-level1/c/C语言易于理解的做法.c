设变量name_index为name的下标，typed_index为typed的下标，两者都从零开始。以name为基准遍历。分两种情况。当name当前下标的字符与下一个下标的字符不相等时，判断typed当前下标的字符是否相等，并将typed的下标右移到下一个不同字符的前一个下标；当name当前下标的字符与下一个相同时，比较后typed的下标不进行右移。遍历到name结束。
口齿不清，敬请谅解！
```c
bool isLongPressedName(char * name, char * typed){
    int name_index=0,typed_index=0;
    while(name[name_index]!=0){
        if(name[name_index+1]!=name[name_index]){
            if(typed[typed_index]!=name[name_index]) return 0;
            while(typed[typed_index+1]==name[name_index]) typed_index++;
        }
        else if(typed[typed_index]!=name[name_index]) return 0;
        typed_index++;
        name_index++;
    }
    return 1;
}
```