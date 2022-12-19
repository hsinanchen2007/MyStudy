# 核心思想
**构建字典树；然后找到word在字典树中的位置；以word的最后一个字符所在节点为根，遍历这棵子树，找到答案。**
例1中，searchWord为"mouse"，那么word就为"m", "mo", "mou", "mous", "mouse"。
如此时word为"mou"，那么就需要找到"mou"中的'u'在字典树中的位置，以该位置为根，然后去遍历子树，从而得到word == "mou"时的答案。

# 字典树的基本操作
### 数据结构
```
struct trieNode {
    bool isStr; // 为true表示这是一个product
    trieNode *next[26]; // 题目规定只有小写字母
    int count; // 因为products里可能有同名的product，所以加此字段用于表示该product的个数
    trieNode() {
        isStr = false;
        memset(next, 0, sizeof(next));
        count = 0;
    }
};
```
### 插入
```
void insert(trieNode& root, string word) {
    trieNode* current = &root;
    for (char c : word) {
        if (current->next[c - 'a'] == NULL) {
            trieNode* newNode = new trieNode();
            current->next[c - 'a'] = newNode;
        }
        current = current->next[c - 'a'];
    }
    current->isStr = true;
    current->count++;
}
```
### 查找子串是否存在，并且返回word最后一个字符所在的位置
```
bool findSubString(trieNode root, string word, trieNode& rootToPrint) {
    trieNode* current = &root;
    for (auto c : word) {
        if (current != NULL) {
            current = current->next[c - 'a'];
        }
    }
    if (current != NULL) {
        rootToPrint = *current;
        return true;
    } else {
        return false;
    }
}
```
### 以word最后一个字符所在字典树的位置为根节点，遍历子树，获取最多3个满足条件的字符串
```
// cur为word最后一个字符所在字典树的位置
// currentString为搜索到cur节点时，此刻的字符串样子
// ans用来存储结果
// num用来表示当前找到的满足条件的product的个数
void dfs(trieNode *cur, string &currentString, int &num, vector<string>& ans) {
    if (cur == NULL) {
        return;
    }
    // 由于同名的product可能有多个，因此这里特殊处理一下
    if (cur->isStr && num < 3) {
        // 如果这是一个product，并且找到的答案ans还不足3个，那么尝试把product放入ans中
        for (int i = 0; i < cur->count; i++) {
            // 当前找到的product个数还不满3个
            if (num < 3) {
                ans.push_back(currentString);
                num++;
            } else {
                break;
            }
        }
    }
    // 如果当前找到的同名product已经>=3个，不需要继续搜索
    if (num >= 3) {
        return;
    }
    // 继续搜索
    for (int i = 0; i < 26; i++) {
        if (cur->next != NULL) {
            string tmp (1, char (i + 'a'));
            currentString.append(tmp);
            dfs(cur->next[i], currentString, num, ans);
            currentString.pop_back();
        }
    }
}
```
### 主函数
```
vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    trieNode root; // 创建字典树根节点
    for (auto product : products) {
        insert(root, product); // 构建字典树
    }
    vector<vector<string>> result;
    for (int i = 1; i <= searchWord.size(); i++) {
        string word = searchWord.substr(0, i); // 以"mouse"为例，那么word就为"m", "mo", "mou", ...
        vector<string> oneResult;
        trieNode rootToPrint; // 当前word最后一个字符所在字典树的位置
        if (findSubString(root, word, rootToPrint)) {
            vector<string> ans;
            int num = 0;
            dfs(&rootToPrint, word, num, ans);
            for (auto s : ans) {
                oneResult.push_back(s);
            }
        }
        result.push_back(oneResult);
    }
    return result;
}
```