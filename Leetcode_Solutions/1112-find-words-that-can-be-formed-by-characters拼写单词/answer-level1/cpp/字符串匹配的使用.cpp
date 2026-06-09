### 解题思路
1、对每一个words里的单词含有的字符在chars里查找；
2、查找到一个字符，抹去一个字符；
3、遍历一个单词之后，如果找到的字符数==单词长度，就把这个长度加到结果中；
4、循环至结束。

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        if (chars.size()==0) return 0;
        string t;
        int re=0;
        int num;
        for (int i=0; i<words.size(); i++){
            num=0;
            t=chars;
            for (int j=0; j<words[i].size(); j++){//对这个单词遍历
                if (t.find(words[i][j]) != string::npos){//如果找到了
                    num++;
                    t.erase(t.find(words[i][j]), 1);//抹去查找到的字符
                }
            }
            if (words[i].size() == num) re+=num;//二者大小相同，说明掌握里，加入结果
        }
        return re;
    }
};
```