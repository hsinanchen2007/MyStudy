### 解题思路
要先将所有单词翻译成摩斯密码，将所有密码放进set容器中，由于set容器的元素不重复性，set的大小就是不同单词翻译的数量。

### 代码

```cpp
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        int num=0;
        set<string> se;
        
        for(int i=0;i<words.size();i++)
        {
            string str="";
            for(int j=0;j<words[i].size();j++)
            {
                str+=s[words[i][j]-'a'];
            }
            se.insert(str);
        }
        
        return se.size();

    }
    
private:
    string s[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
};
```