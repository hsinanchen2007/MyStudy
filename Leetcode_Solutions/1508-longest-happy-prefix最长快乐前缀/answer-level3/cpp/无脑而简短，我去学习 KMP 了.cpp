![image.png](https://pic.leetcode-cn.com/3c66b7554a5ca0e8c91eb666cd6d6fd222197ffb5fc9aa9dcd3d924d83187729-image.png)

```c++
class Solution {
public:
    string longestPrefix(string s) {
      int len = s.size();
      while (--len > 0 && !equal(s.begin(), s.begin() + len, s.end() - len));
      s.resize(len);
      return std::move(s);
    }
}
```