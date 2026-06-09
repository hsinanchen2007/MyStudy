异位词：单词的字母个数要相等，出现的顺序可以相同也可以不同

### 代码

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {//异位词：单词的字母个数要相等，出现的顺序可以相同也可以不同
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
       return s==t;
    }
};
```