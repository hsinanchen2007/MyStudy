### 解题思路
1. string的erase方法
2. basic_string & erase(size_type pos=0, size_type n=npos); //删除从pos开始的n个字符，2个参数都是可选的，如果只有一个参数，则删除pos后的所有字符，如果没有参数，则删除全部字符；返回值是修改后的string对象引用
3. iterator erase(const_iterator position) // 删除迭代器位置处的单个字符, 并返回下个元素的迭代器
4. iterator erase(const_iterator first, const_iterator last) // 删除迭代器[first, last)区间的所有字符,返回一个指向被删除的最后一个元素的下一个字符的迭代器.
5. [string函数网址](https://www.renfei.org/blog/introduction-to-cpp-string.html)

### 代码

```cpp
class Solution {
public:
    void trim(string& s) {
        if (s.empty()) {
            return;
        }
        s.erase(0, s.find_first_not_of(" "));  // 删除字符串前面的空格
        s.erase(s.find_last_not_of(" ") + 1);  // 删除字符串后面的空格
        // 删除中间多余的空格
        bool flag = false;
        auto it = s.begin();
        while (it != s.end()) {
            if (*it == ' ') {
                if (flag) {
                    it = s.erase(it);
                } else {
                    flag = true;
                    it++;
                }
            } else {
                it++;
                if (flag) {
                    flag = false;
                }
            }
        }
    }

    void reverse(string& s, int start, int end) {
        while (start < end) {
            char c = s[start];
            s[start] = s[end];
            s[end] = c;

            start++;
            end--;
        }
    }

    string reverseWords(string s) {
        trim(s);
        int start = 0;
        int end = 0;
        int index = s.find(" ", start);
        while (index != string::npos) {
            end = index - 1;
            reverse(s, start, end);
            start = index + 1;

            index = s.find(" ", start);
        }
        reverse(s, start, s.size() - 1);

        reverse(s, 0, s.size() - 1);

        return s;
    }
};
```