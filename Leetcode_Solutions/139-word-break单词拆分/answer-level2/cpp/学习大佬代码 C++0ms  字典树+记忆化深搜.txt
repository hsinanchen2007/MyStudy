![QQ截图20200110143202.jpg](https://pic.leetcode-cn.com/693b846676ae407ca70c80c1f6cc929033da8edce66b9de01a8e74ab4332c3ce-QQ%E6%88%AA%E5%9B%BE20200110143202.jpg)




```
class Solution {
public:

enum{nums = 26};

struct trieNode{
    bool isEnd;
    trieNode* nxt[nums];

    trieNode(): isEnd(false){
        for(int i=0; i<nums; i++) nxt[i] = NULL;
    }
};

void insert(trieNode* nd, string s){
    if(s.length() == 0) return;

    trieNode* head = nd;
    int len = s.length();

    for(int i=0; i<len; i++){
        int idx = s[i] - 'a';

        if(!head->nxt[idx]) head->nxt[idx] = new trieNode();

        head = head->nxt[idx];
    }

    head->isEnd = true;
}

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        trieNode* root = new trieNode();

        int len = s.length();
        int vis[len+1] = {0};

        for(auto itr = wordDict.begin(); itr!= wordDict.end(); itr++){
            insert(root, *itr);
        }

        return dfs(s, 0, root, vis);
    }

    bool dfs(string s, int idx, trieNode* head, int* vis){
        if(idx == s.length()) return true;

        trieNode* node = head;
        
        vis[idx] = 1;

        for(; idx < s.length(); idx++){
            node = node->nxt[s[idx] - 'a'];

            if(!node) return false;

            if(node->isEnd && vis[idx+1] == 0 && dfs(s, idx+1, head, vis)) return true;
        }

        return false;
    }
};
```

