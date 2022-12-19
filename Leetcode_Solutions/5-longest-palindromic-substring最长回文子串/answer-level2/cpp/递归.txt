### 解题思路
遍历字符串的每一个char作为起点进行递归。

### 代码

```cpp
class Solution {
public:
    int maxsublength = 1, start = 0;  // 记录最长回文串的起始点和最长的长度
    string maxsub, str;
    string longestPalindrome(string s) {
        if(s.length() < 2) return s; 
        str = s;
        for(int i = 0; i < s.length() - 1; i++){
            depth(i-1, i+1);
            if(s[i] == s[i+1]) depth(i-1, i+2); // 两种类型的回文
        }
        for(int i = start; i < start + maxsublength; i++) maxsub += s[i]; //根据最长回文串的起点和长度生成结果
        return maxsub;
    }

    void depth(int s, int e){  //递归
        // cout << s << " " << e << " " << maxsublength << endl;
        if(s < 0 || e >= str.length() || str[s] != str[e]) {
            if(e - s -1 > maxsublength){
                maxsublength = e - s -1;
                start = s + 1;
            }
            return;
        }
        return depth(s-1, e+1);  
    }
};
```