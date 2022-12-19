```
struct Trie{
    bool isEnd;
    Trie* next[26];
    Trie(){
        isEnd=false;
        memset(next,0,sizeof(next));
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        auto t=new Trie();
        for(auto d:dict){//构造前缀树
            auto p=t;
            for(auto c:d){
                if(p->next[c-'a']==NULL){
                    p->next[c-'a']=new Trie();
                }
                p=p->next[c-'a'];
            }
            p->isEnd=true;
        }

        string res;
        int start=0;
        while(start<sentence.size()){//start和end分割每个单词
            int end=start;
            while(end<sentence.size()&&sentence[end]!=' ')++end;
            auto p=t;
            int i=start;
            for(;i<end;++i){//匹配前缀树
                if(p->isEnd)break;//匹配到最短的，先返回
                if(p->next[sentence[i]-'a']==NULL)break;//没匹配到
                p=p->next[sentence[i]-'a'];
            }
            if(!res.empty())res+=" ";
            if(p->isEnd)res+=sentence.substr(start,i-start);//匹配到，取前缀
            else res+=sentence.substr(start,end-start);//没匹配到，取整个单词
            start=end+1;
        }
        return move(res);
    }
};
```
