### 解题思路
将每个单词反转，在进行排序，如果该单词为下一个的前缀，则将该单词删去，记录剩余单词总长以及每个单词后＋1个“#”。

### 代码

```cpp
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        vector<string> reverseword;
        for(string word:words){
            reverse(word.begin(),word.end());
            reverseword.push_back(word);
        }
        sort(reverseword.begin(),reverseword.end());
        int res=reverseword[reverseword.size()-1].size()+1;
        for(int i=0;i<reverseword.size()-1;i++)
            if(reverseword[i+1].find(reverseword[i])!=0)
                res+=reverseword[i].size()+1;
        return res;
    }
};
```