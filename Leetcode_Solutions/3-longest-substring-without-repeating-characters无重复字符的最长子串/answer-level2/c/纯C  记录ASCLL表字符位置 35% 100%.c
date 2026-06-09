### 解题思路


看这道题之前想到之前做过一道统计重复字符串的题，联想或许能不能这道题也用这种方法，试了半天。
做完之后看了官方题解，有点像他那个滑动窗口 

自己之前一直没通过 是卡在了出现重复字符（当前字符的位置并不是-1，而是先前记录的）时候的操作
出现重复字符的时候，如果该字符的位置小于start位置，那么他对于当前的字符来说，并不是重复的字符，更新其位置即可，并把长度+1

如果是重复的字符，那么需要更新start位置，为该字符上次出现的位置+1
### 代码

```c
int lengthOfLongestSubstring(char * s){
    if(s[0] == '\0')//""是个什么？ NULL ?s == ""
        return 0;

    int count[128] ;//C语言无bool 得用int记录位置
    for(int i = 0;i<128;i++)
        count[i] = -1;

    int max = 1;//至少长度为1
    //ASCLL表长128 a在97（0开始）&& ((pos>=97 && pos<=122) ||(pos>=65 && pos<=90))){//且不被其他字符打断
    //题目未考虑
    for( int i = 0,curStart = 0;i < strlen(s); i++){  
        int pos = s[i] - 'a' +97;
        if(count[pos] == -1 || count[pos] < curStart){
            count[pos] = i;
            max =  max > i - curStart +1 ? max:i - curStart +1 ;
        }
        else{
                curStart = count[pos] + 1;
                count[pos] = i;
        }
    }
    return max;
}
```