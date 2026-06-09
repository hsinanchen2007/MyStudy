### 解题思路
相对比较简单，注意一下最后一下进位的处理


### 代码

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
      if(a.size() == 0 && b.size() == 0)  return "";
      if(a.size() * b.size() == 0)
        return a.size() == 0 ? b : a;

      string res;
      int flag = 0;
      for(int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; i--, j--){
        int x = i >= 0 ? a[i] - '0': 0;
        int y = j >= 0 ? b[j] - '0': 0;

        int sum = (x + y + flag) % 2;
        flag = (x + y + flag) / 2;
        res.insert(0, 1, sum + '0');
      }
      
      if(flag)
        res.insert(0, 1, '1');

      return res;
    }
};
```