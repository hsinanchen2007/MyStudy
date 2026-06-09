把词根全部丢进字典树，然后扫描句子的每个单词，在字典树中找词根，如果能找到就替换
代码如下：
```c++ []
class Solution {
public:
    int trie[50000][27];
    int is_end[50000];
    int cnt = 0;
    void insert(string s){
        int cur = 0;
        for(int i = 0; i < s.length(); i++){
            if(!trie[cur][s[i]-'a'])
                trie[cur][s[i]-'a'] = ++cnt;
            cur = trie[cur][s[i]-'a'];
        }
        is_end[cur] = true;
    }
    string search(string s){
        int cur = 0;
        string ans = "";
        if(!trie[cur][s[0]-'a']) return s;//第一个字母不匹配，直接返回
        for(int i = 0; i < s.length(); i++){
            if(!trie[cur][s[i]-'a']) return s;//不匹配马上返回
            cur = trie[cur][s[i]-'a'];
            ans += s[i];
            if(is_end[cur]) return ans;//如果出现多个词根返回最小的那个，这个判断可以保证当前词根最小
        }
        return s;//找不到词根
    }
    string replaceWords(vector<string>& dict, string sentence) {
        for(int i = 0; i < dict.size(); i++)
            insert(dict[i]);
        string ans = "";
        int i = 0;
        while(i < sentence.length()){
            string word = "";
            while(i < sentence.length() && sentence[i] == ' ') i++;
            while(i < sentence.length() && sentence[i] != ' '){
                word += sentence[i];
                i++;
            }
            ans += search(word);
            ans += " ";
        }
        ans = ans.substr(0,ans.length()-1);
        return ans;
    }
};
```

