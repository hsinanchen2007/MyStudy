### 解题思路
利用尾指针顺序遍历字符串
每次从新加入的字符向前找到上一个相同的字符
将头指针指向上一个相同字符的下一字符
每次记录当前最长非零子串的长度
最终给出最大值

### 代码

```c
int lengthOfLongestSubstring(char * s){
    int head = 0,tail = 0;
    int step=0,length=0,length_new=0,i = 0;
    step = strlen(s);
    while(step--){
        for(i=tail;i>head;i--){
            if(*(s+i-1)==*(s+tail)){
                head = i;
                break;
            }
        }
        length_new = tail-head+1;
        if(length_new>length) //若新的长度大于记录则替换
            length = length_new; 
        tail++;
    }
    return length;
}
```