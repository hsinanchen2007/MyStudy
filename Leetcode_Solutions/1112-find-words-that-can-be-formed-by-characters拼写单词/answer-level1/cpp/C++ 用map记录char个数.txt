### 解题思路
用map记录char个数

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char,int> board,use;
        for(int i=0;i<chars.length();i++){
            board[chars[i]]++;
        }
        int res = 0;
        for(int i=0;i<words.size();i++){
            use=board;
            bool f=1;
            for(int j=0;j<words[i].length();j++){
                if(use.find(words[i][j])==use.end()||use[words[i][j]]==0){
                    f=0;
                    break;
                }
                
                use[words[i][j]]--;
            }
            if(f)res+=words[i].length();
        }
        return res;
    }
};
```