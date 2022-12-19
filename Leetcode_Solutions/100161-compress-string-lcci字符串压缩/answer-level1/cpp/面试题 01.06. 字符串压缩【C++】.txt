### 解题思路

由于传入的字符串长度可能为0，所以这种特殊情况应该直接返回原字符串（无法对其进行压缩）。

由于题目要求是压缩字符串，但是如果“压缩”后的字符串长度没有变短的话，就应该返回原字符串，所以不应该在原字符串上进行修改，所以我定义了一个新的字符串 `cpStr` 存储压缩后的字符串。

思路很简单，遍历原字符串，取出一个字符串将其追加到 `cpStr` 末尾，然后对这个字符进行计数，直到遇到下一个不同的字符计数结束，将计数追加到 `cpStr` 末尾，并重新将计数 `count` 修改为1，即当前新遇到的字符个数为1，然后再对新遇到的字符计数，循环前述步骤，直到遍历完原字符串。最后跳出循环还应该将最后一个字符的计数值追加到 `cpStr` 末尾，因为循环内部最后一个字符不会再遇到新的字符，所以虽然对其进行了计数但是并没有将它的个数追加到压缩的字符串的末尾。

最后返回结果用一个条件表达式，判断 `cpStr` 的长度是否小于原字符串长度，当且仅当小于原字符串长度的时候才将压缩后的 `cpStr` 返回，否则应返回原字符串。

### 代码

```cpp
class Solution {
public:
    string compressString(string str) {
        int length = str.length();//获取字符串长度
        if (length == 0)
            return str;
        string cpStr;//压缩后的字符串
        char c = str[0];
        cpStr += c;
        int count = 0;//计数某一个字符
        for (int i = 0; i < length; i++) {
            if (str[i] == c) {
                count++;
            }
            else {
                if (count > 0) {
                    cpStr += to_string(count);
                    c = str[i];
                    cpStr += c;
                    count = 1;
               }
            }
        }
        cpStr += to_string(count);//追加最后一个字符的个数
        return cpStr.length() < length ? cpStr : str;
    }
};
```