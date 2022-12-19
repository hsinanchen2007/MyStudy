### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string toGoatLatin(string S) {
        stringstream ss(S);
        string res;
        int count = 0;
        string word;
        while(ss >> word){
            count++;
            if(word[0]=='a' || word[0]=='e' || word[0]=='i' || word[0]=='o' || word[0]=='u' || word[0]=='A' || word[0]=='E' || word[0]=='I' || word[0]=='O' || word[0]=='U')
                word += "ma";
            else
                word = word.substr(1,word.size()-1) + word[0] + "ma";
            for(int i = 0;i<count;i++)
                word += 'a';
            res += word + ' ';
        }
        return res.substr(0,res.size()-1);
    }
};
```