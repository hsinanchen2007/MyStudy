滑动窗口，定义两个索引，索引之间的距离为needle的长度，然后遍历对比haystack在索引之间的元素是否与needle相同，不同则跳出，索引右移一位，直至找到完全相同的字符串返回前索引的值，或者后索引遍历到haystack最后一个元素返回-1.
```
int strStr(char * haystack, char * needle){
    int len_h = strlen(haystack);
    int len_n = strlen(needle);
    if(len_n==0) {
        return 0;
    }
    if(len_h==0) {
        return -1;
    }
    int front = 0;
    int behind = front + len_n;
    while(behind <= len_h) {
        for(int i = front,j=0;i<behind;i++,j++) {
            if(haystack[i] != needle[j]) {
                front += 1;
                behind = front + len_n;
                break;
            }
            if(j==len_n-1){
                return front;
            }
        }
    }
    return -1;
}
```
执行用时 :4 ms, 在所有 c 提交中击败了80.25%的用户
内存消耗 :7.1 MB, 在所有 c 提交中击败了86.39%的用户