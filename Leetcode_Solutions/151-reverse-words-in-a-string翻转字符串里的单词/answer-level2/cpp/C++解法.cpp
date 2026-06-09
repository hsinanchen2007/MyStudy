### 解题思路
此题用到的思路较简单，设置两个循环，外部循环遍历字符串，内部循环找单词。从最后开始向前遍历，当有非空格的字符，则从该位置开始向前遍历到下一个空格字符，这就为一个单词，加入到result中，并且在后面加上空格。这样可以保证每个单词后面有且仅有一个空格，最后只需要把最后一个空格删掉即可。
对于空字符串和只有空格的字符串另行讨论。

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        if(s == "")
            return "";
        string result;
        int start = 1;
        for(int i=s.size()-1; i>=0; ){
            if(s[i]!=' '){
                int j = i;
                for(; j>=0&&s[j]!=' '; j--);
                for(int k=j+1; k<=i; k++)
                    result += s[k];
                i = j-1;
                result += " ";
            }
            else
                i--;
        }
        if(result.size()>0)
            result.pop_back();
        return result;
    }
};
```
### 执行结果
![image.png](https://pic.leetcode-cn.com/bd6924cc7fa750e4bd24291ed4a8fa9d6d8b6589be6cc11cd0b6d7ddb7401437-image.png)
