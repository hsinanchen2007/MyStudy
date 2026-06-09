### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> fraction(vector<int>& cont)
    {
      return {countNum(cont, 0), countNum(cont, 1)};
    }

    int countNum(vector<int> & cont, int n)
    {
      if(n < cont.size() - 1)
        return cont[n]*countNum(cont, n+1) + countNum(cont, n+2);
      else
      {
        if(n == cont.size() - 1)
          return cont[cont.size() - 1];
        else
          return 1;
      }
    }
};
```