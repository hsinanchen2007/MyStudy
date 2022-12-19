### 思路:

用两个指针维持一个满足条件的最长窗口从字符串左往右扫描。

### 代码：

时间复杂度：```O(n)```

```c++
class Solution {
public:
    set<char> vis;
    int lengthOfLongestSubstring(string s) {
       vis.clear();
       int i=0,j=0,ans=0;
       for(;j<s.size();){
           while(j<s.size()&&vis.count(s[j])==0){
              vis.insert(s[j]);
              j+=1;
           }
           ans = max(ans, j-i);
           vis.erase(s[i++]);
       }
       return ans;
    }
};
```
