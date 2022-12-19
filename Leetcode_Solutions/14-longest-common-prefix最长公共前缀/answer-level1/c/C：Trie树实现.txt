### 解题思路
有点大材小用，不太适合这种题目，分治都比这个Trie树快，适合查询！
这里不需要官方那样，查询啊，startswith函数都不需要。
1. 建立Tire前缀树：建树过程中就可以把空串的清空排除掉。
2. 对树内从根节点往下找前缀：
    + 必须唯一子节点，否者跳出
    + 必须最短前缀，什么意思？就是遇到第一个单词结束就终止循环。
比如`'aa','a'`这种应该返回`'a'`，也就是单词结束。下面代码偷懒，直接把第一个字符串`strs[0]`进行填充答案，因为不管怎么，公共前缀都必须是存在的，不担心长度超过任意一个。（虽然做法不对，哈哈）

不释放节点信息。。
![image.png](https://pic.leetcode-cn.com/a5abc7d98594f0c4f1748dde57e99298baca664b03a59e9d9093131f5f74885b-image.png)

### 代码

```c
typedef struct Node {
    bool isEnd;
    struct Node *next[26];
} Trie;

Trie* TrieCreate() {
    return (Trie*)calloc(1, sizeof(Trie));
}

void Trieinsert(Trie *obj, char *word) {
    while (*word) {
        if (!obj->next[(*word)-97]) {
            obj->next[(*word)-97] = TrieCreate();
        }
        obj = obj->next[(*word++)-97];
    }
    obj->isEnd = true;
}

int TrieIsunique(Trie *obj) {
    int sum = 0, unique;
    for (int i = 0; i < 26; i++) {
        if (obj->next[i]) {
            unique = i;
            sum++;
        }
    }
    return sum == 1 ? unique : -1;
}

void TrieFree(Trie *obj) {
    if (!obj) return;
    for (int i = 0; i < 26; i++) {
        TrieFree(obj->next[i]);
    }
    free(obj);
}

char * longestCommonPrefix(char ** strs, int strsSize){
    if (!strsSize) return "";
    int i, j = 0, ch;
    Trie *root = TrieCreate();  // 1.创建根节点插入单词
    for (i = 0; i < strsSize; i++) {
        if (strs[i][0]) Trieinsert(root, strs[i]);
        else return "";  // 空串直接返回
    }
    // 2.查找前缀
    while ((ch = TrieIsunique(root)) != -1 && !root->next[ch]->isEnd) {
        strs[0][j++] = ch + 97;
        root = root->next[ch];
    }
    if (ch != -1) strs[0][j++] = ch + 97;  // 说明是单词结束
    strs[0][j] = '\0';  // 结尾
    return strs[0];
}
```