### 解题思路
这种需要查找过去有没有出现的题考虑hash map，刚开始我想到的是unordered_map，固然可以解题，但是感觉有点大材小用。题目说了输入是26个小写字母，直接定义一个26size的数组即可。

第一个循环记录每个字母出现的次数，第二次从头到尾找到第一个出现次数是1的字母，返回索引。

### 代码

```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        int size = 26;
        int map[size]= {0};

        for(char c : s) {
            map[c - 'a']++;
        }

        int i = 0;
        for(char c : s) {
            if(map[c-'a'] == 1) return i;
            i++;
        }

        return -1;
    }
};
```