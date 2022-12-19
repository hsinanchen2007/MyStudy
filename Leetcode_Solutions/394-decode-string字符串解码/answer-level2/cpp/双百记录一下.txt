### 解题思路
![image.png](https://pic.leetcode-cn.com/32fe8b03cacfda73f56463c9a8b46630d90d6dc24e78187e2375a97371635d92-image.png)
舔着脸发一个双百的截图。
思路是用递归
1、遇到 '['就调用函数解析、处理、合成这个括号内的内容
2、遇到']'就退出函数调用
3、遇到字母就增加
4、调用函数之后就结合内层的字符串以及之前解析出来的数字，复制
5、***遇到数字就十进制计算***
6、***复制流程处理完成之后，数字要清零***

### 代码

```cpp
class Solution {
private:
    unsigned int strLen;    
    void getInnerString(std::string &oriStr, std::string &innerString, int &pos) {
        //
        int loop = 0;
        char ch;
        std::string preStr;
        std::string inString;
        unsigned int num = 0;
        unsigned int loopIn = 0;
        for (loop = pos + 1; loop < strLen; loop++) {
            ch = oriStr.at(loop);
            if (ch == '[') {
                inString.clear();
                getInnerString(oriStr, inString, loop);
                for (loopIn = 0; loopIn < num; loopIn++) {
                    innerString.append(inString);
                }
                num = 0;
            } else if (ch == ']') {
                pos = loop;
                return;
            } else if (ch == '0' || (ch >= '1' && ch <= '9')) {
                num = num * 10 + (unsigned int)(ch - '0');
            } else {
                innerString.push_back(ch);
            }
        }
    }
public:
    string decodeString(string s) {
        int pos = -1;
        std::string getStr;
        strLen = s.size();
        if (strLen == 0) {
            return getStr;
        }
        getInnerString(s, getStr, pos);
        return getStr;
    }
};
```