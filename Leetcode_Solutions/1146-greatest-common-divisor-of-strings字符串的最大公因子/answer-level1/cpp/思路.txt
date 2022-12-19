### 解题思路
其实能把写的很好看，也不错了
数学的方法 需要一定的时间

### 代码

```cpp
class Solution {
    bool check(string x, string y){
      int len = y.size() / x.size();
      string ans;
      for(int i = 0; i < len; i++){
        ans = ans + x;
      }
      return ans == y;
    }

public:
    string gcdOfStrings(string str1, string str2) {
      if(str1.empty() || str2.empty() || str1[0] != str2[0])
        return "";

      for(int i = min(str1.size(), str2.size()); i > 0; i--){
        if(str1.size() % i || str2.size() % i)
          continue;
        string tmp = str1.substr(0, i);
        if(check(tmp, str1) && check(tmp, str2))
          return tmp;
      }

      return "";
    }
};
```