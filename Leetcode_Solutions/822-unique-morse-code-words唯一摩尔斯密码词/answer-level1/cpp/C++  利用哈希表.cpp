### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_map<string,int> hash;
        for(string w : words){
            string temp;
            for(char c : w)
                temp += morse[c-'a'];
            hash[temp]++;
        }
        return hash.size();
    }
};
```