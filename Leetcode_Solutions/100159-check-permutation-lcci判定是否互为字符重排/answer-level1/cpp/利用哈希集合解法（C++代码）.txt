### 解题思路
因为没有规定乱序的规则，所以实际上只要第一个字符串中字符出现次数与第二个字符串相同即可。
遍历两个字符串，遍历第一个字符串的时候利用哈希集合存储下每个字符出现的次数。
遍历第二个字符串的时候如果有字符出现次数与第一个字符不一致的就直接返回false。

### 代码

```cpp
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        if(len1 != len2)
            return false;
        unordered_map<char,int> mm;
        for(int i=0;i<len1;i++){//记录s1中所有字符的出现次数
            mm[s1[i]]++;
        }

        for(int i=0;i<len2;i++){
            if(mm.find(s2[i]) == mm.end())
                return false;
            if(mm[s2[i]]-- == 0)
                return false;
        }
        return true;
    }
};
```