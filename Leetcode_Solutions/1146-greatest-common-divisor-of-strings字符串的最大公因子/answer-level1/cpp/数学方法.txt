### 解题思路
这里参考了大神们的数学方法真的是超级简单，大家可以看看

### 代码

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
          
          if(str1+str2!=str2+str1)
          {
              return "";
          }
          return str1.substr(0, __gcd((int)str1.length(), (int)str2.length()));
    }
};
```