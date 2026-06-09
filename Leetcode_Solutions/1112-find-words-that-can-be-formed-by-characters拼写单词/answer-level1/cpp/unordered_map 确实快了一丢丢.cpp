### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
       
        std::unordered_map<char,int> m;
        int ans=0;
        for(char c:chars)  ++m[c];
        
        for(string word:words){
            std::unordered_map<char,int> wo;
            bool flag=true;
            for(char x:word){
                ++wo[x];
            }
            for(char cc:word){
                if(wo[cc]>m[cc]) flag=false;
            }
            
            if(flag) ans+=word.size();
        }
        
        return ans;
        

    }
};
```