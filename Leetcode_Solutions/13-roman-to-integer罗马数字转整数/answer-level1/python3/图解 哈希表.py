### 解题思路
通过观察我们发现，**只有在遇到特殊情况时，两个字符中左边的字符小于右边的字符，且等于右边的字符代表的数减左边字符代表的数**。 比如 `CM` 等于 $1000 - 100$，`XC` 等于 $100 - 10$...


因此，我们将 `字符：数值` 存在 `Roman2Int` 的哈希表中。然后从左到右遍历每个字符，如果 `s[i] < s[i+1]`，就将结果减去 `s[i]` 代表的数字；否则，将结果加上 `s[i]` 代表的数字。

<![幻灯片1.JPG](https://pic.leetcode-cn.com/6d1c736b8c8138bc4dc3c5240b018cf4c518f8aa4a81707a37e919ebc54dbf4a-%E5%B9%BB%E7%81%AF%E7%89%871.JPG),![幻灯片2.JPG](https://pic.leetcode-cn.com/44a8b00728519e64145b2b7a7eb6e622a156abb9d42f8055ae03b1f76db0f303-%E5%B9%BB%E7%81%AF%E7%89%872.JPG),![幻灯片3.JPG](https://pic.leetcode-cn.com/bdfaf6cdb17941f4d93ab6392d20cd36194c29f476e73e4a0c40c248ef55c3fe-%E5%B9%BB%E7%81%AF%E7%89%873.JPG),![幻灯片4.JPG](https://pic.leetcode-cn.com/31c752185e8217e8195dafa7621019b848fcf286e26f0032c524d59eb5d66c5f-%E5%B9%BB%E7%81%AF%E7%89%874.JPG),![幻灯片5.JPG](https://pic.leetcode-cn.com/0636c370f26b6f042d7da65863b547977a13a1d9933b519b2f630e927f108b4f-%E5%B9%BB%E7%81%AF%E7%89%875.JPG),![幻灯片6.JPG](https://pic.leetcode-cn.com/0e023ddb7a8caaef1394bcb802edb0cd39cf1c5d1386290c9f19d6d4160bee32-%E5%B9%BB%E7%81%AF%E7%89%876.JPG),![幻灯片7.JPG](https://pic.leetcode-cn.com/a0eafdfa604dba238033a7f1d647c4b90a4e9fc38b914f9f0770a7c8745e2183-%E5%B9%BB%E7%81%AF%E7%89%877.JPG),![幻灯片8.JPG](https://pic.leetcode-cn.com/4b2727cb33143d89e32d734d8b582468e16cb79b8c47137925d65a29513acc02-%E5%B9%BB%E7%81%AF%E7%89%878.JPG)>


### 代码
感谢 [@dreamck](/u/dreamck/) 对代码可读性作出的修改建议！
```python []
class Solution:
    def romanToInt(self, s: str) -> int:
        Roman2Int = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        Int = 0

        for index in range(len(s) - 1):
            if Roman2Int[s[index]] < Roman2Int[s[index + 1]]:
                Int -= Roman2Int[s[index]]
            else:
                Int += Roman2Int[s[index]]

        return Int + Roman2Int[s[-1]]

```

```c++ []
class Solution {
public:
    int romanToInt(string s) {
        int result=0;
        map<char,int> luomab;//初始化哈希表
        luomab.insert(map<char,int>::value_type('I',1));
        luomab.insert(map<char,int>::value_type('V',5));
        luomab.insert(map<char,int>::value_type('X',10));
        luomab.insert(map<char,int>::value_type('L',50));
        luomab.insert(map<char,int>::value_type('C',100));
        luomab.insert(map<char,int>::value_type('D',500));
        luomab.insert(map<char,int>::value_type('M',1000));
        for(int i=0;i<s.length();i++)
        {
            if(luomab[s[i]] < luomab[s[i+1]])
                result -= luomab[s[i]];
            else
            {
                result += luomab[s[i]];
            }
        }
        return result;
    }
};
```
### 复杂度分析
- 时间复杂度：$O(N)$。遍历了一遍数组。
- 空间复杂度：$O(1)$。使用了 `Int`。

如有问题欢迎指正~欢迎补充其他代码