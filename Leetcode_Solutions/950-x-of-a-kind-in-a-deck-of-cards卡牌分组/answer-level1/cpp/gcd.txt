### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if(deck.size() <= 1) return false;
        vector<int> hash(10005);
        int m = 0;
        for(int i=0; i<deck.size(); ++i){
            hash[deck[i]]++;
            
        }
        
        for(int i=0; i<hash.size(); ++i){
            if(hash[i] != 0){
                m = std::gcd(m, hash[i]);
                if(m == 1) return false;
            }
        }

        return m >= 2;
    }
};
```