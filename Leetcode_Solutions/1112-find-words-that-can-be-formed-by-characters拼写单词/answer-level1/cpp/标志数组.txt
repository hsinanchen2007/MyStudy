### 解题思路

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> book(200,0);
        int res=0;
        for(int i=0;i<chars.size();i++){
            book[chars[i]]++;
        }
        for(int i=0;i<words.size();i++){
            int j=0;
            for(j=0;j<words[i].size();j++){
                if(book[words[i][j]]>0) book[words[i][j]]--;
                else break;
            }
            if(j==words[i].size()) res+=j;
            for(j--;j>=0;j--) book[words[i][j]]++;
        }
        return res;
    }
};
```