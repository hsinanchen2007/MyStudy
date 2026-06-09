### 解题思路
 首先先进行整体的翻转，然后再去掉首尾的空格。就能得到一个l和一个r。分别代表，从头是个字母，从尾也是个字母。
 之后从这两点之间的单词再逐个进行翻转。处理完之后，就只需要把里面的多余的空格删减掉就行了。

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        if(s == "")return s;
        reverse(s.begin() , s.end());
        int l = 0 , r = s.length() - 1;
        while(l <= r && s[l] == ' ')l++;
        while(r >= 0 && s[r] == ' ')r--;
        if(l > r)return "";
        for(int i = l ; i <= r ; ){
            while(i <= r && s[i] == ' ')i++;
            int t = i;
            while(i <= r && s[i] != ' ')i++;
            reverse(s.begin() + t , s.begin() + i);
        }
        int t = l;
        for(int i = l ; i <= r ; i++){
            if(s[i] == ' ' && s[i + 1] == ' ')continue;
            s[t++] = s[i];
        }
        return s.substr(l , t - l);
    }
};
```