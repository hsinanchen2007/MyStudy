### 构造哈希

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> mp(58);      //大小写字母差值26，26+32=58
        int len = 0;
        for(char c : s)            mp[c-'A']++;           //统计对应字母出现次数
        for(int  n : mp)            len += n/2*2;          //每出现两次即可在回文串中出现两次
        return len<s.size() ? len+1 : len;
    }
};
```

### 利用奇偶性
字母的出现次数只能为奇数或者偶数，所有字母减去奇数次字母，即为可在回文串中出现的偶数次字母，如果存在奇数次字母，可做回文串的中心，结果+1
### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        int n=0;               //代表奇数个数
        for(char c = 'A';c <= 'z';c++)
        n += count(s.begin(),s.end(),c) & 1;          //统计出现奇数次字母的总出现次数     

        return s.size()-n + (n > 0);                    //所有字母减去奇数次字母，即为偶数次的字母
                                                        //如果存在奇数次字母，可做回文串的中心，结果+1 
    }
};
```
