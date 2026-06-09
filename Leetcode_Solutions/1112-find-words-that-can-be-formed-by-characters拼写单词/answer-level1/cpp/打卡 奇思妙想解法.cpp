### 解题思路

执行用时 60 ms, 在所有 C++ 提交中击败了90.72的用户
内存消耗 :17.2 MB, 在所有 C++ 提交中击败了73.91%的用户

将words中的每个单词与chars匹配，匹配过程中使用临时变量temp，每当单词words[i][j]中的一个字母与temp中字母匹配，将temp相应位置置为‘ ’。


### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        if(chars.size() == 0 || words.size() == 0) return 0;
        int res = 0;
        for(int i=0 ;i<words.size();i++){
            //进入每个单词
            if(words[i].size()>chars.size()){//单词长度大于字母长度，不可能学会
                continue;
            }
            else{
                    int count = 0; 
                    string temp = chars;
                    for(int j =0 ;j<words[i].size();j++){
                       
                        int pos = temp.find(words[i][j]);
                        if(pos == string ::npos)
                            break;
                        else{
                                count++;
                                temp[pos] = ' ';

                        
                            }
                    }
                if(count == words[i].size())
                    res+=words[i].size();
            }
           
            
        }
        return res;

    }
};
```