### 解题思路
字典树方便查找字符串，记忆化是指记忆无法分解的字串
### 代码

```cpp
struct tire{
    bool is_word;
    map<char,tire*>children;
    tire(){is_word=false;for(char a='a';a<='z';a++)children[a]=NULL;}
};
class Solution {
public:
    tire *tire_tree=new tire();
    int is_ok[1000];
    void insert(string word){
        tire *now=tire_tree;
        for(auto c:word){
            if(now->children[c]){
                now=now->children[c];
            }
            else{
                tire *new_one=new tire();
                now->children[c]=new_one;
                now=new_one;
            }
        }
        now->is_word=true;
    }
    bool decompse(string s,int start,int end){
        if(start>end)return true;
        tire *now=tire_tree;
        for(int i=start;i<=end&&now->children[s[i]];i++){
            if(now->children[s[i]]->is_word&&!is_ok[i+1]){
                if(decompse(s,i+1,end))return true;
                is_ok[i+1]=1;
            }
            now=now->children[s[i]];
        }
        is_ok[start]=1;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(is_ok,0,sizeof(is_ok));
        int n=wordDict.size();
        if(!n)return false;
        for(auto word:wordDict)insert(word);
        return decompse(s,0,s.size()-1);
    }
};
```