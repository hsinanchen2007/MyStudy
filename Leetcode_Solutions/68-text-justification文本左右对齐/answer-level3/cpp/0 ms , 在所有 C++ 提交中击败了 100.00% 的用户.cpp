### 解题思路
貌似解题思路并不难：
1.每一步尽可能存储单词，当超过maxWidth，则存储之前的单词；如果等于，则存储当前单词和之前的单词
2.计算空格数，组成当前的字符串
3.考虑特殊情况，最后一行的处理以及一个单词=maxWidth的情况。

### 代码

```cpp
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res {};
        int tempsize = 0;
        int wordsize = 0;
        int start = 0;
        for(int i=0;i<words.size();i++){
            if(tempsize+words[i].size()+wordsize<maxWidth){
                tempsize += words[i].size();
                wordsize += 1;
            }
            else if (tempsize+words[i].size()+wordsize>maxWidth){
                int spaces = maxWidth - tempsize;
                string tempstring = "";
                if(wordsize==1){
                    tempstring = words[i-1] + string(maxWidth-words[i-1].size(),' ');
                }
                else{
                    int c = spaces/(wordsize-1);
                    int y = spaces%(wordsize-1);
                    
                    for(int j=start;j<i;j++){
                        tempstring += words[j];
                        if(j<i-1){
                            if(j-start<y){
                                tempstring += string(c+1,' ');
                            }
                            else{
                                tempstring += string(c,' ');
                            }
                        }
                    }
                }
                res.push_back(tempstring);
                start = i;
                for(;start<words.size();start++){
                    if(words[start].size()==maxWidth){
                        res.push_back(words[start]);
                    }
                    else{
                        break;
                    }
                }
                if(start>=words.size()) break;
                i = start;
                wordsize = 1;
                tempsize = words[i].size();
            }
            else{
                string tempstring = "";
                for(int j=start;j<=i;j++){
                    tempstring += words[j];
                    if(j<i){
                        tempstring += ' ';
                    }
                }
                res.push_back(tempstring);
                
                start = i+1;
                wordsize = 0;
                tempsize = 0;
                
            }
        }
        if(start<words.size()){
            string tempstring = "";
            for(;start<words.size();start++){
                tempstring += words[start];
                if(start<words.size()-1){
                    tempstring += ' ';
                }
            }
            tempstring += string(maxWidth-tempstring.size(),' ');
            res.push_back(tempstring);
        }
        return res;
    }
};
```