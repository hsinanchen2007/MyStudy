### 解题思路
有点类似于数学题

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
      if(s.size() == 0) return 0;
      map<char, int> maps;
      for(int i = 0; i < s.size(); i++){
        maps[s[i]]++;
      }

      int sum = 0;
      bool flag = false;
      for(auto p : maps){
        //先把所有的偶数都加上，如果存在基数，最后在加一个1，以那个字母对称
        sum += p.second / 2 * 2;

        if(!flag && p.second % 2 == 1) {
          flag = true;
        }
      }
      return flag == true ? sum + 1 : sum;
    }
};
```