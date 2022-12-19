### 解题思路
此处撰写解题思路

1.用两指针分别指向可能最长序列的head以及rear，这个可能最长的序列满足条件：除最后一个元素外，其他元素不发生重复。
2.然后遍历这个序列是否发生重复
2.1 发生重复  
    >>>将head移到发生重复的后一个位置
    >>>标记 发生了重复
    >>>跳出本次循环
2.2 不发生重复
    >>>标记 没发生重复
3.记录size
3.1 发生了重复
    >>>size = i
3.2没发生重复
    >>>size = i + 1
4.比较 size 与 maxSize

### 代码

```c
int lengthOfLongestSubstring(char * s){
    int length = strlen(s);
    if (length == 1) {
        return length;
    }
    char *head = NULL, *rear = NULL;
    int size = 0, maxSize=0;
    head = rear = s;
    while ( s + length > rear) {
        int i, is_repeat_char = 1;
        for (i = 0; head + i < rear; i++) {
            // 在前面字符串  出现重复字符
            // 将head移到重复位置的后一个位置，跳出本次循环
            if ( *(head + i) == *rear && head + i != rear) {
                head = head + size;
                is_repeat_char = 1；
                break;
            } else {
                // 没有出现重复字符
                is_repeat_char = 0;
            }
        }
        // 如果没有出现重复的字符
        if (is_repeat_char == 0) {
            size = i+1;
        } else { 
            size = i;
        }
        rear++;
        if (maxSize < size) { maxSize = size;}
    }
    if (maxSize < size) { maxSize = size;}
    return maxSize;
}
```