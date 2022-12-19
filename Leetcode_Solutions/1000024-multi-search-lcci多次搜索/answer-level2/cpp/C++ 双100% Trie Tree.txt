# 思路：
对smalls建trie树，其中每个树节点的sid记录对应的smalls id。
遍历big的所有后缀，并在trie树中查找后缀。对于查找路径上经过的所有有效sid（sid有效值为大于等于0的数），将后缀的起始id加入到sid对应的ans中。

![WX20200308-001925@2x.png](https://pic.leetcode-cn.com/49e0e3d0f3022f4dc974f1f16628a159c6af8abe147a5580930133ec5e6998d9-WX20200308-001925@2x.png)
# 代码
```
struct TrieNode{
    int sid;
    TrieNode *child[26];
    TrieNode(){
        sid=-1;
        for(int i=0;i<26;++i) child[i]=NULL;
    }
};
class Solution {
private:
    TrieNode *root=new TrieNode();
public:
    void insert(string word,int s){
        int n=word.size();
        TrieNode *cur=root;
        for(int i=0;i<n;++i){
            int cid=word.at(i)-'a';
            if(cur->child[cid]==NULL) cur->child[cid]=new TrieNode();
            cur=cur->child[cid];
        }
        cur->sid=s;
    }
    void search(string word,vector<vector<int>>& ans,int bid){
        int n=word.size();
        TrieNode *cur=root;
        for(int i=0;i<n;++i){
            int cid=word.at(i)-'a';
            if(cur->sid!=-1) ans[cur->sid].push_back(bid);
            if(cur->child[cid]==NULL) return ;
            cur=cur->child[cid];
        }
        if(cur->sid!=-1) ans[cur->sid].push_back(bid);
    }
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        int n=smalls.size(),m=big.size();
        vector<vector<int>> ans(n,vector<int>{});
        for(int i=0;i<n;++i){
            if(smalls[i].size()==0) continue;
            insert(smalls[i],i);
        }
        for(int i=0;i<m;++i){
            string word=big.substr(i,m-i);
            search(word,ans,i);
        }
        return ans;
    }
};
```