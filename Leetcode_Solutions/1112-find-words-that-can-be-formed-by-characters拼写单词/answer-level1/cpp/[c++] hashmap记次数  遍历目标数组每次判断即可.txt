### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char,int> m;
        for(char i:chars){
            m[i]+=1;
        }
        map<char,int> tmp;
        int res = 0,f = 1;
        for(string word:words){
            tmp = m;
            f = 1;
            for(char i:word){
        
            if(tmp[i]<=0)
            {
                f = 0;
                break;
            }
            tmp[i]--;

        }
        if(f)
        {
            res+=word.size();
           
        }
        }
        return res;
    }
};
```