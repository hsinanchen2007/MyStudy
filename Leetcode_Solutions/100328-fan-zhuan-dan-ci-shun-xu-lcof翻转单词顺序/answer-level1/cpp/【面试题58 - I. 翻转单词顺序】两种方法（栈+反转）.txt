## 思路一：栈
通过空格分割单词并放入栈中，然后依次从栈中取出。

### 代码
时间复杂度：O(n)
空间复杂度：O(n)
```cpp
class Solution {
public:
    string reverseWords(string s) {
        istringstream is(s);
        stack<string> st;
        string str, res;
        while (is >> str) {
            st.push(str);            
        }
        while (!st.empty()) {
            if (!res.empty()) {
                res += " ";
            }
            res += st.top();
            st.pop();
        }
        return res;
    }
};
```

### 另一种写法
将字符串放入vector中，然后从后向前遍历。
```c++
class Solution {
public:
    string reverseWords(string s) {
        string res, str;        
        istringstream is(s);
        vector<string> svec;
        while (is >> str) {
            svec.push_back(str);
        }
        for (int i = svec.size() - 1; i >= 0; --i) {
            if (!res.empty()) res += ' ';
            res += svec[i];
        }
        return res;
    }
};
```


## 思路二：reverse
从前向后，先对每个单词反转，再对整个句子反转。

### 代码
时间复杂度：O(n)
空间复杂度：O(1)
```c++
class Solution {
public:
    string reverseWords(string s) {
        string res;
        for (int i = 0; i < s.size(); ++i) {
            string tmp;
            while (i < s.size() && s[i] == ' ') ++i;
            while (i < s.size() && s[i] != ' ') {
                tmp += s[i];
                ++i;
            }
            if (!tmp.empty()) {
                reverse(tmp.begin(), tmp.end()); //对单词反转
                if (!res.empty()) res += ' ';
                res += tmp;
            }            
        }
        reverse(res.begin(), res.end());//对整个句子反转
        return res;
    }
};
```
