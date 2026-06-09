递归查找长度的地方写了很久

```
struct node{
    node *next[26];
    int cnt;
    node(){
        for(int i=0;i<26;i++) next[i] = nullptr;
        cnt = 0;
    }
};
class Solution {
public:

    void insert(node * trie,string tmp){
        node * now = trie;
        for(int i=tmp.length()-1;i>=0;i--){
           // cout<<tmp<<" "<<i<<endl;
            int k = tmp[i] - 'a';
            //cout<<k<<endl;
            if(now->next[k] == nullptr){
                now->next[k] = new node();
            } 
            now = now->next[k];
        }
        now->cnt = 1; // 单词结尾。
    }
    /*
        trie 树。
    */
    int ans = 0;
    int countDepth(node * trie,int dep){
        node * now = trie;
        int find = 0;
        int tmp = 0;
        for(int i=0;i<26;i++){
            if(now->next[i]){
                tmp += countDepth(now->next[i],dep+1);
                find = 1;
            }   
        }
        if(find) 
            return tmp;
        return dep+1;
    }
    int minimumLengthEncoding(vector<string>& words) {
        node * trie = new node();
        for(int i=0;i<words.size();i++){
            string tmp = words[i];
            insert(trie,tmp);
        }
        for(int i=0;i<26;i++){
            if(trie->next[i] != NULL){
                ans += countDepth(trie->next[i],1);
                //cout<<ans<<endl;
            }
        }
        return ans;
    }
};
```
