### 解题思路
此处撰写解题思路

### 代码

```cpp


class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> chars_count=count(chars);
        int res=0;
        for(string& word:words){
            vector<int> word_count=count(word);
            if(contains(chars_count,word_count)){
                res+=word.length();
            }
        }
        return res;
    } 
       bool contains(vector<int>& chars_count,vector<int>& word_count){
           for(int i=0;i<26;i++){
               if(chars_count[i]<word_count[i]){
                   return false;
               }
           }
           return true;
       }

       vector<int> count(string& word){
           vector<int> counter(26,0);
           for(char c:word){
               counter[c-'a']++;
           }
           return counter;
       }


 
};
```