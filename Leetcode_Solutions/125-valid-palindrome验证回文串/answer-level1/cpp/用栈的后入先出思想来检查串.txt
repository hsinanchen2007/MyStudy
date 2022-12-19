1. 首先输入s为空时，返回true；
2. 对于输入串先处理非字母和数字符号，保存在临时string变量tmp中，若tmp为单个字符，返回true；
3. 将tmp一半的字符压入栈，无论字符个数奇偶，i都是对lengh/2向下取整；
4. 检查tmp的后一半元素，字符个数为偶数i开始位置为对lengh/2向下取整，否则对其向上取整，开始遍历剩下字符，若与栈顶元素相同，则出栈；
5. 最后，若栈为空，返回true，否则返回false。
6. 
```
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() == 0) return true;
        
        string tmp;
        // 去除非字母和数字字符
        for(int i = 0; i < s.length(); i++) {
            // 判断是否为字母和数字
            if(isalnum(s[i])) {
                // 判断是否是大写字母
                if(s[i] >= 'A' && s[i] <= 'Z') {
                    tmp.insert(tmp.end(), s[i] + 32);
                }
                else {
                    tmp.insert(tmp.end(), s[i]);
                }
            }
        }
        if(tmp.length() == 1) return true;
        
        // 将tmp一半的字符存入栈
        stack<char> tmpStack;
        for(int i = 0; i < floor(tmp.length() / 2); i++) {
            tmpStack.push(tmp[i]);
        }
        // 检查tmp后一半的字符
        for(int i = (tmp.length() % 2 ? floor(tmp.length() / 2) : ceil(tmp.length() / 2)); i < tmp.length(); i++) {
            if(tmp[i] == tmpStack.top()) {
                    tmpStack.pop();
            }
        }

        return tmpStack.empty()?true:false;
    }
};
```
![捕获.JPG](https://pic.leetcode-cn.com/8e433db4a99c34b223ee48f6767ac92ed1e83343343e904c7ae2ce6d96faf9e4-%E6%8D%95%E8%8E%B7.JPG)

