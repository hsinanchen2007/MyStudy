今天学习了前缀树

### 代码

```cpp
class Tie{
    public:
       bool is_string;
       Tie* next[26];

       Tie(){
           is_string = false;
           memset(next,0,sizeof(next));
       }
       
       void insert(string word){
           Tie* root = this;
           for(const auto &w:word){
               if(root->next[w-'a'] == nullptr) {
                   root->next[w-'a'] = new Tie();
               }
               root = root->next[w-'a'];
           }
           root->is_string = true;
       }


       bool search(string word){
           Tie* root = this;
           for(auto &w:word){
               if(root->next[w-'a'] == nullptr || root->next[w-'a']->is_string == false)  return false;
               root = root->next[w-'a'];
           }
           return true;
       }
       
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        if(words.size() == 0) return "";
        Tie * root =new Tie();
        for(const auto &word:words){
            root->insert(word);
        }
        string res = "";
        for(const auto &word:words){
            if(root->search(word)){
                if(res.size() < word.size()) res = word;
                else if(word.size()==res.size()&&word<res)res=word;
            }
        }
        return res;

    }
};


```