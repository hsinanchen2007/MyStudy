### 解题思路
1.所谓字母异位词，就是要字符长度相等，字符种类相等，字符次数相同，但位置不同的两个字符串。
2.因为只包含小写字母那我们就创建两个数组大小为26.
3.数组去统计字符串中每个字符出现的次数。
4.然后从0-26遍历，去判断两个数组中对应的值是否相等。

### 代码

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        #if 0
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
        #else

        //长度不相等直接返回
        if (s.length() != t.length())
        {
            return false;
        }

        //英文字母26个就够了
        int sTable[26] = {0};
        int tTable[26] = {0};
        
        //统计次数
        for (int i = 0; i < s.length(); i++) 
        {
            sTable[s[i] - 'a']++;
            tTable[t[i] - 'a']++;
        }
        
        for (int i = 0; i < 26; i++) 
        { 
            //26: sTable.length
            if (sTable[i] != tTable[i]) 
            {
                return false;
            }
        }
        return true;

        #endif
    }
};
```