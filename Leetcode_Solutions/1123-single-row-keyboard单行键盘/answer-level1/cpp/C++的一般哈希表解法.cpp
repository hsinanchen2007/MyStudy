### 解题思路
1. 遍历keyboard，将keyboard键位存入哈希表
2. 将word中相邻两个字母的键位差相加，并加上word中第一个字母与keyboard第一个键位的键位差

### 代码

```cpp
class Solution {
public:
    int calculateTime(string keyboard, string word) {
        map<char, int> hashmap;
        int time = 0;
        for(int i = 0; i < 26; i ++) {
            hashmap[keyboard[i]] = i;
        }
        for(int i = 1; i < word.length(); i ++) {
            if(hashmap[word[i]] > hashmap[word[i - 1]]) {
                time += hashmap[word[i]] - hashmap[word[i - 1]];
            }
            else {
                time += hashmap[word[i - 1]] - hashmap[word[i]];
            }
        }
        return time + hashmap[word[0]];
    }
};
```