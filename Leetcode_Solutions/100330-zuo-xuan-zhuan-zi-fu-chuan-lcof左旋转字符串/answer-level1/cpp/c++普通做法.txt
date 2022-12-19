### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string s2=s.substr(0,n);//截取s从0往后n个字符赋予s2
        s.erase(0,n);//s删除从0开始n个字符
        s.append(s2);//将s2追加再s末尾
        return s;
    }
};
```