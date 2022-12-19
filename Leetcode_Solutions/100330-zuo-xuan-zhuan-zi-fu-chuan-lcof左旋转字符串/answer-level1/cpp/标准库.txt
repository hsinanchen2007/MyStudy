### 解题思路
标准库函数, string的重载拷贝构造函数：拷贝给定string当中的前n个元素，然后执行append成员函数在string尾元素后面添加新元素，使用一对迭代器对指明范围，本题中是一个string的前n个元素。

### 代码

```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        if (1 <= n && n < s.size() && n <= 10000) {
            string temp(s,n);
            temp.append(s.begin(), s.begin() + n);
            return temp;
        }
        else
            return string("Arguments Error!");
    }
};
```