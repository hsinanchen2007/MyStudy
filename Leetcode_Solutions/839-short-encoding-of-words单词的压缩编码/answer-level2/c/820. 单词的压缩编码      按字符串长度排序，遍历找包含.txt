### 解题思路
给定一个单词列表，我们将这个列表编码成一个索引字符串 S 与一个索引列表 A。

例如，如果这个列表是 ["time", "me", "bell"]，我们就可以将其表示为 S = "time#bell#" 和 indexes = [0, 2, 5]。

对于每一个索引，我们可以通过从字符串 S 中索引的位置开始读取字符串，直到 "#" 结束，来恢复我们之前的单词列表。

那么成功对给定单词列表进行编码的最小字符串长度是多少呢？

 

示例：

输入: words = ["time", "me", "bell"]
输出: 10
说明: S = "time#bell#" ， indexes = [0, 2, 5] 。


1. 此题只要求返回长度， 降低了难度
2. 按照规则， 只有整个字符串 与 某一个长串后缀一样时， 才有效能合并；比如属于长串中间一部分也无效
3. qsort 按长度升序排列， strstr 找是否属于某个长串的后缀

### 代码

```c


int cmp(const void ** _a, const void **_b){
    char **a = (char **)_a;
    char **b = (char **)_b;

    return strlen(*a) - strlen(*b);
}


int minimumLengthEncoding(char ** words, int wordsSize){
    int old_len=0, cut_len=0;
    int i,j,hide_cnt=0,len;
    char *pos;

    /*当数组时， 如下使用  qsort(arr,arr_len,sizeof(int),cmp)*/
    qsort(words, wordsSize, sizeof(char*),cmp);

    for(i=0;i<wordsSize-1;i++){

        len = strlen(words[i]);
        old_len += len;
        for(j=i+1;j<wordsSize;j++){
            /*在words[i]中找words[j], 找到则返回在words[i]中指针，所以可以直接对返回值取strlen*/
            pos = strstr(words[j], words[i]);
            if(pos != NULL && strlen(pos) == strlen(words[i])){
                cut_len += strlen(words[i]);
                hide_cnt += 1;
                break;
            }
        }
    }
    old_len += strlen(words[i]);

    return old_len -cut_len + wordsSize-hide_cnt;
}
```