嗯， `cstdio` 库(捂脸)
```c++
class Solution {
 public:
  string toHexspeak(string num) {
    long long val = atoll(num.c_str());
    char str[100];
    sprintf(str, "%llX", val);
    for(int i = 0, sz = strlen(str); i < sz; ++i)
      if(str[i] == '1')
        str[i] = 'I';
      else if(str[i] == '0')
        str[i] = 'O';
      else if(str[i] > '0' && str[i] <= '9') {
        string ans("ERROR");
        return ans;
      }
    string ans = string(str);
    return ans;
  }
};
```