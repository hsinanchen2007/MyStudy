### 解题思路

输入: "the sky is blue"
输出: "blue is sky the"

####  方法一：
**0.按空格分割成单词列表；
1.末位单词+空格 
2.最后一个单词末位不加空格**

```python3 []
class Solution:
    def reverseWords(self, s: str) -> str:
        """按空格分割成单词列表，1.末位单词+空格 2.最后一个单词末位不加空格"""
        if s == [] : return ""
        ls = s.split()  # ['the', 'sky', 'is', 'blue']
        if ls == []: return ""
        res = ""
        for i in range(len(ls)-1): # 少一个，处理末位不加空格
            res += ls[len(ls) - 1 - i] + " "  # 最后一个单词 + 空格  
        res += ls[0] # 末位不加空格
        return res
```
```python3 []
class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(s.split()[::-1])
```

####  方法二：
**1.反转每个单词：eht yks si eulb
2.反转整个字符：blue is sky the**

### 代码



```cpp []
class Solution {
public:
    string reverseWords(string s) {
        int k = 0;
        for (int i = 0; i < s.size(); ++ i){
            while (i < s.size() && s[i] == ' ') ++i;  //找到第一个非空格字符
            if (i == s.size()) break;
            int j = i;
            while (j < s.size() && s[j] != ' ') ++j;    //遍历1个非空单词
            reverse(s.begin() + i, s.begin() + j);      //反转1个单词
            if (k) s[k++] = ' ';
            while (i < j) s[k++] = s[i++];      //反转后的1个单词赋给s[k]
        }
        s.erase(s.begin() + k, s.end());   //删除 k后面空格
        reverse(s.begin(), s.end());
        return s;
    }
};
```

