### 解题思路
使用的是创建字典树的策略。
首先使用结构创建字典树。
在这之前需要对字符串长度进行排序，长的在前。
之后将单词插入到字典树中，并对每一个倒序插入的字符串进行判断，当没有遇到NULL时，即判断当前字符串为某一字符串的后缀，无需进行计数，否则需要进行计数。

### 代码

```c
int count;
typedef struct Trie{
    bool hasvisited;
    bool haschildren;
    struct Trie* chil[26];
}Trie;
//创建字典树
Trie* createtrie()
{
    int i;
    Trie* res = (Trie*)malloc(sizeof(Trie));
    res->hasvisited = false;
    res->haschildren = false;
    for(i= 0; i < 26;i++)
        res->chil[i] = NULL;
    return res;
}
//在添加单词的同时，进行计数
bool insertword(Trie* trie, char* word)
{
    int len,flag;
    len = strlen(word);
    char f;
    flag = 0;
    for(int i=len-1;i>=0;i--)
    {
        f = word[i];
        if(trie->chil[f-'a'] == NULL)
        {
            trie->chil[f-'a'] = createtrie();
            trie->haschildren = true;
            flag = 1;
        }
        trie = trie->chil[f-'a'];
    }
    if(flag == 1)
        return true;
    else
        return false;
}

int minimumLengthEncoding(char ** words, int wordsSize){
    if(words == NULL || wordsSize <= 0)
        return 0;
    Trie* trie = createtrie();
    // 对数组进行排序
    char *temp;
    int i;
    bool ans;
    for(int i=0;i<wordsSize;i++)
	{
		int max = strlen(words[i]);
        char* maxstr = words[i];
		int index=i;
 
		//找出最大的数
		for(int j=i+1;j<wordsSize;j++)
		{
			if(strlen(words[j])>max)
			{
				max=strlen(words[j]);
                maxstr = words[j];
				index=j;
			}
			
		}
		temp=words[i];
		words[i]=maxstr;
		words[index]=temp;
	}
    count = 0;
    
    for(i = 0 ; i < wordsSize;i++)
    {
        ans = insertword(trie,words[i]);
        if(ans == true)
            count += strlen(words[i])+1;
        else
            continue;
    }
    return count;
}
```