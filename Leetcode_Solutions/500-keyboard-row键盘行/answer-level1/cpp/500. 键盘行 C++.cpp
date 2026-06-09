### 解题思路
1.使用hash_map用于记录每个字母的对应在键盘上的行数，若所有字母都在同一行上就将该字符串压入result容器中。

### 代码

```cpp
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        unordered_map<char,int> keyboard = {
            {'q',1},{'w',1},{'e',1},{'r',1},{'t',1},
            {'y',1},{'u',1},{'i',1},{'o',1},{'p',1},
            {'a',2},{'s',2},{'d',2},{'f',2},{'g',2},
            {'h',2},{'j',2},{'k',2},{'l',2},
            {'z',3},{'x',3},{'c',3},{'v',3},{'b',3},
            {'n',3},{'m',3}
        };
        
        unordered_map<char,int>::iterator keyboard_iter;
        string str_temp;
        int p_str;
        bool flag;
        
        for(int i = 0;i < words.size();i++){
            str_temp = words[i];
            
            for(int j = 0;j < str_temp.length();j++){
                keyboard_iter = keyboard.find(tolower(str_temp[j]));
                if(j == 0){
                    p_str = keyboard_iter->second;
                    flag = true;
                }
                else{
                    if(p_str != keyboard_iter->second){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag){
                result.push_back(str_temp);
            }
        }
        return result;
    }
};
```