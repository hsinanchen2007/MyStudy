### 解题思路
需要注意res += 这样的写法比较节约内存

### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
      if(S.size() == 0) return S;

      string res = S.substr(0, 1);
      long cnt = 1;
      for(long i = 1; i < S.size(); i++){
        if(S[i] != S[i - 1]){
          string tmp = to_string(cnt);
          res += tmp;
          res += S[i];
          cnt = 1;
        }else{
          cnt++;
        }
      }
      string tmp = to_string(cnt);
      res += tmp;

      return res.size() >= S.size() ? S : res;
    }
};
```