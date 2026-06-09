使用简易HashMap统计每个字符数量，由于偶数一定对称，大于2的奇数的偶数部分也可以用来对称，所以统计奇数个数。
在结果含有奇数的情况下结果+1（因为一个奇数可以为对称中心）。

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        if(s.empty()) return 0;
        int map_letter[100];
        memset(map_letter, 0, sizeof(map_letter));
        for(auto i: s){
            map_letter[i-'A']++;
        }
        int count=0;
        for(int i=0; i<100; i++){
            if(map_letter[i]%2==1) count++;
        }
        if(count>1) return (s.size()-count+1);
        return s.size();
    }
};
```