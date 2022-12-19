### 解题思路
代码开始声明循环变量 i,j,k，速度仅仅击败了50%
代码中声明循环变量 for (int i),速度击败了100%
？？？ 
希望有大神能给解释下原理！！！
PS：代码中有注释
### 代码

```c
typedef struct node{
    bool is_end;
    struct node *next[26];
}trie;
//前缀树的基本知识，26代表有26个字母，为了能够更好的判断一个完整单词中的片段是否也在列表中，我们选用一个布尔变量，true表示这个字母和字母之前的字母组成的单词在单词列表中
char * longestWord(char ** words, int wordsSize){
    trie root,*p,*temp;
    int x,flag;
    for (int i=0;i<26;i++)
        root.next[i] = NULL;
    root.is_end = false;
    for (int i=0;i<wordsSize;i++){
        p = &root;
        for (int j=0;words[i][j];j++){
            x = words[i][j] - 'a';
            if (!p->next[x]){
                temp = (trie*)malloc(sizeof(trie));
                for (int k=0;k<26;k++)
                    temp->next[k] = NULL;
                temp->is_end = false;
                p->next[x] = temp;
            }
            p = p->next[x];
        }
        p->is_end = true;
    }//根据单词列表中的单词绘制前缀树
    char *ans;
    ans = (char*)malloc(sizeof(char)*31);
    ans[0] = '\0';
    for (int i=0;i<wordsSize;i++){
        p = &root;
        flag = 1;
        for (int j=0;words[i][j];j++){
            x = words[i][j] - 'a';
            if (p->next[x]->is_end==false){
                flag = 0;
                break;
            }//由于本题的意思是选出最长的单词，并且单词列表中有这个单词从末尾去一个、取两个。。。的单词，所以判断这个单词中的字母是不是末位，如果不是末尾（false）则表示单词列表中没有这个单词片段，就直接跳过这个单词
            p = p->next[x];
        }
        if (flag==1){
            if (strlen(words[i])>strlen(ans)){
                strcpy(ans,words[i]);
            }//如果单词长直接替换
            else if (strlen(words[i])==strlen(ans)&&strcmp(ans,words[i])>0)
                strcpy(ans,words[i]);//如果相等，用strcmp谁更小要谁
        }//falg跳过单词
    }
    return ans;
}
```