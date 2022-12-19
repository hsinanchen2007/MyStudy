```
/*
 * @lc app=leetcode.cn id=820 lang=c
 *
 * [820] 找到最终的安全状态
 *
 * https://leetcode-cn.com/problems/short-encoding-of-words/description/
 *
 * algorithms
 * Medium (38.19%)
 * Total Accepted:    17.7K
 * Total Submissions: 39.8K
 * Testcase Example:  '["time", "me", "bell"]'
 *
 * 给定一个单词列表，我们将这个列表编码成一个索引字符串 S 与一个索引列表 A。
 *
 * 例如，如果这个列表是 ["time", "me", "bell"]，我们就可以将其表示为 S = "time#bell#" 和 indexes =
 * [0, 2, 5]。
 *
 * 对于每一个索引，我们可以通过从字符串 S 中索引的位置开始读取字符串，直到 "#" 结束，来恢复我们之前的单词列表。
 *
 * 那么成功对给定单词列表进行编码的最小字符串长度是多少呢？
 *
 *
 *
 * 示例：
 *
 * 输入: words = ["time", "me", "bell"]
 * 输出: 10
 * 说明: S = "time#bell#" ， indexes = [0, 2, 5] 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= words.length <= 2000
 * 1 <= words[i].length <= 7
 * 每个单词都是小写字母 。
 *
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct MyTrie {
    char val;
    struct MyTrie *next[26];
};

struct MyTrie *CreateTrie(char ch)
{
    struct MyTrie *trie = malloc(sizeof(struct MyTrie));
    memset(trie, 0, sizeof(struct MyTrie));
    trie->val = ch;
    return trie;
}

void TrieAddr(struct MyTrie *root, char *s)
{
    int index;
    int len = strlen(s);

    if (len == 0) {
        return;
    }

    char *str = s + len - 1;
    while (str >= s) {
        index = *str - 'a';
        if (root->next[index] == NULL) {
            root->next[index] = CreateTrie(*str);
        }
        root = root->next[index];
        str--;
    }
}

int g_len;
void TrieLengh(struct MyTrie *root, int prev)
{
    if (root == NULL) {
        return;
    }

    int cnt = 0;
    for (int i = 0; i < 26; i++) {
        if (root->next[i] != NULL) {
            TrieLengh(root->next[i], prev + 1);
            cnt++;
        }
    }

    if (cnt == 0) {
        /* printf("end char %c len %d\n", root->val, prev); */
        g_len += prev + 1;
    }
}

int minimumLengthEncoding(char ** words, int wordsSize)
{
    if (wordsSize == 0) {
        return 0;
    }

    struct MyTrie root = {0};
    for (int i = 0; i < wordsSize; i++) {
        TrieAddr(&root, words[i]);
    }

    g_len = 0;
    TrieLengh(&root, 0);
    printf("len %d\n", g_len);
    return g_len;
}



```
