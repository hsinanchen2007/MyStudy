### 解题思路
题解区对substr函数是不是有些误解。s.substr(pos, n)，作用是返回一个string，包含s中从pos开始的n个字符的拷贝（pos的默认值是0，n的默认值是s.size() - pos，即不加参数会默认拷贝整个s），所以第二个参数应该是s.size()-n或者s.length()-n。

### 代码

```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        return s.substr(n,s.size()-n)+s.substr(0,n);
    }
};
```