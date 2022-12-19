### 解题思路
遍历s中字符,i表示第i个字符：
1、当s[i]为字母时，直接添加到结果字符串中。
2、当s[i]为数字时，识别数字的长度m，并将i到i+m的字符串转换成数字repeatNum，然后采用栈找到后续'['到']'之间的字串，递归的对字串进行解码，然后将解码后的字符串重复repeatNum次，添加到结果字符串中。

### 代码

```cpp
class Solution {
public:
    string decodeString(string s) {
        string result;
        for (int i = 0; i < s.length();) {
            if (isdigit(s[i])) {
                int m = 0;
                while(isdigit(s[i+m])) m++;
                int repeatNum = stoi(s.substr(i,m),0,10);
                i+=m-1;
                stack<char> mystack;
                mystack.push(s[i + 1]);
                int j = i + 2;
                while (!mystack.empty() && j <s.length()) {
                    if (s[j] == ']' && mystack.top() == '[') mystack.pop();
                    if (s[j] == '[') mystack.push(s[j]);
                    j++;
                }
                string decode = decodeString(s.substr(i+2,j-i-3));
                for (int k = 0; k < repeatNum; ++k) {
                    result += decode;
                }
                i=j;
            }
            else {
                result += s[i];
                i++;
            }
        }
        return result;
    }
};
```