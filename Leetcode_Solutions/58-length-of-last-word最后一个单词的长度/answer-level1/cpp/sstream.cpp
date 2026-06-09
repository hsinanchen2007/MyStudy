### 解题思路
使用sstream

### 代码

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
      stringstream ss;
      string temp;
      ss <<s;
      while (ss >>temp);
      return temp.size();

    }
};
```