### 解题思路
https://leetcode-cn.com/problems/minimum-window-substring/solution/hua-dong-chuang-kou-suan-fa-tong-yong-si-xiang-by-/

写的非常好，参考题解写出来的
特别是如何满足条件，有些小细节还是很难想到的

### 代码

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
      if(!s.size() || !t.size())  return "";

      map<char, int> map_s;
      map<char, int> map_t;
      //update map_t
      for(auto c : t)
        map_t[c]++;

      int minLenght = INT_MAX;
      int start = 0, match = 0;
      int left = 0, right = 0;
      while(right < s.size()){
        char c = s[right];
        if(map_t.find(c) != map_t.end()){
          map_s[c]++;
          if(map_s[c] == map_t[c])
            match++;
        }
        
        while(match == map_t.size()){
          if(right - left + 1 < minLenght){
            minLenght = right - left + 1;
            start = left;
          }

          char cs = s[left];
          if(map_s.find(cs) != map_s.end()){
            map_s[cs]--;
            if(map_s[cs] < map_t[cs])
              match--;
          }
          left++;
        }
        right++;
      }
    
      return minLenght == INT_MAX ? "" : s.substr(start, minLenght);
    }
};
```