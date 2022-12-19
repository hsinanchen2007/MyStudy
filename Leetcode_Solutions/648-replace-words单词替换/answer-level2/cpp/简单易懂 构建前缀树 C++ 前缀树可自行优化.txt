```
class Solution {
public:
    struct node
    {
        node *next[26] = {};
        string word = ""; //保存当前最长前缀
        bool is_entry = false; //用来判断是不是前缀
    };
    
    string replaceWords(vector<string>& dict, string sentence) {
        node *dic = new node();
        //构建前缀树
        for(auto word:dict){
            node *cur = dic;
            for(auto c:word){ 
                if(!cur->next[c-'a']) {
                    node *tmp = new node();
                    tmp -> word = cur->word + c;
                    cur->next[c-'a'] = tmp;
                }
                cur = cur->next[c-'a'];
            }
            cur->is_entry = true;
        }
        string ans = "";
        //裁剪字符串并索引
        int pos = 0;
        while(sentence.length()>0 && pos>=0){
            pos = sentence.find(' ');
            string p = sentence.substr(0, pos);
            if(dic->next[p[0]-'a']){
                node *cur = dic;
                for(auto ps:p){
                    if(cur->next[ps-'a']&&cur->is_entry==false) {
                        cur = cur->next[ps-'a'];
                    }
                    else break;
                }
                if(cur->is_entry==true) p = cur->word;
            }
            if(ans != "") ans = ans + ' ' + p;
            else ans += p;
            sentence = sentence.substr(pos+1);
        }

        return ans;
    }
};
```
