### 解题思路
本题难点应该是正则表达式，但是很简单，就一个`.`号，使用`.`的前提是前面字符匹配上。那么此时`.`对应26个字母，直接暴力回溯即可，有一个为真就返回真，否者返回假。

这是不释放每个节点的时间。。
![image.png](https://pic.leetcode-cn.com/e959d5783bd83774e5394ae03de3c3588e4a2b209aec640f9bbbdcbd8b60de54-image.png)
完全释放太慢，但是是正确做法，内存是malloc累加值，所以free节点也没变化多大。
![image.png](https://pic.leetcode-cn.com/75da8924128e8dc9f74f771496f91b5f95f358a93c98140331f193a4f5158ccd-image.png)

### 代码

```c
typedef struct node {
    bool isend;
    struct node *next[26];
} WordDictionary;

/** Initialize your data structure here. */

WordDictionary* wordDictionaryCreate() {
    WordDictionary *obj=(WordDictionary *)calloc(1, sizeof(WordDictionary));
    // memset(obj, 0, sizeof(WordDictionary));
    return obj;
}

/** Adds a word into the data structure. */
void wordDictionaryAddWord(WordDictionary* obj, char * word) {
    while (*word != '\0') {
        if (obj->next[*word - 'a'] == NULL) {
            obj->next[*word - 'a'] = wordDictionaryCreate();
        }
        obj = obj->next[(*word++) - 'a'];
    }
    obj->isend = true;
}
/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
bool wordDictionarySearch(WordDictionary* obj, char * word) {
    /* 回溯算法，遇到.号进行暴力回溯 */
    while (*word) {
        if (*word != '.' && !obj->next[(*word)-97]) return false;  // 不匹配且不是.一定为假
        else if (*word == '.') {  // 是.号进行26字母暴力回溯
            for (int i = 0; i < 26; i++) {
                if (obj->next[i] && wordDictionarySearch(obj->next[i], word+1))
                    return true;  // 只要一个为真即可，立马返回
            }
            return false;  // 否者26个过完，还没找到，一定为假
        }
        obj = obj->next[(*word++)-97];  // 这是正常匹配obj交换的进行
    }
    return obj->isend;  // 最后字符串完了，需要判断字典树在此节点是是否有个bool标记结束
}

void wordDictionaryFree(WordDictionary* obj) {
    // for (int i = 0; i < 26; i++) {
    //     if (obj->next[i])
    //         wordDictionaryFree(obj->next[i]);
    // }
    free(obj);
}

/**
 * Your WordDictionary struct will be instantiated and called as such:
 * WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);
 
 * bool param_2 = wordDictionarySearch(obj, word);
 
 * wordDictionaryFree(obj);
*/
```