这个题很简单，算是hashmap的入门题
### 代码

```cpp
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char,int>hash_map;
        int odd=0;
        for(char i:s)hash_map[i]++;
        for(auto i:hash_map){
            if(i.second%2==1)odd++;
            if(odd>=2)return 0;
        }
        return 1;
    }
};
```
