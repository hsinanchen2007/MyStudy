### 解题思路
第一种方法，分别对word和chars字母排序，然后对word轮询，并设置查找位置pos，查找是否每个字母都在chars中
第二种方法，使用unordered_map统计word和chars中字母出现的数量，如果word中对应字母的数量小于等于chars，则表示满足条件
自己需要注意的点：1.unorder_map的使用 2.for循环使用优化 3.string.find()函数的谨慎使用
### 代码

```cpp
//第一种
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int sum = 0;
        int pos;
        int j;
        sort(chars.begin(),chars.end());
        for(int i=0;i<words.size();i++){
            pos=0;
            sort(words[i].begin(),words[i].end());
            for(j=0;j<words[i].length()&&pos<chars.length();j++){
                pos = isFind(words[i][j],chars,pos);
                if(pos==-1){
                    break;
                }
                pos++;
            }
            if(pos!=-1&&j==words[i].length()){
                sum+=words[i].length();
            }
        }
        return sum;
    }
    int isFind(char a,string b,int pos){
        for(int k=pos;k<b.length();k++){
            if(b[k] == a){
                return k;
            }
        }
        return -1;
    }
};
//第二种
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int sum = 0;
        unordered_map<char,int> char_cnt;
        for(char i : chars){
            char_cnt[i]++;
        }
        for(string word:words){
            unordered_map<char,int> word_cnt;
            for(char j:word){
                word_cnt[j]++;
            }
            bool ans=true;
            for(char k:word){
                if(word_cnt[k]>char_cnt[k]){
                    ans=false;
                    break;
                }
            }
            if(ans){
                sum+=word.length();
            }  
        }
        return sum ;
    }
    
};
```