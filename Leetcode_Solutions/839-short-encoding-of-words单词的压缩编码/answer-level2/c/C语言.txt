### 解题思路
此处撰写解题思路

### 代码

```c
typedef struct Trie
{
    char c;
    struct Trie *child[26];
    int p;
} Trie;

int findleaves(Trie *root, int lev)
{
    if (root->p == 0)
        return lev;
    int i, sum = 0;
    for (i = 0; i < root->p; i++)
        sum += findleaves(root->child[i], lev + 1);
    return sum;
}

int minimumLengthEncoding(char ** words, int wordsSize)
{
    Trie *trie = (Trie*)malloc(sizeof(Trie));
    trie->p = 0;
    Trie *node;
    int i, j, k, flag;
    for (i = 0; i < wordsSize; i++)
    {
        node = trie;
        for (j = strlen(words[i]) - 1; j >= 0; j--)
        {
            flag = 0;
            for (k = 0; k < node->p; k++)
            {
                if (node->child[k]->c == words[i][j])
                {
                    flag = 1;
                    node = node->child[k];
                    break;
                }
            }
            if (!flag)
            {
                node->child[node->p++] = (Trie*)malloc(sizeof(Trie));
                node = node->child[node->p - 1];
                node->p = 0;
                node->c = words[i][j];
            }
        }
    }
    return findleaves(trie, 1);
}
```