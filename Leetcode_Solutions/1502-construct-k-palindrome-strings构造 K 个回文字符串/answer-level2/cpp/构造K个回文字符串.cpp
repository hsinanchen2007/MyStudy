### 解题思路
写于2020.4.5 0:26
刚打完看了大佬的代码，我真是菜，哈哈哈哈，加油！！！
思路：
- 统计奇数个数的字符的个数，奇数个数的字符数小于k，则可以构造

### 代码

```cpp
int cnt[30];

class Solution {
public:
    bool canConstruct(string s, int k) {
        int len = s.size();
        if(len < k) return 0;
        memset(cnt,0,sizeof cnt);
        for(int i = 0;i<len;i++)
            cnt[s[i] - 'a']++;      
        int sum = 0;
        for(int i = 0;i<26;i++)
            if(cnt[i] & 1) sum++;   //统计奇数个数的字符的个数
        if(sum<=k) return true;     //奇数个数的字符数小于k，则可以构造
        return false;
    }
};
```