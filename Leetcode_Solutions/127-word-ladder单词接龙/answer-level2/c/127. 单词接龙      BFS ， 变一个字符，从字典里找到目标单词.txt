### 解题思路
给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：

每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回 0。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出: 5

解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
     返回它的长度 5。



1.宽度搜索，二叉树层次遍历类似
2.每个元素入过队列后，后面就不用再将其入队列了。　加此标记也保证不会死循环了

### 代码

```c

bool onediff(char * beginWord, char * endWord){
    int len = strlen(beginWord);
    int i, count=0;

    for (i = 0; i < len; i++) {
        if (beginWord[i] != endWord[i])
            count++;
    }
    if(count == 1)
        return true;
    else
        return false;
}


int ladderLength(char * beginWord, char * endWord, char ** wordList, int wordListSize){
    int i, r = 0, w = 0, size, level = 0;
    char *temp;
    char *queue[10000] = {0};
    bool marked[10000] = {0};

    for (i = 0; i < wordListSize; i++) {
        if (!strcmp(wordList[i], endWord))
            break;
    }
    if (i == wordListSize)
        return 0;

    queue[w++] = beginWord;
    while (r < w) {
        size = w - r;
        level++;
        while (size--) {
            temp = queue[r++];
            if (!strcmp(temp, endWord))
                return level;
            for (i = 0; i < wordListSize; i++) {
                //为啥每个元素只检查一遍就行呢？
                //每个元素一旦进来，会把其所有可能都加入队列，要找到就找到了;找不到就肯定找不到，其他人不用再进来
                if (marked[i])  continue;
                //只有差１才能加入队列,相等不用加入
                if (onediff(temp, wordList[i])){
                    marked[i] = true;
                    queue[w++] = wordList[i]; 
                }
            }
        }
    }
    
    return 0;
}
```